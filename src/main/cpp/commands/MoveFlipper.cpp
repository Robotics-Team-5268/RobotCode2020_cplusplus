#include "commands/MoveFlipper.h"

#include "RobotContainer.h"

MoveFlipper::MoveFlipper( bool aOpen )
{
    SetName( "MoveFlipper" );

    Requires(RobotContainer::intakeFlipper.get());
    mOpen = aOpen;
}

void MoveFlipper::End()
{
  intakeFlipper->setSpeed( 0.0 );
}

void MoveFlipper::Execute()
{
  if( mOpen )
  {
    intakeFlipper->setSpeed( 0.4 );
  }
  else
  {
    intakeFlipper->setSpeed( -0.4 );
  }
}

void MoveFlipper::Initialize()
{

}

// Make this return true when this Command no longer needs to run execute()
bool MoveFlipper::IsFinished()
{
  bool finished = false;
  if( mOpen )
  {
     // Value taken from REV-11-1271 datasheet
     // const double pulsesPerRevolution = 8192.0;
     // 850 pulses * 360 degrees / 8192 pulses pre revolution ~=  37 degrees
    if( intakeFlipper->getEncoderValue() >= 850 )
    {
      finished = true;
    }
  }
  else
  {
    if( intakeFlipper->getEncoderValue() <= 0 )
    {
      finished = true;
    }
  }
  
  return finished;
}
