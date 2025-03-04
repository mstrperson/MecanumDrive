//
// Created by Jason Cox on 3/1/25.
//

#ifndef MECANUMDRIVE_H
#define MECANUMDRIVE_H
#include "DCMotor.h"

/// Mecanum Drive Library
/// Uses 4 DCMotor objects for each of the 4 wheels.
class MecanumDrive
{
    DCMotor* leftFront;
    DCMotor* rightFront;
    DCMotor* rightBack;
    DCMotor* leftBack;


    public:
    MecanumDrive(
        unsigned int leftFrontPin,
        unsigned int rightFrontPin,
        unsigned int rightBackPin,
        unsigned int leftBackPin);

    /// Does all the math to write drive outputs given Joystick Inputs
    /// @param x Left-Right Strafe Component
    /// @param y Forward-Backward Strafe Component
    /// @param t Rotational Bias (Turn in Place)
    void drive(double x, double y, double t);

    void setPWMPulseRange(int min, int max);

    void setMotorOrientations(
        MotorDirection leftFront,
        MotorDirection rightFront,
        MotorDirection rightBack,
        MotorDirection leftBack);
};



#endif //MECANUMDRIVE_H
