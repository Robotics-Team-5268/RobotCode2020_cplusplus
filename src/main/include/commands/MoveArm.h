#pragma once

#include <frc/commands/Command.h>

class MoveArm : public frc::Command {
   public:
      MoveArm( bool aRaise );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    bool mRaise;
};
