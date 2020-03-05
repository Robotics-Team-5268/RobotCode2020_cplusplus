#pragma once

#include <frc/commands/Command.h>

class MoveFlipper : public frc::Command {
   public:
      MoveFlipper( bool aOpen );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    bool mOpen;
};
