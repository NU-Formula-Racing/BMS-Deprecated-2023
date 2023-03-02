#pragma once

class IBMS
{
public:
    enum class BMSFault : bool
    {
        kNotFaulted = 0,
        kFaulted = 1,
    };

    enum class BMSState
    {
        kShutdown = 0,
        kPrecharge = 1,
        kActive = 2,
        kCharging = 3,
        kFault = 4
    };
};