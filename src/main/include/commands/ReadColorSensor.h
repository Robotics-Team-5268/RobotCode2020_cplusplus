#pragma once

#include <frc/commands/Command.h>

class ReadColorSensor : public frc::Command {
 public:
  ReadColorSensor();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:

};