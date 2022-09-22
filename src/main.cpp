#include "main.h"

void autonomous()
{
    pros::delay(10);
}

void initialize()
{
    pros::lcd::initialize();
    pros::lcd::set_text(1, "8771Z: Shaky Flywheels");

    lift.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    setDriveCoast();

    gyro.reset();
    pros::delay(2000);
}

void competition_initialize()
{
    // autonomous selector
}

void disabled()
{
}

void on_center_button()
{
    static bool pressed = false;
    pressed = !pressed;
    if (pressed)
    {
        pros::lcd::set_text(2, "I was pressed!");
    }
    else
    {
        pros::lcd::clear_line(2);
    }
}

void opcontrol()
{
    while (true)
    {
        controlDrive();
        controlIntake();
        controlLift();
        controlTilt();
        controlClaw();
    }
}