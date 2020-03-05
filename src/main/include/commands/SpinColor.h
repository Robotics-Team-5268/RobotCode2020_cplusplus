#pragma once

#include <frc/commands/Command.h>
#include <subsystems/ColorWheel.h>

class SpinColor : public frc::Command {
 public:
  SpinColor( ColorWheel* aColorWheel );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;

 private:
    ColorWheel* mColorWheel;
    ColorWheel::MatchedColor mFmsColor; //!< Field management system color
    bool mColorMatched;
};