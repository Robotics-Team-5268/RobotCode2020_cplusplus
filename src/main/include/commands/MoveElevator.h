#pragma once

#include "CommandBase.h"

class MoveElevator : public CommandBase {
 private:
  double speed;
 public:
  MoveElevator(double spd);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
