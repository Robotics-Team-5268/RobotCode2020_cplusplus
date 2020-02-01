#include "CommandBase.h"

std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<OI> CommandBase::oi;
#if( PNEUMATICS_SUPPORT )
    std::unique_ptr<Pneumatics> CommandBase::pneumatics;
#endif

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {
    drive.reset(new Drive());
    #if( PNEUMATICS_SUPPORT )
        pneumatics.reset(new Pneumatics());
    #endif
    // Keep at the end
	oi.reset(new OI());
}