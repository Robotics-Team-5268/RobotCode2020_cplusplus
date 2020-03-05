#pragma once

#include "RobotContainer.h"

class Lift : public RobotContainer {
  public:
    Lift( bool aRaise );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

  private:
    bool mRaise;
};
