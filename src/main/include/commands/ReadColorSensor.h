#pragma once

#include "CommandBase.h"

class ReadColorSensor : public CommandBase {
 public:
  ReadColorSensor();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:

};