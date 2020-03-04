#include "subsystems/Pneumatics.h"

Pneumatics::Pneumatics() : frc2::SubsystemBase() {
    SetName( "Pneumatics" );
}

void Pneumatics::Forward() {
    doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::Reverse() {
    doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::Off() {
    doubleSolenoid.Set(frc::DoubleSolenoid::kOff);
}