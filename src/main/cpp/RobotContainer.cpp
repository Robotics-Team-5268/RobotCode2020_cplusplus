#include "RobotContainer.h"

std::unique_ptr<BallIntake> RobotContainer::ballIntake;
std::unique_ptr<ColorWheel> RobotContainer::colorWheel;
std::unique_ptr<Drive> RobotContainer::drive;
std::unique_ptr<IntakeFlipper> RobotContainer::intakeFlipper;
std::unique_ptr<LiftArm> RobotContainer::liftArm;
std::unique_ptr<OI> RobotContainer::oi;
std::unique_ptr<Pneumatics> RobotContainer::pneumatics;
std::unique_ptr<Winches> RobotContainer::winches;

RobotContainer::RobotContainer()
{
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
