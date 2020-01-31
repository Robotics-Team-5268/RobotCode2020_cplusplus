#include "CommandBase.h"

std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Pneumatics> CommandBase::pneumatics;

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {
    drive.reset(new Drive());
    pneumatics.reset(new Pneumatics());
    // Keep at the end
	oi.reset(new OI());
}