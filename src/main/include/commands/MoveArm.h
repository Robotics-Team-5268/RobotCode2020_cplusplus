#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/LiftArm.h"

class MoveArm : public frc2::CommandHelper<frc2::CommandBase, MoveArm>
{
   public:
      MoveArm( LiftArm* aLiftArm, bool aRaise );
      void End(bool interrupted) override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    LiftArm* mLiftArm;
    bool mRaise;
};
