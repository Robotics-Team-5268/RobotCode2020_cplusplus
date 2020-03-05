#include "commands/MoveFlipper.h"

MoveFlipper::MoveFlipper( IntakeFlipper* aIntakeFlipper, bool aOpen )
  : mIntakeFlipper( aIntakeFlipper )
  , mOpen( aOpen )
{
    SetName( "MoveFlipper" );

    AddRequirements( mIntakeFlipper );
}

void MoveFlipper::End(bool interrupted)
{
  mIntakeFlipper->setSpeed( 0.0 );
}

void MoveFlipper::Execute()
{
  if( mOpen )
  {
    mIntakeFlipper->setSpeed( 0.4 );
  }
  else
  {
    mIntakeFlipper->setSpeed( -0.4 );
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
    if( mIntakeFlipper->getEncoderValue() >= 850 )
    {
      finished = true;
    }
  }
  else
  {
    if( mIntakeFlipper->getEncoderValue() <= 0 )
    {
      finished = true;
    }
  }
  
  return finished;
}
