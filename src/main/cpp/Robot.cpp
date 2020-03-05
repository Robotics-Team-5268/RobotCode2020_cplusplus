#include "Robot.h"

#include "RobotConfig.h"
#include "subsystems/Drive.h"
#include "Vision.hpp"

#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

static std::unique_ptr<Vision> vision;

Robot::Robot()
    : mAutonomousCommand( nullptr )
{

}

void Robot::RobotInit() {
    vision.reset( new Vision() );
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::AutonomousInit()
{
    mAutonomousCommand = mRobotContainer.GetAutonomousCommand();
    if( mAutonomousCommand != nullptr )
    {
        mAutonomousCommand->Schedule();
    }
}

void Robot::AutonomousPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
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
}

void Robot::TeleopPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
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
