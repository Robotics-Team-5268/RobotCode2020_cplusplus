#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/ColorWheel.h>

class SpinColor : public frc2::CommandHelper<frc2::CommandBase, SpinColor>
{
public:
  SpinColor( ColorWheel* aColorWheel );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

 private:
    ColorWheel* mColorWheel;
    ColorWheel::MatchedColor mFmsColor; //!< Field management system color
    bool mColorMatched;
};