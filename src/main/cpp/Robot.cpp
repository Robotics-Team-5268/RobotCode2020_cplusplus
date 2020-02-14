#include "Robot.h"

#include "RobotConfig.h"
#include "commands/DriveStraightAutonomous.h"
#include "subsystems/Drive.h"
#include "CommandBase.h"
#include "Vision.hpp"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

std::unique_ptr<DriveStraightAutonomous> Robot::autonomousCommand;
AutonomousChooser Robot::AutoChooser;

static std::unique_ptr<Vision> vision;

void Robot::RobotInit() {
    CommandBase::init();

    vision.reset( new Vision() );

	#if( GYRO_SUPPORT )
		CommandBase::drive->calibrateGyro();
	#endif
	CommandBase::drive->safetyOff();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit()
{
	autonomousCommand.reset( new DriveStraightAutonomous() );
	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() { 
    frc::Scheduler::GetInstance()->Run();
    AddSmartDashboardItems();
}

void Robot::TeleopInit() {
	//frc::SmartDashboard::PutNumber("breakpoint", 200);
	#if( GYRO_SUPPORT )
		CommandBase::drive->resetGyro();
	#endif
	CommandBase::drive->setMotors(0.0, 0.0);
}

void Robot::TeleopPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
    frc::SmartDashboard::PutValue("Solenoid Value", CommandBase::pneumatics->getValue())
    #if( GYRO_SUPPORT )
        frc::SmartDashboard::PutNumber("Gyro Angle", CommandBase::drive->getGyroAngle());
        frc::SmartDashboard::PutNumber("Gyro Rate", CommandBase::drive->getGyroRate());
    #endif
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
