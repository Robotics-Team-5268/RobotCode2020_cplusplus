#pragma once

#include "RobotContainer.h"

class ReadColorSensor : public RobotContainer {
 public:
  ReadColorSensor();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:

};