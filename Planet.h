#ifndef PLANET_H
#define PLANET_H

#include "Star.h"
#include <string>
#include <vector>

class Planet{
    public:
        /**
         * @brief Planet constructor (all inputs)
         * @param planetStar [Star] star planet orbits
         * @param planetMass [float] mass of planet (MEarth)
         * @param planetCMF [float] percentage of planet mass in core (% 0-1)
         * @param planetAxialTilt [float] axial tilt of planet (degrees)
         * @param planetAlbedo [float] how reflective planet is (0 perfect absorber, 1 perfect reflector)
         * @param planetGreenhouseEffect [float] how strong the greenhouse effect is on planet (0-500)
         * @param planetRotationPeriod [float] how long it takes planet to rotate (Earth hrs)
         * @param planetSemiMajorAxis [float] how far from star planet orbits (AU)
         * @param planetEccentricity [float] how eliptical planet's orbit is (0 orbit is circle, 1 orbit is parabola)
         * @param planetInclination [float] inclination of planet's orbit (degrees)
         * @param atmPress [float] atmpspheric pressure of planet (atm)
         * @param atmO [float] percent of atmosphere that is oxygen (% 0-1)
         * @param atmCO2 [float] percent of atmosphere that is carbon dioxide (% 0-1)
         * @param atmAr [float] percent of atmosphere that is argon (% 0-1)
         */
        Planet(Star planetStar, float planetMass, float planetCMF, float planetAxialTilt, float planetAlbedo, float planetGreenhouseEffect, float planetRotationPeriod, float planetSemiMajorAxis, float planetEccentricity, float planetInclination, float atmPress, float atmO, float atmCO2, float atmAr);
        /**
         * @brief Planet constructor (physical characteristics inputs, all others default to earth values)
         * @param planetStar [Star] star planet orbits
         * @param planetMass [float] mass of planet (MEarth)
         * @param planetCMF [float] percentage of planet mass in core (% 0-1)
         * @param planetAxialTilt [float] axial tilt of planet (degrees)
         * @param planetAlbedo [float] how reflective planet is (0 perfect absorber, 1 perfect reflector)
         * @param planetGreenhouseEffect [float] how strong the greenhouse effect is on planet (0-500)
         */
        Planet(Star planetStar, float planetMass, float planetCMF, float planetAxialTilt, float planetAlbedo, float planetGreenhouseEffect);
        /**
         * @brief Planet constructor (orbital characteristics inputs, all others default to earth values)
         * @param planetStar [Star] star planet orbits
         * @param planetRotationPeriod [float] how long it takes planet to rotate (Earth hrs)
         * @param planetSemiMajorAxis [float] how far from star planet orbits (AU)
         * @param planetEccentricity [float] how eliptical planet's orbit is (0 orbit is circle, 1 orbit is parabola)
         * @param planetInclination [float] inclination of planet's orbit (degrees)
         */
        Planet(Star planetStar, float planetRotationPeriod, float planetSemiMajorAxis, float planetEccentricity, float planetInclination);
        /**
         * @brief Planet constructor (atmospheric characteristics inputs, all others default to earth values)
         * @param planetStar [Star] star planet orbits
         * @param atmPress [float] atmpspheric pressure of planet (atm)
         * @param atmO [float] percent of atmosphere that is oxygen (% 0-1)
         * @param atmCO2 [float] percent of atmosphere that is carbon dioxide (% 0-1)
         * @param atmAr [float] percent of atmosphere that is argon (% 0-1)
         */
        Planet(Star planetStar, float atmPress, float atmO, float atmCO2, float atmAr);
        /**
         * @brief Planet constructor (only star and rotation period initialized, all other values set to earth values)
         * @param planetStar [Star] star planet orbits
         * @param planetRotationPeriod [float] how long it takes planet to rotate (Earth hrs)
         */
        Planet(Star planetStar, float planetRotationPeriod);
        /**
         * @brief Planet constructor (only star is initialized, all other values initialized to earth values)
         * @param planetStar [Star] star planet orbits
         */
        Planet(Star planetStar);

        /**
         * @brief changeStar change planet star
         * @param newStar [Star] new star
         */
        void changeStar(Star newStar);
        /**
         * @brief setMass change planet mass
         * @param m [float] mass of planet (MEarth)
         */
        void setMass(float m);
        /**
         * @brief setCMF change planet Core Mass Fraction
         * @param CMF [float] percentage of planet mass in core (% 0-1)
         */
        void setCMF(float CMF);
        /**
         * @brief setAxialTilt change planet axial tilt
         * @param planetAxialTilt [float] axial tilt of planet (degrees)
         */
        void setAxialTilt(float planetAxialTilt);
        /**
         * @brief setAlbedo change planet albedo
         * @param planetAlbedo [float] how reflective planet is (0 perfect absorber, 1 perfect reflector)
         */
        void setAlbedo(float planetAlbedo);
        /**
         * @brief setGreenhouseEffect change planet greenhouse effect
         * @param planetGreenhouseEffect [float] how strong the greenhouse effect is on planet (0-500)
         */
        void setGreenhouseEffect(float planetGreenhouseEffect);
        /**
         * @brief setRotationPeriod change planet rotation period
         * @param hours [float] how long it takes planet to rotate (Earth hrs)
         */
        void setRotationPeriod(float hours);
        /**
         * @brief setSemiMajorAxis change planet semi-major axis
         * @param distanceFromStar [float] how far from star planet orbits (AU)
         */
        void setSemiMajorAxis(float distanceFromStar);
        /**
         * @brief setEccentricity change planet eccentricity
         * @param planetEccentricity [float] how eliptical planet's orbit is (0 orbit is circle, 1 orbit is parabola)
         */
        void setEccentricity(float planetEccentricity);
        /**
         * @brief setInlcination change planet inclination
         * @param planetInlcination [float] inclination of planet's orbit (degrees)
         */
        void setInlcination(float planetInlcination);
        /**
         * @brief setAtmPress change planet atmospheric pressure
         * @param atmPress [float] atmpspheric pressure of planet (atm)
         */
        void setAtmPress(float atmPress);
        /**
         * @brief setAtmO change atmospheric oxygen percent
         * @param atmO [float] percent of atmosphere that is oxygen (% 0-1)
         */
        void setAtmO(float atmO);
        /**
         * @brief setAtmCO2 change atmospheric carbon dioxide percent
         * @param atmCO2 [float] percent of atmosphere that is carbon dioxide (% 0-1)
         */
        void setAtmCO2(float atmCO2);
        /**
         * @brief setAtmAr change atmospheric argon percent
         * @param atmAr [float] percent of atmosphere that is argon (% 0-1)
         */
        void setAtmAr(float atmAr);
        /**
         * @brief setPhysicalCharacteristics change planet physical characteristics
         * @param m [float] mass of planet (MEarth)
         * @param CMF [float] axial tilt of planet (degrees)
         * @param planetAxialTilt [float] axial tilt of planet (degrees)
         * @param planetAlbedo [float] how reflective planet is (0 perfect absorber, 1 perfect reflector)
         * @param planetGreenhouseEffect [float] how strong the greenhouse effect is on planet (0-500)
         */
        void setPhysicalCharacteristics(float m, float CMF, float planetAxialTilt, float planetAlbedo, float planetGreenhouseEffect);
        /**
         * @brief setOrbitalCharacteristics change planet orbital characteristics
         * @param hours [float] how long it takes planet to rotate (Earth hrs)
         * @param planetSemiMajorAxis [float] how far from star planet orbits (AU)
         * @param planetEccentricity [float] how eliptical planet's orbit is (0 orbit is circle, 1 orbit is parabola)
         * @param planetInclination [float] inclination of planet's orbit (degrees)
         */
        void setOrbitalCharacteristics(float hours, float planetSemiMajorAxis, float planetEccentricity, float planetInclination);
        /**
         * @brief setAtmosphericCharacteristics change planet atmospheric characteristics
         * @param atmPress [float] atmpspheric pressure of planet (atm)
         * @param atmO [float] percent of atmosphere that is oxygen (% 0-1)
         * @param atmCO2 [float] percent of atmosphere that is carbon dioxide (% 0-1)
         * @param atmAr [float] percent of atmosphere that is argon (% 0-1)
         */
        void setAtmosphericCharacteristics(float atmPress, float atmO, float atmCO2, float atmAr);

        Star getStar();
        float getMass();
        float getMasskg();
        float getCMF();
        float getAxialTilt();
        float getAlbedo();
        float getGreenhouseEffect();
        float getRotationPeriod();
        float getSemiMajorAxis();
        float getSemiMajorAxisMilkm();
        float getEccentricity();
        float getInclination();
        float getAtmosphericPressure();
        float getAtmosphericPressurekPa();
        float getAtmPercentOxygen();
        float getAtmOxygenPartialPressure();
        float getAtmPercentCarbonDioxide();
        float getAtmCarbonDioxidePartialPressure();
        float getAtmPercentArgon();
        float getAtmArgonPartialPressure();
        float getDensity();
        float getRadius();
        float getRadiuskm();
        float getGravity();
        float getGravitymps2();
        float getEscapeVelocity();



    private:
        // inputs
        Star homeStar; //star that planet orbits
        float mass; //mass of planet in MEarth
        float coreMassFraction; //percentage of planet's mass contained within the core (%)
        float axialTilt; //planet's axial tilt (degrees)
        float albedo; //bond albedo of planet (1 perfect reflector, 0 perfect absorber)
        float greenhouseEffect; //strength of greenhouse effect on planet (0-500)
        float rotationPeriod; //how long it takes for planet to rotate (Earth hrs)
        float semiMajorAxis; //where the planet orbits relative to star (AU)
        float eccentricity; //how eliptical the orbit is (0-1)
        float inclination; //the inclination of the planet's orbit (degrees)
        float atmosphericPressure; //air pressure of planet (atm)
        float atmPercentOxygen; //percentage of the atmosphere that is oxygen (%)
        float atmPercentCarbonDioxide; //percentage of the atmosphere that is carbon dioxide (%)
        float atmPercentArgon; //percentage of the atmosphere that is argon (%)

        // internal variables and outputs
        float density; //density of planet (g/cm^3)
        float radius; //radius of planet (REarth)
        float gravity; //strenght of gravity on planet (g)
        float escapeVelocity; //escape velocity of planet (VEarth)
        std::string rotationDirection; //direction of rotation for planet (prograde: earth, retrograde: opposite of earth, undefined: tilt of 90 degrees)
        std::vector<float> tropics; //range of planet's tropics (first entry is lowerbound, second entry is upperbound) (degrees north/south)
        std::vector<float> polarCircles; //range of planet's polar circles (first entry is lowerbound, second entry is upperbound) (degrees north/south)
        float avgSurfaceTemp; //average surface temperature of planet (K)
        float periapsis; //closest distance planet will get to star (AU)
        float apoapsis; //farthest distance planet will get to star (AU)
        float orbitalPeriod; //how long it takes planet to orbit star (local days)
        std::string orbitalDirection; //direction of orbit for planet ((prograde: earth, retrograde: opposite of earth, undefined: orbit of 90 degrees) (should always be prograde for earth-like life)
        float atmPercentNitrogen; //percentage of the atmosphere that is nitrogen (%)
        float atmosphericDensity; //density of planet's atmosphere (kg/m^3)
        int numAtmoshpereCirculationCells; //number of circulation cells in planet's atmosphere
        std::vector<std::vector<int>> cellBoundaries; //list of cell boundary, each item will have a length of 2 with the first entry being the lowerbound and the second the upperbound of the cell (degrees north/south)

};

#endif // PLANET_H
