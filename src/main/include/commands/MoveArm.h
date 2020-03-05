#pragma once

#include "RobotContainer.h"

class MoveArm : public RobotContainer {
   public:
      MoveArm( bool aRaise );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    bool mRaise;
};
