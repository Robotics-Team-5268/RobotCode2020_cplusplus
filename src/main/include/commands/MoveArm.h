#pragma once

#include "CommandBase.h"

class MoveArm : public CommandBase {
   public:
      MoveArm(double setPoint);
      void Initialize() override;
      bool IsFinished() override;

  private:
    double mSetpoint;
};
