//
// Created by Jason Cox on 3/1/25.
//

#include "DCMotor.h"
#include "Servo.h"

int DCMotor::MapDoubleToPWM(double percentage)
{
    if (percentage > 1) percentage = 1;
    else if (percentage < -1) percentage = -1;
    
    int offset = percentage * (PWM_MAX-PWM_ZERO);
    return PWM_ZERO + offset;
}

DCMotor::DCMotor(unsigned int pin)
{
    this->pin = pin;
    servo = Servo();
    this->servo.attach(pin);
}

/// 
/// @param speed -1.0 to 1.0
void DCMotor::setSpeed(double speed)
{
    if (this->reversed)
        speed = -speed;
    int pwm = MapDoubleToPWM(speed);

    servo.writeMicroseconds(pwm);
}

void DCMotor::setPWMPulseRange(int min, int max)
{
    this->PWM_MIN = min;
    this->PWM_MAX = max;
    this->PWM_ZERO = PWM_MIN + (PWM_MAX-PWM_MIN)/2;
}
