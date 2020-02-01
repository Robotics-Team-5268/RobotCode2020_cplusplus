#include "Robot.h"

#include "RobotConfig.h"
#include "subsystems/Drive.h"
#include "CommandBase.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

std::unique_ptr<Autonomous> Robot::autonomousCommand;
AutonomousChooser Robot::AutoChooser;

void Robot::RobotInit() {
    CommandBase::init();
	CommandBase::drive->calibrateGyro();
	CommandBase::drive->safetyOff();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit() {
	autonomousCommand.reset(new Autonomous(AutoChooser.AutonomousSelection()));
	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() { 
    frc::Scheduler::GetInstance()->Run();
    AddSmartDashboardItems();
}

void Robot::TeleopInit() {
	//frc::SmartDashboard::PutNumber("breakpoint", 200);
	CommandBase::drive->resetGyro();
	CommandBase::drive->setMotors(0.0, 0.0);
}

void Robot::TeleopPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
    #if( PNEUMATICS_SUPPORT )
        frc::SmartDashboard::PutValue("Solenoid Value", CommandBase::pneumatics->getValue())
    #endif
    frc::SmartDashboard::PutNumber("Gyro Angle", CommandBase::drive->getGyroAngle());
    frc::SmartDashboard::PutNumber("Gyro Rate", CommandBase::drive->getGyroRate());
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
