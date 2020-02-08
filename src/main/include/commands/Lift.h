#pragma once

#include "CommandBase.h"

class Lift : public CommandBase {
  public:
    Lift( bool raise );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

  private:
    bool mRaise;
};
