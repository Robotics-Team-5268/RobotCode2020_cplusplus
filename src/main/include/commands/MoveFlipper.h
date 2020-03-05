#pragma once

#include <frc/commands/Command.h>
#include "subsystems/IntakeFlipper.h"

class MoveFlipper : public frc::Command {
   public:
      MoveFlipper( IntakeFlipper* aIntakeFlipper, bool aOpen );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    IntakeFlipper* mIntakeFlipper;
    bool mOpen;
};
