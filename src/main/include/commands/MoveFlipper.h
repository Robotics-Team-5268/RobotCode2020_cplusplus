#pragma once

#include "CommandBase.h"

class MoveFlipper : public CommandBase {
   public:
      MoveFlipper(double setPoint);
      void Initialize() override;
      bool IsFinished() override;

  private:
    double mSetpoint;
};
