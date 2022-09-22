#include "main.h"

// helper functions
void setDrive(double left, double right)
{
    frontLeft = left;
    centerLeft = left;
    backLeft = left;
    frontRight = right;
    centerRight = right;
    backRight = right;
}

double avgDrivePosition()
{

    return (fabs(frontLeft.get_position()) + fabs(centerLeft.get_position()) + fabs(backLeft.get_position()) + fabs(frontRight.get_position()) + fabs(centerRight.get_position()) + fabs(backRight.get_position())) / 6;
}

void setDriveCoast()
{
    frontLeft.set_brake_mode(MOTOR_BRAKE_COAST);
    centerLeft.set_brake_mode(MOTOR_BRAKE_COAST);
    backLeft.set_brake_mode(MOTOR_BRAKE_COAST);
    frontRight.set_brake_mode(MOTOR_BRAKE_COAST);
    centerRight.set_brake_mode(MOTOR_BRAKE_COAST);
    backRight.set_brake_mode(MOTOR_BRAKE_COAST);
}

void resetDriveEncoders()
{
    frontLeft.tare_position();
    centerLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    centerRight.tare_position();
    backRight.tare_position();
}

// main functions

void controlDrive()
{
    double left = master.get_analog(ANALOG_LEFT_Y);
    double right = master.get_analog(ANALOG_RIGHT_Y);
    setDrive(left, right);
}

void moveFeet(double feet, double voltage)
{
    double units = ((feet * 12) / (wheelDiameter * M_PI)) * driveGearRatio * 300;
    int direction = abs(units) / units;

    resetDriveEncoders();
    gyro.tare_heading();

    while (avgDrivePosition() < abs(units))
    {
        setDrive(voltage * direction - gyro.get_heading(), voltage * direction + gyro.get_heading());
        pros::delay(10);
    }

    setDrive(-10 * direction, -10 * direction);
    pros::delay(50);
    setDrive(0, 0);
}

void turnDegrees(double degrees, double voltage)
{
    int direction = abs(degrees) / degrees;
    gyro.tare_heading();

    // positive degrees is right, negative degrees is left
    while (gyro.get_heading() < abs(degrees))
    {
        setDrive(voltage * direction, -voltage * direction);
        pros::delay(10);
    }
    // wait for robot to lose momentum
    pros::delay(100);
}