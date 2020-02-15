#include "CommandBase.h"

std::unique_ptr<BallIntake> CommandBase::ballIntake;
std::unique_ptr<ColorWheel> CommandBase::colorWheel;
std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<IntakeFlipper> CommandBase::intakeFlipper;
std::unique_ptr<LiftArm> CommandBase::liftArm;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Pneumatics> CommandBase::pneumatics;
std::unique_ptr<Winches> CommandBase::winches;

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {

    ballIntake.reset( new BallIntake() );
    colorWheel.reset( new ColorWheel() );
    drive.reset(new Drive());
    intakeFlipper.reset( new IntakeFlipper() );
    liftArm.reset( new LiftArm() );
    pneumatics.reset(new Pneumatics());
    winches.reset( new Winches() );
    // Keep at the end
	oi.reset(new OI());
}
