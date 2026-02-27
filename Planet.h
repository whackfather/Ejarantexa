#ifndef PLANET_H
#define PLANET_H

#include "Star.h"
#include <string>
#include <vector>

class Planet{
public:
    /**
         * @brief Planet constructor (all inputs)
         * @param planetStar [Star*] star planet orbits
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
         * @param atmO2 [float] percent of atmosphere that is oxygen (% 0-1)
         * @param atmCO2 [float] percent of atmosphere that is carbon dioxide (% 0-1)
         * @param atmAr [float] percent of atmosphere that is argon (% 0-1)
         */
    Planet(Star* planetStar, float planetMass, float planetCMF, float planetAxialTilt, float planetAlbedo, float planetGreenhouseEffect, float planetRotationPeriod, float planetSemiMajorAxis, float planetEccentricity, float planetInclination, float atmPress, float atmO2, float atmCO2, float atmAr);
    /**
         * @brief Planet constructor (only star and rotation period initialized, all other values set to earth values)
         * @param planetStar [Star*] star planet orbits
         * @param planetRotationPeriod [float] how long it takes planet to rotate (Earth hrs)
         */
    Planet(Star* planetStar, float planetRotationPeriod);
    /**
         * @brief Planet constructor (only star is initialized, all other values initialized to earth values)
         * @param planetStar [Star*] star planet orbits
         */
    Planet(Star* planetStar);

    /**
         * @brief changeStar change planet star
         * @param newStar [Star*] new star
         */
    void changeStar(Star* newStar);
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
         * @brief setAtmO2 change atmospheric oxygen percent
         * @param atmO2 [float] percent of atmosphere that is oxygen (% 0-1)
         */
    void setAtmO2(float atmO2);
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
         * @param atmO2 [float] percent of atmosphere that is oxygen (% 0-1)
         * @param atmCO2 [float] percent of atmosphere that is carbon dioxide (% 0-1)
         * @param atmAr [float] percent of atmosphere that is argon (% 0-1)
         */
    void setAtmosphericCharacteristics(float atmPress, float atmO2, float atmCO2, float atmAr);

    /**
         * @brief getStar
         * @return [Star*] star associated with planet
         */
    Star* getStar()const;
    /**
         * @brief getMass
         * @return [float] mass of planet (MEarth)
         */
    float getMass()const;
    /**
         * @brief getMassSI
         * @return [float] mass of planet (kg)
         */
    float getMassSI()const;
    /**
         * @brief getCMF
         * @return [float] percentage of planet mass in core (% 0-1)
         */
    float getCMF()const;
    /**
         * @brief getAxialTilt
         * @return [float] axial tilt of planet in degrees
         */
    float getAxialTilt()const;
    /**
         * @brief getAlbedo
         * @return [float] albedo of planet (0-1, 0 perfect absorber, 1 perfect reflector)
         */
    float getAlbedo()const;
    /**
         * @brief getGreenhouseEffect
         * @return [float] strength of greenhouse effect on planet (0-500)
         */
    float getGreenhouseEffect()const;
    /**
         * @brief getRotationPeriod
         * @return [float] time it takes planet to rotate (Earth hrs)
         */
    float getRotationPeriod()const;
    /**
         * @brief getSemiMajorAxis
         * @return [float] distance planet orbits from star (AU)
         */
    float getSemiMajorAxis()const;
    /**
         * @brief getSemiMajorAxisSI
         * @return [long double] distance planet orbits from star (million km)
         */
    long double getSemiMajorAxisSI()const;
    /**
         * @brief getEccentricity
         * @return [float] how eliptical the orbit is (0-1, 0 orbit is circle, 1 orbit is parabola)
         */
    float getEccentricity()const;
    /**
         * @brief getInclination
         * @return [float] orbit inclination (degrees)
         */
    float getInclination()const;
    /**
         * @brief getAtmosphericPressure
         * @return [float] atmosphere pressure at sea level (atm)
         */
    float getAtmosphericPressure()const;
    /**
         * @brief getAtmosphericPressureSI
         * @return [float] atmosphere pressure at sea level (kPa)
         */
    float getAtmosphericPressureSI()const;
    /**
         * @brief getAtmPercentOxygen
         * @return [float] percentage of atmosphere that is oxygen (% 0-1)
         */
    float getAtmPercentOxygen()const;
    /**
         * @brief getAtmOxygenPartialPressure
         * @return [float] PP of Oxygen in atmosphere (atm)
         */
    float getAtmOxygenPartialPressure()const;
    /**
         * @brief getAtmOxygenPartialPressureSI
         * @return [float] PP of Oxygen in atmosphere (kPa)
         */
    float getAtmOxygenPartialPressureSI()const;
    /**
         * @brief getAtmPercentCarbonDioxide
         * @return [float] percentage of atmosphere that is Carbon Dioxide (% 0-1)
         */
    float getAtmPercentCarbonDioxide()const;
    /**
         * @brief getAtmCarbonDioxidePartialPressure
         * @return [float] PP of Carbon Dioxide in atmosphere (atm)
         */
    float getAtmCarbonDioxidePartialPressure()const;
    /**
         * @brief getAtmCarbonDioxidePartialPressureSI
         * @return [float] PP of Carbon Dioxide in atmosphere (kPa)
         */
    float getAtmCarbonDioxidePartialPressureSI()const;
    /**
         * @brief getAtmPercentArgon
         * @return [float] percentage of atmosphere that is Argon (% 0-1)
         */
    float getAtmPercentArgon()const;
    /**
         * @brief getAtmArgonPartialPressure
         * @return [float] PP of Argon in atmosphere (atm)
         */
    float getAtmArgonPartialPressure()const;
    /**
         * @brief getAtmArgonPartialPressureSI
         * @return [float] PP of Argon in atmosphere (kPa)
         */
    float getAtmArgonPartialPressureSI()const;
    /**
         * @brief getDensity
         * @return [float] planet density (g/cm^3)
         */
    float getDensity()const;
    /**
         * @brief getRadius
         * @return [float] planet radius (REarth)
         */
    float getRadius()const;
    /**
         * @brief getRadiusSI
         * @return [float] planet radius (km)
         */
    float getRadiusSI()const;
    /**
         * @brief getGravity
         * @return [float] planet gravity (g)
         */
    float getGravity()const;
    /**
         * @brief getGravitySI
         * @return [float] planet gravity (m/s^2)
         */
    float getGravitySI()const;
    /**
         * @brief getEscapeVelocity
         * @return [float] speed needed to exit planet orbit (VEarth)
         */
    float getEscapeVelocity()const;
    /**
         * @brief getEscapeVelocitySI
         * @return [float] speed needed to exit planet orbit (km/s)
         */
    float getEscapeVelocitySI()const;
    /**
         * @brief getRotationDirection
         * @return [std::string] direction of planet rotation (prograde: earth, retrograde: opposite of earth, undefined: tilt of 90 degrees)
         */
    std::string getRotationDirection()const;
    /**
         * @brief getTropicsBounds
         * @return [std::vector<float>] bounds of planet's tropics (first entry is lowerbound, second entry is upperbound) (degrees north/south)
         */
    std::vector<float> getTropicsBounds()const;
    /**
         * @brief getPolarCirclesBounds
         * @return [std::vector<float>] bounds of the planet's polar circles (first entry is lowerbound, second entry is upperbound) (degrees north/south)
         *
         */
    std::vector<float> getPolarCirclesBounds()const;
    /**
         * @brief getAvgSurfaceTemp
         * @return [float] average temperature at planet surface (K)
         */
    float getAvgSurfaceTemp()const;
    /**
         * @brief getAvgSurfaceTempSI
         * @return [float] average temperature at planet surface (C)
         */
    float getAvgSurfaceTempSI()const;
    /**
         * @brief getPeriapsis
         * @return [float] closest distance planet will get to star (AU)
         */
    float getPeriapsis()const;
    /**
         * @brief getPeriapsisSI
         * @return [float] closest distance planet will get to star (million km)
         */
    float getPeriapsisSI()const;
    /**
         * @brief getApoapsis
         * @return [float] farthest distance planet will get from star (AU)
         */
    float getApoapsis()const;
    /**
         * @brief getApoapsisSI
         * @return [float] farthest distance planet will get from star (million km)
         */
    float getApoapsisSI()const;
    /**
         * @brief getOrbitalPeriod
         * @return [float] how long the planet's year is (local days)
         */
    float getOrbitalPeriod()const;
    /**
         * @brief getOrbitalPeriodSIyrs
         * @return [float] how long the planet's year is (Earth years)
         */
    float getOrbitalPeriodSIyrs()const;
    /**
         * @brief getOrbitalPeriodSIdys
         * @return [float] how long the planet's year is (Earth days)
         */
    float getOrbitalPeriodSIdys()const;
    /**
         * @brief getOrbitalDirection
         * @return [std::string] direction of orbit for planet ((prograde: earth, retrograde: opposite of earth, undefined: orbit of 90 degrees) (should always be prograde for earth-like life)
         */
    std::string getOrbitalDirection()const;
    /**
         * @brief getAtmPercentNitrogen
         * @return [float] percentage of atmosphere that is Nitrogen (% 0-1)
         */
    float getAtmPercentNitrogen()const;
    /**
         * @brief getAtmNitrogenPartialPressure
         * @return [float] PP of Nitrogen in atmosphere (atm)
         */
    float getAtmNitrogenPartialPressure()const;
    /**
         * @brief getAtmNitrogenPartialPressureSI
         * @return [float] PP of Nitrogen in atmosphere (kPa)
         */
    float getAtmNitrogenPartialPressureSI()const;
    /**
         * @brief getAtmDensity
         * @return [float] density of atmosphere (kg/m^3)
         */
    float getAtmDensity()const;
    /**
         * @brief getNumCirculationCells
         * @return [int] number of circulation cells in atmosphere
         */
    int getNumCirculationCells()const;
    /**
         * @brief getCirculationCellBounds
         * @return [std::vector<std::vector<float>>] list of cell boundary, each item will have a length of 2 with the first entry being the lowerbound and the second the upperbound of the cell (degrees north/south)
         */
    std::vector<std::vector<float>> getCirculationCellBounds()const;

    /**
         * @brief recalculatePlanet updates values for planet
         */
    void recalculatePlanet();

    /**
         * @brief findSightDist calculates how far you can see given the hight you are looking from
         * @param observationHeight [float] how high you are looking from (m)
         * @return [float] how far you can see (m)
         */
    float findSightDist(float observationHeight)const;



private:
    // inputs
    Star* homeStar; //star that planet orbits
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
    int numAtmosphereCirculationCells; //number of circulation cells in planet's atmosphere
    std::vector<std::vector<float>> cellBoundaries; //list of cell boundary, each item will have a length of 2 with the first entry being the lowerbound and the second the upperbound of the cell (degrees north/south)

    // private functions
    /**
         * @brief calculateDensity
         * @return [float] planet radius (REarth)
         */
    float calculateDensity()const;
    /**
         * @brief calculateRadius
         * @return [float] planet radius (REarth)
         */
    float calculateRadius()const;
    /**
         * @brief calculateGravity
         * @return [float] planet gravity (g)
         */
    float calculateGravity()const;
    /**
         * @brief calculateEscapeVelocity
         * @return [float] speed needed to exit planet orbit (VEarth)
         */
    float calculateEscapeVelocity()const;
    /**
         * @brief calculateRotationDirection
         * @return [std::string] direction of planet rotation (prograde: earth, retrograde: opposite of earth, undefined: tilt of 90 degrees)
         */
    std::string calculateRotationDirection()const;
    /**
         * @brief calculateTropics
         * @return [std::vector<float>] bounds of planet's tropics (first entry is lowerbound, second entry is upperbound) (degrees north/south)
         */
    std::vector<float> calculateTropics()const;
    /**
         * @brief calculatePolarCircles
         * @return [std::vector<float>] bounds of the planet's polar circles (first entry is lowerbound, second entry is upperbound) (degrees north/south)
         */
    std::vector<float> calculatePolarCircles()const;
    /**
         * @brief calculateAvgSurfaceTemp
         * @return [float] average temperature at planet surface (K)
         */
    float calculateAvgSurfaceTemp()const;
    /**
         * @brief calculatePeriapsis
         * @return [float] closest distance planet will get to star (AU)
         */
    float calculatePeriapsis()const;
    /**
         * @brief calculateApoapsis
         * @return [float] farthest distance planet will get from star (AU)
         */
    float calculateApoapsis()const;
    /**
         * @brief calculateOrbitalPeriod
         * @return [float] how long the planet's year is (local days)
         */
    float calculateOrbitalPeriod()const;
    /**
         * @brief calculateOrbitalDirection
         * @return [std::string] direction of orbit for planet ((prograde: earth, retrograde: opposite of earth, undefined: orbit of 90 degrees)
         */
    std::string calculateOrbitalDirection()const;
    /**
         * @brief calculateAtmPercentNitrogen
         * @return [float] percentage of atmosphere that is Nitrogen (% 0-1)
         */
    float calculateAtmPercentNitrogen()const;
    /**
         * @brief calculateAtmoshpericDensity
         * @return [float] density of atmosphere (kg/m^3)
         */
    float calculateAtmoshpericDensity()const;
    /**
         * @brief calculateNumAtmosphericCirculationCells
         * @return [int] number of circulation cells in atmosphere
         */
    int calculateNumAtmosphericCirculationCells()const;
    /**
         * @brief calculateCellBoundaries
         * @return [std::vector<std::vector<float>>] list of cell boundary, each item will have a length of 2 with the first entry being the lowerbound and the second the upperbound of the cell (degrees north/south)
         */
    std::vector<std::vector<float>> calculateCellBoundaries()const;

};

#endif // PLANET_H
