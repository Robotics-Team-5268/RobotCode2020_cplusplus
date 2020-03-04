#include "Commands.h"

#include "commands/DriveWithJoystick.h"

std::unique_ptr<ColorWheel> Commands::colorWheel;
std::unique_ptr<Drive> Commands::drive;
std::unique_ptr<OI> Commands::oi;
#if( PNEUMATICS_SUPPORT )
    std::unique_ptr<Pneumatics> Commands::pneumatics;
#endif

void Commands::init() {
    colorWheel.reset( new ColorWheel() );
    drive.reset(new Drive());
    drive->SetDefaultCommand( DriveWithJoystick());
    #if( PNEUMATICS_SUPPORT )
        pneumatics.reset(new Pneumatics());
    #endif
    // Keep at the end
	oi.reset(new OI());
}