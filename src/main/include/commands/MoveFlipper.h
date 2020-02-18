#pragma once

#include "CommandBase.h"

class MoveFlipper : public CommandBase {
   public:
      MoveFlipper( bool aOpen );
      void End() override;
      void Execute() override;
      void Initialize() override;
      bool IsFinished() override;

  private:
    bool mOpen;
};
