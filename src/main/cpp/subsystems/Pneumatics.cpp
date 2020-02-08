#include "subsystems/Pneumatics.h"

Pneumatics::Pneumatics() : Subsystem("Pnuematics") {

}

void Pneumatics::ShiftForward() {
    shiftSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::ShiftReverse() {
    shiftSolenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::ShiftOff() {
    shiftSolenoid.Set(frc::DoubleSolenoid::kOff);
}

void Pneumatics::StingerForward() {
    stingerSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Pneumatics::StingerReverse() {
    stingerSolenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Pneumatics::StingerOff() {
    stingerSolenoid.Set(frc::DoubleSolenoid::kOff);
}