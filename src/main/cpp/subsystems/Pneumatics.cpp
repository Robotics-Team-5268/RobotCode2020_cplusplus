#include "subsystems/Pneumatics.h"

Pneumatics::Pneumatics()
{
    SetName( "Pnuematics" );
}

void Pneumatics::ShiftForward() {
    mShiftSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::ShiftReverse() {
    mShiftSolenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::ShiftOff() {
    mShiftSolenoid.Set(frc::DoubleSolenoid::kOff);
}

void Pneumatics::StingerForward() {
    mStingerSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::StingerReverse() {
    mStingerSolenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::StingerOff() {
    mStingerSolenoid.Set(frc::DoubleSolenoid::kOff);
}