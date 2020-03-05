#pragma once

#include "RobotContainer.h"

class MoveFlipper : public RobotContainer {
   public:
      MoveFlipper( bool aOpen );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    bool mOpen;
};
