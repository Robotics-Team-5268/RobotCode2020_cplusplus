#pragma once

#include "RobotContainer.h"

class Telescope : public RobotContainer {
  public:
    Telescope( bool aExtend );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

  private:
    bool mExtend;
};
