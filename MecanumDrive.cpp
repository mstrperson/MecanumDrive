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

MecanumDrive::~MecanumDrive()
{
    delete leftFront;
    delete rightFront;
    delete rightBack;
    delete leftBack;
}

void MecanumDrive::drive(double x, double y, double t)
{
    double angle = atan2(y, x);
    double magnitude = sqrt(pow(x, 2) + pow(y, 2));

    if (magnitude < 0.05) magnitude = 0;
    if (magnitude > 1.0) magnitude = 1.0;

    double y1 = sin(angle + PI/4) * magnitude;
    double y2 = sin(angle - PI/4) * magnitude;

    double lf = y1 + t,
           lb = y2 + t,
           rf = y2 - t,
           rb = y1 - t;

    double m = max(abs(lf), max(abs(lb), max(abs(rf), abs(rb))));

    if (m > 1.0)
    {
        lf /= m;
        lb /= m;
        rf /= m;
        rb /= m;
    }

    leftFront->setSpeed(lf);
    rightBack->setSpeed(rb);
    rightFront->setSpeed(rf);
    leftBack->setSpeed(lb);
}

void MecanumDrive::setPWMPulseRange(int min, int max) {
    leftFront->setPWMPulseRange(min, max);
    rightFront->setPWMPulseRange(min, max);
    leftBack->setPWMPulseRange(min, max);
    rightBack->setPWMPulseRange(min, max);
}

void MecanumDrive::setMotorOrientations(
    MotorDirection leftFront,
    MotorDirection rightFront,
    MotorDirection rightBack,
    MotorDirection leftBack)
{
    this->leftFront->setOrientation(leftFront);
    this->rightFront->setOrientation(rightFront);
    this->rightBack->setOrientation(rightBack);
    this->leftBack->setOrientation(leftBack);
}
