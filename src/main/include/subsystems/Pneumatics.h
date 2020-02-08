#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

#include "RobotMap.h"

class Pneumatics : public frc::Subsystem {
  public:
    Pneumatics();
    void ShiftForward();
    void ShiftReverse();
    void ShiftOff();

    void StingerForward();
    void StingerReverse();
    void StingerOff();

  private:
    frc::Compressor compressor{PCM_PORT};
    frc::DoubleSolenoid shiftSolenoid{PCM_PORT, SHIFT_DOUBLESOLENOID_FORWARD_CHANNEL, SHIFT_DOUBLESOLENOID_REVERSE_CHANNEL};
    frc::DoubleSolenoid stingerSolenoid{PCM_PORT, STINGER_DOUBLESOLENOID_FORWARD_CHANNEL, STINGER_DOUBLESOLENOID_REVERSE_CHANNEL};

};
