#include <commands/ReadColorSensor.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/ColorWheel.h>


ReadColorSensor::ReadColorSensor() : RobotContainer("ReadColorSensor") {
    Requires( colorWheel.get() );
}

void ReadColorSensor::Initialize() {}

void ReadColorSensor::Execute() {
    ColorWheel::ColorReading colorReading = colorWheel->readColorSensor();

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

bool ReadColorSensor::IsFinished() { 
    return true; 
}

void ReadColorSensor::End()
{

}

void ReadColorSensor::Interrupted()
{

}
