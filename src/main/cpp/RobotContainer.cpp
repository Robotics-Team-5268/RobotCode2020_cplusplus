#include "RobotContainer.h"

#include "commands/DriveWithJoystick.h"

std::unique_ptr<ColorWheel> RobotContainer::colorWheel;
std::unique_ptr<Drive> RobotContainer::drive;
std::unique_ptr<OI> RobotContainer::oi;
#if( PNEUMATICS_SUPPORT )
    std::unique_ptr<Pneumatics> RobotContainer::pneumatics;
#endif

void RobotContainer::init() {
    colorWheel.reset( new ColorWheel() );
    drive.reset(new Drive());
    drive->SetDefaultCommand( DriveWithJoystick());
    #if( PNEUMATICS_SUPPORT )
        pneumatics.reset(new Pneumatics());
    #endif
    // Keep at the end
	oi.reset(new OI());
}