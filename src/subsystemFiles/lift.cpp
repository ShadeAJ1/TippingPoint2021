#include "main.h"

void setLift(int power)
{
    lift = power;
}

void controlLift()
{
    int power = 127 * (master.get_digital(DIGITAL_L2) - master.get_digital(DIGITAL_L1));
    setLift(power);
}
