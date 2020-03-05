#include "commands/MoveArm.h"

#include "RobotContainer.h"

#include "RobotContainer.h"

MoveArm::MoveArm( bool aRaise )
{
  SetName( "MoveArm" );

  Requires(RobotContainer::liftArm.get());
  mRaise = aRaise;
}

void MoveArm::End()
{
  RobotContainer::liftArm->setSpeed( 0.0 );
}

void MoveArm::Execute()
{
  if( mRaise )
  {
    RobotContainer::liftArm->setSpeed( 0.4 );
  }
  else
  {
    RobotContainer::liftArm->setSpeed( -0.4 );
  }
}

void MoveArm::Initialize()
{

}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished()
{
  bool finished = false;

  if( mRaise )
  {
     // Value taken from REV-11-1271 datasheet
     // const double pulsesPerRevolution = 8192.0;
     // 3072 pulses * 360 degrees / 8192 pulses pre revolution ~=  135 degrees
    if( RobotContainer::liftArm->getEncoderValue() >= 3072 )
    {
      finished = true;
    }
  }
  else
  {
    if( RobotContainer::liftArm->getEncoderValue() <= 0 )
    {
      finished = true;
    }    
  }
   

  return finished;
}