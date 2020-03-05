#pragma once

#include <frc/commands/Command.h>
#include "subsystems/Winches.h"

class Telescope : public frc::Command {
  public:
    Telescope( Winches* aWinches, bool aExtend );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;

  private:
    Winches* mWinches;
    bool mExtend;
};
