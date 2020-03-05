#pragma once

#include <frc/commands/Command.h>
#include "subsystems/Drive.h"

class Autonomous : public frc::Command {
 public:
  Autonomous( Drive* aDrive, int aSelection );

  virtual ~Autonomous() {};
  virtual void End();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();

private:
  Drive* mDrive;
};
