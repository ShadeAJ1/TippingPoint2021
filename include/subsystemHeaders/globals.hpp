#include "main.h"

// MOTORS
extern Motor frontRight;
extern Motor backRight;
extern Motor centerRight;
extern Motor frontLeft;
extern Motor backLeft;
extern Motor centerLeft;

extern Motor lift;
extern Motor intake;

// PNEUMATICS
extern ADIPort claw;
extern ADIPort tilt;

// MISC
extern Imu gyro;
extern pros::Controller master

// MATH
#define liftGearRatio 7
#define driveGearRatio 2.33333
#define wheelDiameter 4

// PORTS
#define frontRightPort 8
#define centerRightPort 1
#define backRightPort 5
#define frontLeftPort 4
#define centerLeftPort 1
#define backLeftPort 6

#define intakePort 7
#define liftPort 10

#define clawPort 'A'
#define tiltPort 'D'
#define gyroPort 1