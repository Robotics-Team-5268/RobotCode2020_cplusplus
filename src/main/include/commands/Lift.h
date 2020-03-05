#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Winches.h"

class Lift : public frc2::CommandHelper<frc2::CommandBase, Lift>
{
  public:
    Lift( Winches* aWinches, bool aRaise );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

  private:
    Winches* mWinches;
    bool mRaise;
};
