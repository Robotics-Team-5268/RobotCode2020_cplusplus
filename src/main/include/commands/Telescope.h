#pragma once

#include <frc/commands/Command.h>

class Telescope : public frc::Command {
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
