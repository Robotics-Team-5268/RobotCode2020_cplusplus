#include "commands/MoveArm.h"

MoveArm::MoveArm( LiftArm* aLiftArm, bool aRaise )
  : mLiftArm( aLiftArm )
  , mRaise( aRaise )
{
  SetName( "MoveArm" );

  AddRequirements(mLiftArm);
}

void MoveArm::End(bool interrupted)
{
  mLiftArm->setSpeed( 0.0 );
}

void MoveArm::Execute()
{
  if( mRaise )
  {
    mLiftArm->setSpeed( 0.4 );
  }
  else
  {
    mLiftArm->setSpeed( -0.4 );
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
    if( mLiftArm->getEncoderValue() >= 3072 )
    {
      finished = true;
    }
  }
  else
  {
    if( mLiftArm->getEncoderValue() <= 0 )
    {
      finished = true;
    }    
  }

  return finished;
}
