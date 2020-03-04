#pragma once

#include <frc/TimedRobot.h>

#include "commands/Autonomous.h"
#include "AutonomousChooser.h"



class Robot : public frc::TimedRobot {
 public:
  static std::unique_ptr<Autonomous> autonomousCommand;
  static AutonomousChooser AutoChooser;
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
};
