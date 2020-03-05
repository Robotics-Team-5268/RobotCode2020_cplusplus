#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IntakeFlipper.h"

class MoveFlipper : public frc2::CommandHelper<frc2::CommandBase, MoveFlipper>
{
   public:
      MoveFlipper( IntakeFlipper* aIntakeFlipper, bool aOpen );
      void End(bool interrupted) override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    IntakeFlipper* mIntakeFlipper;
    bool mOpen;
};
