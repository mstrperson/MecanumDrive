//
// Created by Jason Cox on 3/1/25.
//

#ifndef MECANUMDRIVE_H
#define MECANUMDRIVE_H
#include "DCMotor.h"


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

    void drive(double x, double y, double t);

    void setPWMPulseRange(int min, int max);

};



#endif //MECANUMDRIVE_H
