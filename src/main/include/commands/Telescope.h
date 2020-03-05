#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Winches.h"

class Telescope : public frc2::CommandHelper<frc2::CommandBase, Telescope> {
  public:
    Telescope( Winches* aWinches, bool aExtend );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

  private:
    Winches* mWinches;
    bool mExtend;
};
