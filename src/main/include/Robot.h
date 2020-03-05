#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "RobotContainer.h"

class Robot : public frc::TimedRobot
{
public:
  Robot();

private:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void AddSmartDashboardItems();

  RobotContainer mRobotContainer;

  frc2::Command* mAutonomousCommand;
};
