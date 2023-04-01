#pragma once
#include <Arduino.h>

class CoulombCounting
{
private:
    float StateOfCharge;
    float full_capacity;
    int remaining;

public:
    void Initialize(float SOC)
    {
        StateOfCharge = SOC;
        remaining = SOC * full_capacity * 60;
    }

    int countCoulombs(float current, uint32_t time)
    {
        remaining -= current * time / 1000;
        return remaining;
    }

    float getSOC()
    {
        StateOfCharge = remaining * 1000 / (60 * full_capacity);
        return StateOfCharge;
    }

    CoulombCounting(float full_charge_capacity) { full_capacity = full_charge_capacity; }
};