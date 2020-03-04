#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

#include "RobotMap.h"

class Pneumatics : public frc2::SubsystemBase {
 private:
  frc::Compressor compressor{PCM_PORT};
  frc::DoubleSolenoid doubleSolenoid{PCM_PORT, DOUBLESOLENOID_FORWARD_CHANNEL, DOUBLESOLENOID_REVERSE_CHANNEL};
 public:
  Pneumatics();
  void Forward();
  void Reverse();
  void Off();
};
