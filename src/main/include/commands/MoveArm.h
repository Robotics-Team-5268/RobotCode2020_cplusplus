#pragma once

#include <frc/commands/Command.h>
#include "subsystems/LiftArm.h"

class MoveArm : public frc::Command {
   public:
      MoveArm( LiftArm* aLiftArm, bool aRaise );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    LiftArm* mLiftArm;
    bool mRaise;
};
