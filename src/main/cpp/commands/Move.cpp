#include "commands/Move.h"

#include "RobotContainer.h"

Move::Move(float tm, float spd) {
  AddRequirements(RobotContainer::drive.get());
  pid = nullptr;
  seconds = tm;
  speed = spd;
  timer.reset(new frc::Timer());
}

void Move::Initialize() {}

void Move::Execute() {
  if(pid) {
    
  }
}

bool Move::IsFinished() { 
  return timer->HasPeriodPassed(seconds); 
  }

void Move::End(bool interrupted) {}
