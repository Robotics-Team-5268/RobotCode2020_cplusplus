#pragma once

#include <frc/commands/Command.h>
#include "subsystems/Winches.h"

class Lift : public frc::Command {
  public:
    Lift( Winches* aWinches, bool aRaise );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;

  private:
    Winches* mWinches;
    bool mRaise;
};
