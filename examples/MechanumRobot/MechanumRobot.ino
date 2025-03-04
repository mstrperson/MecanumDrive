#include <DCMotor.h>
#include <MecanumDrive.h>

#define LEFT_FRONT_PIN 5
#define RIGHT_FRONT_PIN 6
#define LEFT_BACK_PIN 9
#define RIGHT_BACK_PIN 10

MecanumDrive* robot;

void setup()
{
    robot = new MecanumDrive(
      LEFT_FRONT_PIN,
      RIGHT_FRONT_PIN,
      RIGHT_BACK_PIN,
      LEFT_BACK_PIN);
    robot.setPWMPulseRange(500, 2500);
}

void loop()
{
    double theta = ((millis()%360000)/1000.0) * 180.0/PI;
    double x = cos(theta), y = sin(theta);
    robot->drive(x, y, 0);
    delay(50);
}
