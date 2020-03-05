#pragma once

#include <frc/commands/Command.h>

class Autonomous : public frc::Command {
 public:
  Autonomous(int aSelection);

  virtual ~Autonomous() {};
  virtual void End();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
};
