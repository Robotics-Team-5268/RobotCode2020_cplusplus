#include "CommandBase.h"
#include "subsystems/Encoders.h"
#include "subsystems/Drive.h"

#include <Subsystems/Encoders.h>

std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<Encoders> CommandBase::leftEncoder;
std::unique_ptr<Encoders> CommandBase::rightEncoder;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Pneumatics> CommandBase::pneumatics;

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {
    drive.reset(new Drive());
    leftEncoder.reset(new Encoders("left", 3, 2, false));
	rightEncoder.reset(new Encoders("right", 1, 0, false));
    pneumatics.reset(new Pneumatics());
    // Keep at the end
	oi.reset(new OI());
}