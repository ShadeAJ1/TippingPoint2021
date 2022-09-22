#include "main.h"

void controlClaw()
{
    if (master.get_digital_new_press(DIGITAL_Y))
    {
        claw.set_value(!claw.get_value());
    }
}