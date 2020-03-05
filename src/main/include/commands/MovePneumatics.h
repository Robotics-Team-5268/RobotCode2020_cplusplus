#pragma once

#if( PNEUMATICS_SUPPORT )
    #include "subsystems/Pneumatics.h"
#endif
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/DoubleSolenoid.h>

class MovePneumatics : public frc2::CommandHelper<frc2::CommandBase, MovePneumatics> {
 public:
  MovePneumatics
    (
    frc::DoubleSolenoid::Value v
    #if( PNEUMATICS_SUPPORT )
      , Pneumatics* aPneumantics
    #endif
    );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  frc::DoubleSolenoid::Value value;
  #if( PNEUMATICS_SUPPORT )
    Pneumatics* mPneumantics
  #endif

};
