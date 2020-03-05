#pragma once

#include <frc/commands/Command.h>

class Lift : public frc::Command {
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
