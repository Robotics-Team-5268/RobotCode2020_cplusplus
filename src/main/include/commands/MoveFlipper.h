#pragma once

#include "CommandBase.h"

class MoveFlipper : public CommandBase {
   public:
      MoveFlipper(double aSetPoint);
      void Initialize() override;
      bool IsFinished() override;

  private:
    double mSetpoint;
};
