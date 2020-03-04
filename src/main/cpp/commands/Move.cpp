#include "commands/Move.h"

#include "Commands.h"

Move::Move(float tm, float spd) {
  AddRequirements(Commands::drive.get());
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
