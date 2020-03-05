#include "Robot.h"

#include "RobotConfig.h"
#include "subsystems/Drive.h"
#include "RobotContainer.h"
#include "Vision.hpp"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

static std::unique_ptr<Vision> vision;

Robot::Robot()
    : mAutonomousCommand( nullptr )
{

}

void Robot::RobotInit() {
    vision.reset( new Vision() );

	#if( GYRO_SUPPORT )
		RobotContainer::drive->calibrateGyro();
	#endif
	RobotContainer::drive->safetyOff();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit()
{
    mAutonomousCommand = mRobotContainer.GetAutonomousCommand();
    if( mAutonomousCommand != nullptr )
    {
        mAutonomousCommand->Start();
    }
}

void Robot::AutonomousPeriodic() { 
    frc::Scheduler::GetInstance()->Run();
    AddSmartDashboardItems();
}

void Robot::TeleopInit()
{
	// Protect against a NULL autonomous command in case testing bypasses the auto phase
    if (mAutonomousCommand != nullptr)
    {
        mAutonomousCommand->Cancel();
        mAutonomousCommand = nullptr;
    }

	//frc::SmartDashboard::PutNumber("breakpoint", 200);
	#if( GYRO_SUPPORT )
		RobotContainer::drive->resetGyro();
	#endif
	RobotContainer::drive->setMotors(0.0, 0.0);
}

void Robot::TeleopPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
    #if( GYRO_SUPPORT )
        frc::SmartDashboard::PutNumber("Gyro Angle", RobotContainer::drive->getGyroAngle());
        frc::SmartDashboard::PutNumber("Gyro Rate", RobotContainer::drive->getGyroRate());
    #endif
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
