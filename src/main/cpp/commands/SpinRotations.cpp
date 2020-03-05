#include <commands/SpinRotations.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/ColorWheel.h>

#include "RobotContainer.h"

static const int ColorsPerRotation = 8;

SpinRotations::SpinRotations( int aNumRotations )
    : mNumRotations( aNumRotations )
    , mLastMatchedColor( ColorWheel::NO_MATCH )
    , mColorChangeCount( 0 )
{
    SetName("SpinRotations");
    Requires( RobotContainer::colorWheel.get() );
}

void SpinRotations::Initialize()
{
    mLastMatchedColor = ColorWheel::NO_MATCH;
    mColorChangeCount = 0;
}

void SpinRotations::Execute() {
    ColorWheel::ColorReading colorReading = RobotContainer::colorWheel->readColorSensor();

    if( colorReading.matchedColor != mLastMatchedColor )
    {
        ++mColorChangeCount;
        mLastMatchedColor = colorReading.matchedColor;
    }

    // Spin at a slow speed until we determine reliability of the system
    RobotContainer::colorWheel->spin( 0.2 );

    std::string colorString = "No Match";
    switch( colorReading.matchedColor )
    {
    case ColorWheel::BLUE:
        colorString = "Blue";
        break;

    case ColorWheel::YELLOW:
        colorString = "Yellow";
        break;

    case ColorWheel::GREEN:
        colorString = "Green";
        break;
    
    case ColorWheel::RED:
        colorString = "Red";
        break;

    default:
        break;
    }

    frc::SmartDashboard::PutString("Detected Color", colorString);
    frc::SmartDashboard::PutNumber("NumberRotations", mColorChangeCount / ColorsPerRotation );
}

bool SpinRotations::IsFinished()
{
    return( mColorChangeCount >= mNumRotations * ColorsPerRotation ) ;
}

void SpinRotations::End()
{
    RobotContainer::colorWheel->spin( 0.0 );
}
