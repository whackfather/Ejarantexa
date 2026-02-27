#ifndef UNITCONVERSION_H
#define UNITCONVERSION_H

/**
 * @brief relMass2SI converts a relative mass to kg
 * @param relativeMass multiple of mass
 * @param reference identification char (S: sol, E: earth, M: luna)
 * @return [long double] mass in kg
 */
long double relMass2SI(float relativeMass, char reference);

/**
 * @brief relDist2SI converts a relative distance to km
 * @param relativeDistance multiple of distance
 * @param reference identification char (S: radius of sol, E: radius of earth, M: radius of luna, A: AU)
 * @return [long double] distance in km
 */
long double relDist2SI(float relativeDistance, char reference);

/**
 * @brief relLum2SI converts a relative luminosity to W
 * @param relativeLuminosity multiple of luminosity
 * @param reference identificatio char (S: sol)
 * @return [long double] luminosity in W
 */
long double relLum2SI(float relativeLuminosity, char reference);

/**
 * @brief relGrav2SI converts a relative gravity to m/s^2
 * @param relativeGravity multiple of gravity
 * @param reference identification char (S: sol, E: earth, M: luna)
 * @return [float] gravity in m/s^2
 */
float relGrav2SI(float relativeGravity, char reference);

/**
 * @brief relEscVel2SI converts a relative escape velocity to km/s
 * @param relativeEscapeVelocity multiple of escape velocity
 * @param reference identification char (E: earth)
 * @return [float] escape velocity in km/s
 */
float relEscVel2SI(float relativeEscapeVelocity, char reference);

/**
 * @brief k2c converts kelvin to celcius
 * @param temp temperature in K
 * @return [float] temperature in C
 */
float k2c(float temp);

/**
 * @brief atm2kPa converts atm to kPa
 * @param press pressure in atm
 * @return [float] pressure in kPa
 */
float atm2kPa(float press);

#endif // UNITCONVERSION_H
