#pragma once

#include <memory>
#include <vector>

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>

class OI {
 private:
  std::shared_ptr<frc::Joystick> driverJoystick, mechanismsJoystick;
  std::vector<frc::JoystickButton*> driverBtns, mechanismsBtns;
 public:
  std::shared_ptr<frc::Joystick> getDriverJoystick();
  OI();
};
