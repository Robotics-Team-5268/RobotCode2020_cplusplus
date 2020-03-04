#pragma once

#include <memory>
#include <vector>

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

class OI {
 private:
  std::shared_ptr<frc::Joystick> driverJoystick, mechanismsJoystick;
  std::vector<frc2::JoystickButton*> driverBtns, mechanismsBtns;
 public:
  std::shared_ptr<frc::Joystick> getDriverJoystick();
  OI();
};
