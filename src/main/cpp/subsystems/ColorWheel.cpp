#include "subsystems/ColorWheel.h"

// TODO: Set these colors based on our sensor
static constexpr frc::Color sBlueTarget = frc::Color(0.143, 0.427, 0.429);
static constexpr frc::Color sGreenTarget = frc::Color(0.197, 0.561, 0.240);
static constexpr frc::Color sRedTarget = frc::Color(0.561, 0.232, 0.114);
static constexpr frc::Color sYellowTarget = frc::Color(0.361, 0.524, 0.113);

ColorWheel::ColorWheel() 
    : frc2::SubsystemBase()
    , mColorSensor( frc::I2C::Port::kOnboard )
{
    SetName( "ColorWheel" );

    mColorMatcher.AddColorMatch(sBlueTarget);
    mColorMatcher.AddColorMatch(sGreenTarget);
    mColorMatcher.AddColorMatch(sRedTarget);
    mColorMatcher.AddColorMatch(sYellowTarget);
}

ColorWheel::~ColorWheel()
{

}

ColorWheel::ColorReading ColorWheel::readColorSensor()
{
    ColorReading reading;
    reading.color = mColorSensor.GetColor();
    frc::Color closestColor = mColorMatcher.MatchClosestColor( reading.color, reading.matchConfidence );

    if( sBlueTarget == closestColor )
    {
        reading.matchedColor = BLUE;
    }
    else if( sGreenTarget == closestColor )
    {
        reading.matchedColor = GREEN;
    }
    else if( sRedTarget == closestColor )
    {
        reading.matchedColor = RED;
    }
    else if( sYellowTarget == closestColor )
    {
        reading.matchedColor = YELLOW;
    }    

    return reading;

}
