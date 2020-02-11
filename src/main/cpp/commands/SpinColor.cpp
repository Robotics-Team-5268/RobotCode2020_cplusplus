#include <commands/SpinColor.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/ColorWheel.h>

SpinColor::SpinColor()
    : CommandBase("SpinColor")
    , mFmsColor( ColorWheel::NO_MATCH )
    , mColorMatched( false )
{
    Requires( colorWheel.get() );
}

void SpinColor::Initialize()
{
    mFmsColor = ColorWheel::NO_MATCH;
    mColorMatched = false;
    std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    if( !gameData.empty() )
    {
        switch (gameData[0])
        {
        case 'B' :
            //Blue case code
            mFmsColor = ColorWheel::BLUE;
            break;
        case 'G' :
            //Green case code
            mFmsColor = ColorWheel::GREEN;
            break;
        case 'R' :
            //Red case code
            mFmsColor = ColorWheel::RED;
            break;
        case 'Y' :
            //Yellow case code
            mFmsColor = ColorWheel::YELLOW;
            break;
        default :
            //This is corrupt data
            break;
        }
    }

    std::string colorString = "No Match";
    switch( mFmsColor )
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
    frc::SmartDashboard::PutString( "FMS Color", colorString );
}

void SpinColor::Execute()
{
    ColorWheel::ColorReading colorReading = colorWheel->readColorSensor();

    if( colorReading.matchedColor == mFmsColor ||
        ColorWheel::NO_MATCH == mFmsColor )
    {
        // If we matched color the FMS color or the field management system hasn't given us a color yet,
        // stop spinning and end this command
        colorWheel->spin( 0.0 );
        mColorMatched = true;
    }
    else
    {
        // For now, spin at a slow speed until we can prove reliable at higher speed
        colorWheel->spin( 0.2 );
    }

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

    frc::SmartDashboard::PutNumber("Red", colorReading.color.red);
    frc::SmartDashboard::PutNumber("Green", colorReading.color.green);
    frc::SmartDashboard::PutNumber("Blue", colorReading.color.blue);
    frc::SmartDashboard::PutNumber("Confidence", colorReading.matchConfidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
}

bool SpinColor::IsFinished() { 
    return mColorMatched;
}

void SpinColor::End()
{

}

void SpinColor::Interrupted()
{

}
