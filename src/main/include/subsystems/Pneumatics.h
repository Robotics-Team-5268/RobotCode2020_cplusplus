#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

#include "RobotMap.h"

class Pneumatics : public frc2::SubsystemBase {
  public:
    Pneumatics();
    void ShiftForward();
    void ShiftReverse();
    void ShiftOff();

    void StingerForward();
    void StingerReverse();
    void StingerOff();

  private:
    frc::Compressor mCompressor{PCM_PORT};
    frc::DoubleSolenoid mShiftSolenoid{PCM_PORT, SHIFT_DOUBLESOLENOID_FORWARD_CHANNEL, SHIFT_DOUBLESOLENOID_REVERSE_CHANNEL};
    frc::DoubleSolenoid mStingerSolenoid{PCM_PORT, STINGER_DOUBLESOLENOID_FORWARD_CHANNEL, STINGER_DOUBLESOLENOID_REVERSE_CHANNEL};

};
