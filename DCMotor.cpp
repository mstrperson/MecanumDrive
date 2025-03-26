//
// Created by Jason Cox on 3/1/25.
//

#include "DCMotor.h"
#include "Servo.h"

/// validate and map the percentage into the range [PWM_MIN, PWM_MAX] linearly
/// such that 0.0 -> PWM_ZERO.
int DCMotor::mapDoubleToPWM(double percentage)
{
    if (percentage > 1) percentage = 1;
    else if (percentage < -1) percentage = -1;
    
    int offset = percentage * (PWM_MAX-PWM_ZERO);
    return PWM_ZERO + offset;
}

/// Initialize a simple DCMotor
/// @param pin PWM Enabled Digital Pin
DCMotor::DCMotor(unsigned int pin)
{
    this->pin = pin;
    servo = new Servo();
    this->servo->attach(pin);
}

/// Clean up memory associated with the underlying servo instance.
DCMotor::~DCMotor() {
    delete servo;
}

/// Set the Speed of the motor from full reverse to full forward
/// uses the set MotorDirection to flip the sign on the speed input if configured as Reversed.
/// @param speed -1.0 to 1.0
void DCMotor::setSpeed(double speed)
{
    if (this->reversed)
        speed = -speed;
    int pwm = mapDoubleToPWM(speed);

    servo->writeMicroseconds(pwm);
}

/// Set the PWM duty cycle range that corresponds to full clockwise and full anti-clockwise rotation.
/// STOP is assumed to be the midpoint of the range.
/// these values should be found in the documentation for your specific Motor Controller
/// @param min minimum PWM duty cycle for the given Motor Controller
/// @param max maximum PWM duty cycle for the given Motor Controller
void DCMotor::setPWMPulseRange(int min, int max)
{
    this->PWM_MIN = min;
    this->PWM_MAX = max;
    this->PWM_ZERO = PWM_MIN + (PWM_MAX-PWM_MIN)/2;
}
