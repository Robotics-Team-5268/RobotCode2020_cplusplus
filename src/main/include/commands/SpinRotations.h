#pragma once

#include "CommandBase.h"

class SpinRotations : public CommandBase {
 public:
  SpinRotations
    (
    int aNumRotations
    );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
    int mNumRotations;
};