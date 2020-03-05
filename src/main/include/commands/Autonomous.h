#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Drive.h"

class Autonomous : public frc2::CommandHelper<frc2::CommandBase, Autonomous>
{
public:
  Autonomous( Drive* aDrive, int aSelection );

  virtual ~Autonomous() {};
  void End(bool interrupted) override;
  virtual void Initialize() override;
  virtual void Execute() override;
  virtual bool IsFinished() override;

private:
  Drive* mDrive;
};
