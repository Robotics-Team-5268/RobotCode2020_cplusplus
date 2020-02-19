#pragma once

#include "CommandBase.h"

class MoveArm : public CommandBase {
   public:
      MoveArm( bool aRaise );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    bool mRaise;
};
