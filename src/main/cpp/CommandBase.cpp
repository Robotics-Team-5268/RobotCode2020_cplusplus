#include "CommandBase.h"

std::unique_ptr<BallIntake> CommandBase::ballIntake;
std::unique_ptr<ColorWheel> CommandBase::colorWheel;
std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<LiftArm> CommandBase::liftArm;
std::unique_ptr<OI> CommandBase::oi;
#if( PNEUMATICS_SUPPORT )
    std::unique_ptr<Pneumatics> CommandBase::pneumatics;
#endif

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {

    ballIntake.reset( new BallIntake() );
    colorWheel.reset( new ColorWheel() );
    drive.reset(new Drive());
    liftArm.reset( new LiftArm() );
    #if( PNEUMATICS_SUPPORT )
        pneumatics.reset(new Pneumatics());
    #endif
    // Keep at the end
	oi.reset(new OI());
}
