#include "main.h"

void controlTilt()
{
    if (master.get_digital_new_press(DIGITAL_RIGHT))
    {
        tilt.set_value(!tilt.get_value());
    }
}