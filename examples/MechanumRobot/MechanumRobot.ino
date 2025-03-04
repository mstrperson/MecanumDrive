#include <DCMotor.h>
#include <MecanumDrive.h>

#define LEFT_FRONT_PIN 5
#define RIGHT_FRONT_PIN 6
#define LEFT_BACK_PIN 9
#define RIGHT_BACK_PIN 10

#define PWM_MIN 500     // PWM duty cycle (us) for Full Reverse
#define PWM_MAX 2500    // PWM duty cycle (us) for Full Forward

MecanumDrive* robot;

void setup()
{
    Serial.begin(9600);
    // Initialize the Robot.
    robot = new MecanumDrive(
      LEFT_FRONT_PIN,
      RIGHT_FRONT_PIN,
      RIGHT_BACK_PIN,
      LEFT_BACK_PIN);

    // Set the Pulse Range given the specs of your Motor Controller.
    // REV Smart Servos range from 500us~2500us duty cycle.
    robot->setPWMPulseRange(PWM_MIN, PWM_MAX);
    robot->setMotorOrientations(FORWARD, REVERSE, REVERSE, FORWARD);

}

void loop()
{
    double thetaD = ((millis()%36000)/100.0);
    double theta = thetaD * PI/180;
    double x = cos(theta), y = sin(theta);
    Serial.print(thetaD);
    Serial.print(",");
    Serial.print(theta);
    Serial.print(",");
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.println(atan2(y, x));

    // Send the Drive Command
    robot->drive(x, y, 0);
    delay(50);
}
