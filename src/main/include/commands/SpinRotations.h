#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/ColorWheel.h>

class SpinRotations : public frc2::CommandHelper<frc2::CommandBase, SpinRotations>
{
 public:
  SpinRotations
    (
    ColorWheel* aColorWheel,
    int aNumRotations
    );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
    ColorWheel* mColorWheel;
    int mNumRotations;
    ColorWheel::MatchedColor mLastMatchedColor;
    int mColorChangeCount;
};