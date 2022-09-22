#include "main.h"

Motor frontLeft(frontLeftPort, E_MOTOR_GEARSET_06, true);
Motor centerLeft(centerLeftPort, E_MOTOR_GEARSET_06, false);
Motor backLeft(backLeftPort, E_MOTOR_GEARSET_06, false);

Motor frontRight(frontRightPort, E_MOTOR_GEARSET_06, true);
Motor centerRight(centerRightPort, E_MOTOR_GEARSET_06, false);
Motor backRight(backRightPort, E_MOTOR_GEARSET_06, false);

Motor lift(liftPort, E_MOTOR_GEARSET_36, false);
Motor intake(intakePort, E_MOTOR_GEARSET_06);

ADIPort claw(clawPort);
ADIPort tilt(tiltPort);
Imu gyro(gyroPort);

Controller master(E_CONTROLLER_MASTER);
