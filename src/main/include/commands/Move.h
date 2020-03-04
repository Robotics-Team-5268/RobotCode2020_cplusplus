#pragma once

#include <frc/PIDController.h>
#include <frc/Timer.h>

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Move : public frc2::CommandHelper<frc2::CommandBase, Move> {
 public:
  Move(float tm, float spd);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

  float speed;
  float seconds;
  std::shared_ptr<frc::Timer> timer;
  frc::PIDController* pid;
};

class MovePIDOutput: public frc::PIDOutput {
  public:
    MovePIDOutput(double sp);
    virtual ~MovePIDOutput();
    void PIDWrite(double a);
    float speed;
};
