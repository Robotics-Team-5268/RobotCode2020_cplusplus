#include "subsystems/ColorWheel.h"

ColorWheel::ColorWheel() 
    : Subsystem("ColorWheel")
    , mColorSensor( frc::I2C::Port::kOnboard )
{

}

ColorWheel::~ColorWheel()
{

}
