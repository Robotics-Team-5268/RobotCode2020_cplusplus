#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class DriveStraightAutonomous : public frc2::CommandHelper<frc2::CommandBase, DriveStraightAutonomous> {
private:
    double mStartTime;
public:
    virtual void End(bool interrupted);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    DriveStraightAutonomous();
};
