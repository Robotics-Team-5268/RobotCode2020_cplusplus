#include "Robot.h"

#include "RobotConfig.h"
#include "subsystems/Drive.h"
#include "RobotContainer.h"
#include "Vision.hpp"

#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Relay.h>

std::unique_ptr<Autonomous> Robot::autonomousCommand;
AutonomousChooser Robot::AutoChooser;

static std::unique_ptr<frc::Relay> cameraRelay;
static std::unique_ptr<Vision> vision;

void Robot::RobotInit() {
    RobotContainer::init();
    const int CameraRelayChannel = 3;
    cameraRelay.reset( new frc::Relay( CameraRelayChannel ) );
    cameraRelay->Set( frc::Relay::kForward );

    vision.reset( new Vision() );

	#if( GYRO_SUPPORT )
		RobotContainer::drive->calibrateGyro();
	#endif
	RobotContainer::drive->safetyOff();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::AutonomousInit() {
	autonomousCommand.reset(new Autonomous(AutoChooser.AutonomousSelection()));
	autonomousCommand->Schedule();
}

void Robot::AutonomousPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
    AddSmartDashboardItems();
}

void Robot::TeleopInit() {
	//frc::SmartDashboard::PutNumber("breakpoint", 200);
	#if( GYRO_SUPPORT )
		RobotContainer::drive->resetGyro();
	#endif
	RobotContainer::drive->setMotors(0.0, 0.0);
}

void Robot::TeleopPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
    #if( PNEUMATICS_SUPPORT )
        frc::SmartDashboard::PutValue("Solenoid Value", RobotContainer::pneumatics->getValue())
    #endif
    #if( GYRO_SUPPORT )
        frc::SmartDashboard::PutNumber("Gyro Angle", RobotContainer::drive->getGyroAngle());
        frc::SmartDashboard::PutNumber("Gyro Rate", RobotContainer::drive->getGyroRate());
    #endif
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
