#include "Robot.h"

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
}

void Robot::TeleopPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems()
{

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
