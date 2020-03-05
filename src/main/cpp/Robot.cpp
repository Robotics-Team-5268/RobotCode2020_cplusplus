#include "Robot.h"

#include "RobotConfig.h"
#include "subsystems/Drive.h"
#include "RobotContainer.h"
#include "Vision.hpp"

#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Relay.h>

static std::unique_ptr<frc::Relay> cameraRelay;
static std::unique_ptr<Vision> vision;

Robot::Robot()
    : mAutonomousCommand( nullptr )
{

}


void Robot::RobotInit() {
    const int CameraRelayChannel = 3;
    cameraRelay.reset( new frc::Relay( CameraRelayChannel ) );
    cameraRelay->Set( frc::Relay::kForward );

    vision.reset( new Vision() );

	#if( GYRO_SUPPORT )
		RobotContainer::drive->calibrateGyro();
	#endif
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::AutonomousInit()
{
    mAutonomousCommand = mRobotContainer.GetAutonomousCommand();

    if (mAutonomousCommand != nullptr)
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
    if (mAutonomousCommand != nullptr)
    {
        mAutonomousCommand->Cancel();
        mAutonomousCommand = nullptr;
    }

	#if( GYRO_SUPPORT )
        // TODO: Implement if necessary
		// RobotContainer::drive->resetGyro();
	#endif
}

void Robot::TeleopPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
