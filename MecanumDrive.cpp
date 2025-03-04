//
// Created by Jason Cox on 3/1/25.
//

#include "MecanumDrive.h"
#include <Arduino.h>

MecanumDrive::MecanumDrive(
    unsigned int leftFrontPin,
    unsigned int rightFrontPin,
    unsigned int rightBackPin,
    unsigned int leftBackPin)
{
    leftFront = new DCMotor(leftFrontPin);
    rightFront = new DCMotor(rightFrontPin);
    rightFront->setOrientation(REVERSED);
    leftBack = new DCMotor(leftBackPin);
    rightBack = new DCMotor(rightBackPin);
    rightBack->setOrientation(REVERSED);
}

///
/// @param x Horizontal Strafe Component
/// @param y Vertical Strafe Component
/// @param t Rotational Bias
void MecanumDrive::drive(double x, double y, double t)
{
    double angle = atan2(y, x);
    double magnitude = sqrt(pow(x, 2) + pow(y, 2));

    if (magnitude < 0.05) magnitude = 0;
    if (magnitude > 1.0) magnitude = 1.0;

    double y1 = sin(angle + PI/4) * magnitude + t;
    double y2 = sin(angle - PI/4) * magnitude + t;

    if (abs(y1) > 1.0 || abs(y2) > 1.0)
    {
        double scaleFactor = max(abs(y1), abs(y2));
        y1 *= 1/scaleFactor;
        y2 *= 1/scaleFactor;
    }

    leftFront->setSpeed(y1);
    rightBack->setSpeed(y1);
    rightFront->setSpeed(y2);
    leftBack->setSpeed(y2);
}

void MecanumDrive::setPWMPulseRange(int min, int max) {
    leftFront->setPWMPulseRange(min, max);
    rightFront->setPWMPulseRange(min, max);
    leftBack->setPWMPulseRange(min, max);
    rightBack->setPWMPulseRange(min, max);
}
