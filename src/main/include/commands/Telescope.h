#pragma once

#include "CommandBase.h"

class Telescope : public CommandBase {
  public:
    Telescope( bool extend );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

  private:
    bool mExtend;
};
