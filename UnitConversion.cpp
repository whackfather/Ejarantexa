#include "UnitConversion.h"

long double relMass2SI(float relativeMass, char reference){
    long double M_SOL = 1989000000000000000000000000000.0; //kg
    long double M_EARTH = 5972000000000000000000000.0; //kg
    long double M_LUNA =  73420000000000000000000.0; //kg

    if (reference == 'S') {
        return relativeMass * M_SOL;
    } else if (reference == 'M') {
        return relativeMass * M_LUNA;
    } else {
        return relativeMass * M_EARTH;
    }
}

long double relDist2SI(float relativeDistance, char reference){
    const long double R_SOL = 696340; //km
    const long double R_EARTH = 6370.11; //km
    const long double R_LUNA = 1736.4; //km
    const long double AU = 149600000; //km

    if (reference == 'S') {
        return relativeDistance * R_SOL;
    } else if (reference == 'E') {
        return relativeDistance * R_EARTH;
    } else if (reference == 'M') {
        return relativeDistance * R_LUNA;
    } else {
        return relativeDistance * AU;
    }
}

long double relLum2SI(float relativeLuminosity, char reference){
    long double L_SOL = 382800000000000000000000000.0; //W

    return relativeLuminosity * L_SOL;
}

float relGrav2SI(float relativeGravity, char reference){
    const float G_SOL = 274; //m/s^2
    const float G_EARTH = 9.81; //m/s^2
    const float G_LUNA = 1.625; //m/s^2

    if (reference == 'S') {
        return relativeGravity * G_SOL;
    } else if (reference == 'M') {
        return relativeGravity * G_LUNA;
    } else {
        return relativeGravity * G_EARTH;
    }
}

float relEscVel2SI(float relativeEscapeVelocity, char reference){
    const float V_EARTH = 11.2; //km/s

    return relativeEscapeVelocity * V_EARTH;
}

float k2c(float temp){
    const float CONVERSION = 273;

    return temp - CONVERSION;
}

float atm2kPa(float press){
    const float CONVERSION = 101.3;

    return press * CONVERSION;
}
