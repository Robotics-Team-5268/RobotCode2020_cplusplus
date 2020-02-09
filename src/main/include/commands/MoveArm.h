#pragma once

#include "CommandBase.h"

class MoveArm : public CommandBase {
   public:
      MoveArm(double aSetPoint);
      void Initialize() override;
      bool IsFinished() override;

  private:
    double mSetpoint;
};
