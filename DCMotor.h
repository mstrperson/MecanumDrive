//
// Created by Jason Cox on 3/1/25.
//

#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "Servo.h"

enum MotorDirection {
    FORWARD,
    REVERSED
};

class DCMotor
{
    unsigned int pin;
    Servo* servo;
    int PWM_MIN   = 1500;
    int PWM_MAX   = 2500;
    int PWM_ZERO  = PWM_MIN + (PWM_MAX-PWM_MIN)/2;
    bool reversed = false;

    [[nodiscard]] int mapDoubleToPWM(double percentage);

    public:
    explicit DCMotor(unsigned int pin);

    ~DCMotor();

    ///
    /// @param speed -1.0 to 1.0
    void setSpeed(double speed);
    void stop() { setSpeed(0); }
    void setOrientation(MotorDirection direction) { this->reversed = direction == REVERSED; }
    void setPWMPulseRange(int min, int max);
};


#endif //DCMOTOR_H
