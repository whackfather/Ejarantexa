#define _USE_MATH_DEFINES
#include "planet.h"
#include "Star.h"
#include "UnitConversion.h"
#include <vector>
#include <string>
#include <cmath>

// constructors
Planet::Planet(Star *planetStar, float planetMass, float planetCMF, float planetAxialTilt, float planetAlbedo, float planetGreenhouseEffect, float planetRotationPeriod, float planetSemiMajorAxis, float planetEccentricity, float planetInclination, float atmPress, float atmO2, float atmCO2, float atmAr){
    this->homeStar = planetStar;
    this->mass = planetMass;
    this->coreMassFraction = planetCMF;
    this->axialTilt = planetAxialTilt;
    this->albedo = planetAlbedo;
    this->greenhouseEffect = planetGreenhouseEffect;
    this->rotationPeriod = planetRotationPeriod;
    this->semiMajorAxis = planetSemiMajorAxis;
    this->eccentricity = planetEccentricity;
    this->inclination = planetInclination;
    this->atmosphericPressure = atmPress;
    this->atmPercentOxygen = atmO2;
    this->atmPercentCarbonDioxide = atmCO2;
    this->atmPercentArgon = atmAr;

    this->recalculatePlanet();
}

Planet::Planet(Star *planetStar, float planetRotationPeriod){
    this->homeStar = planetStar;
    this->rotationPeriod = planetRotationPeriod;

    //initialize all other values to earth values
    this->mass = 1;
    this->coreMassFraction = .334;
    this->axialTilt = 23.5;
    this->albedo = 0.29;
    this->greenhouseEffect = 1;
    this->semiMajorAxis = 1;
    this->eccentricity = 0.0167;
    this->inclination = 0;
    this->atmosphericPressure = 1;
    this->atmPercentOxygen = 0.2095;
    this->atmPercentCarbonDioxide = 0.0004;
    this->atmPercentArgon = 0.0093;

    this->recalculatePlanet();
}

Planet::Planet(Star *planetStar){
    this->homeStar = planetStar;

    //initialize all other values to earth values
    this->mass = 1;
    this->coreMassFraction = .334;
    this->axialTilt = 23.5;
    this->albedo = 0.29;
    this->greenhouseEffect = 1;
    this->rotationPeriod = 24;
    this->semiMajorAxis = 1;
    this->eccentricity = 0.0167;
    this->inclination = 0;
    this->atmosphericPressure = 1;
    this->atmPercentOxygen = 0.2095;
    this->atmPercentCarbonDioxide = 0.0004;
    this->atmPercentArgon = 0.0093;

    this->recalculatePlanet();
}


// getters/setters
//      setters
void Planet::changeStar(Star *newStar){
    this->homeStar = newStar;

    this->recalculatePlanet();
}
void Planet::setMass(float m){
    this->mass = m;

    this->recalculatePlanet();
}
void Planet::setCMF(float CMF){
    this->coreMassFraction = CMF;

    this->recalculatePlanet();
}
void Planet::setAxialTilt(float planetAxialTilt){
    this->axialTilt = planetAxialTilt;

    this->recalculatePlanet();
}
void Planet::setAlbedo(float planetAlbedo){
    this->albedo = planetAlbedo;

    this->recalculatePlanet();
}
void Planet::setGreenhouseEffect(float planetGreenhouseEffect){
    this->greenhouseEffect = planetGreenhouseEffect;

    this->recalculatePlanet();
}
void Planet::setRotationPeriod(float hours){
    this->rotationPeriod = hours;

    this->recalculatePlanet();
}
void Planet::setSemiMajorAxis(float distanceFromStar){
    this->semiMajorAxis = distanceFromStar;

    this->recalculatePlanet();
}
void Planet::setEccentricity(float planetEccentricity){
    this->eccentricity = planetEccentricity;

    this->recalculatePlanet();
}
void Planet::setInlcination(float planetInlcination){
    this->inclination = planetInlcination;

    this->recalculatePlanet();
}
void Planet::setAtmPress(float atmPress){
    this->atmosphericPressure = atmPress;

    this->recalculatePlanet();
}
void Planet::setAtmO2(float atmO2){
    this->atmPercentOxygen = atmO2;

    this->recalculatePlanet();
}
void Planet::setAtmCO2(float atmCO2){
    this->atmPercentCarbonDioxide = atmCO2;

    this->recalculatePlanet();
}
void Planet::setAtmAr(float atmAr){
    this->atmPercentArgon = atmAr;

    this->recalculatePlanet();
}
void Planet::setPhysicalCharacteristics(float m, float CMF, float planetAxialTilt, float planetAlbedo, float planetGreenhouseEffect){
    this->mass = m;
    this->coreMassFraction = CMF;
    this->axialTilt = planetAxialTilt;
    this->albedo = planetAlbedo;
    this->greenhouseEffect = planetGreenhouseEffect;

    this->recalculatePlanet();
}
void Planet::setOrbitalCharacteristics(float hours, float planetSemiMajorAxis, float planetEccentricity, float planetInclination){
    this->rotationPeriod = hours;
    this->semiMajorAxis = planetSemiMajorAxis;
    this->eccentricity = planetEccentricity;
    this->inclination = planetInclination;

    this->recalculatePlanet();
}
void Planet::setAtmosphericCharacteristics(float atmPress, float atmO2, float atmCO2, float atmAr){
    this->atmosphericPressure = atmPress;
    this->atmPercentOxygen = atmO2;
    this->atmPercentCarbonDioxide = atmCO2;
    this->atmPercentArgon = atmAr;

    this->recalculatePlanet();
}

//      getters
Star* Planet::getStar()const{
    return this->homeStar;
}
float Planet::getMass()const{
    return this->mass;
}
float Planet::getMassSI()const{
    return relMass2SI(this->mass, 'E');
}
float Planet::getCMF()const{
    return this->coreMassFraction;
}
float Planet::getAxialTilt()const{
    return this->axialTilt;
}
float Planet::getAlbedo()const{
    return this->albedo;
}
float Planet::getGreenhouseEffect()const{
    return this->greenhouseEffect;
}
float Planet::getRotationPeriod()const{
    return this->rotationPeriod;
}
float Planet::getSemiMajorAxis()const{
    return this->semiMajorAxis;
}
long double Planet::getSemiMajorAxisSI()const{
    return relDist2SI(this->semiMajorAxis, 'A');
}
float Planet::getEccentricity()const{
    return this->eccentricity;
}
float Planet::getInclination()const{
    return this->inclination;
}
float Planet::getAtmosphericPressure()const{
    return this->atmosphericPressure;
}
float Planet::getAtmosphericPressureSI()const{
    return atm2kPa(this->atmosphericPressure);
}
float Planet::getAtmPercentOxygen()const{
    return this->atmPercentOxygen;
}
float Planet::getAtmOxygenPartialPressure()const{
    return this->atmosphericPressure * this->atmPercentOxygen;
}
float Planet::getAtmOxygenPartialPressureSI()const{
    return atm2kPa(this->atmosphericPressure * this->atmPercentOxygen);
}
float Planet::getAtmPercentCarbonDioxide()const{
    return this->atmPercentCarbonDioxide;
}
float Planet::getAtmCarbonDioxidePartialPressure()const{
    return this->atmosphericPressure * this->atmPercentCarbonDioxide;
}
float Planet::getAtmCarbonDioxidePartialPressureSI()const{
    return atm2kPa(this->atmosphericPressure * this->atmPercentCarbonDioxide);
}
float Planet::getAtmPercentArgon()const{
    return this->atmPercentArgon;
}
float Planet::getAtmArgonPartialPressure()const{
    return this->atmosphericPressure * this->atmPercentArgon;
}
float Planet::getAtmArgonPartialPressureSI()const{
    return atm2kPa(this->atmosphericPressure * this->atmPercentArgon);
}
float Planet::getDensity()const{
    return this->density;
}
float Planet::getRadius()const{
    return this->radius;
}
float Planet::getRadiusSI()const{
    return relDist2SI(this->radius, 'E');
}
float Planet::getGravity()const{
    return this->gravity;
}
float Planet::getGravitySI()const{
    return relGrav2SI(this->gravity, 'E');
}
float Planet::getEscapeVelocity()const{
    return this->escapeVelocity;
}
float Planet::getEscapeVelocitySI()const{
    return relEscVel2SI(this->escapeVelocity, 'E');
}
std::string Planet::getRotationDirection()const{
    return this->rotationDirection;
}
std::vector<float> Planet::getTropicsBounds()const{
    return this->tropics;
}
std::vector<float> Planet::getPolarCirclesBounds()const{
    return this->polarCircles;
}
float Planet::getAvgSurfaceTemp()const{
    return this->avgSurfaceTemp;
}
float Planet::getAvgSurfaceTempSI()const{
    return k2c(this->avgSurfaceTemp);
}
float Planet::getPeriapsis()const{
    return this->periapsis;
}
float Planet::getPeriapsisSI()const{
    return relDist2SI(this->periapsis, 'A');
}
float Planet::getApoapsis()const{
    return this->apoapsis;
}
float Planet::getApoapsisSI()const{
    return relDist2SI(this->apoapsis, 'A');
}
float Planet::getOrbitalPeriod()const{
    return this->orbitalPeriod;
}
float Planet::getOrbitalPeriodSIyrs()const{
    return std::sqrt(std::pow(this->semiMajorAxis, 3) / this->homeStar->getStarMass());
}
float Planet::getOrbitalPeriodSIdys()const{
    return std::sqrt(std::pow(this->semiMajorAxis, 3) / this->homeStar->getStarMass()) * 365.256;
}
std::string Planet::getOrbitalDirection()const{
    return this->orbitalDirection;
}
float Planet::getAtmPercentNitrogen()const{
    return this->atmPercentNitrogen;
}
float Planet::getAtmNitrogenPartialPressure()const{
    return this->atmosphericPressure * this->atmPercentNitrogen;
}
float Planet::getAtmNitrogenPartialPressureSI()const{
    return atm2kPa(this->atmosphericPressure * this->atmPercentNitrogen);
}
float Planet::getAtmDensity()const{
    return this->atmosphericDensity;
}
int Planet::getNumCirculationCells()const{
    return this->numAtmosphereCirculationCells;
}
std::vector<std::vector<float>> Planet::getCirculationCellBounds()const{
    return this->cellBoundaries;
}


// public functions
void Planet::recalculatePlanet(){
    density = this->calculateDensity();
    radius = this->calculateRadius();
    gravity = this->calculateGravity();
    escapeVelocity = this->calculateEscapeVelocity();
    rotationDirection = this->calculateRotationDirection();
    tropics = this->calculateTropics();
    polarCircles = this->calculatePolarCircles();
    avgSurfaceTemp = this->calculateAvgSurfaceTemp();
    periapsis = this->calculatePeriapsis();
    apoapsis = this->calculateApoapsis();
    orbitalPeriod = this->calculateOrbitalPeriod();
    orbitalDirection = this->calculateOrbitalDirection();
    atmPercentNitrogen = this->calculateAtmPercentNitrogen();
    atmosphericDensity = this->calculateAtmoshpericDensity();
    numAtmosphereCirculationCells = this->calculateNumAtmosphericCirculationCells();
    cellBoundaries = this->calculateCellBoundaries();
}

float Planet::findSightDist(float observationHeight)const{
    //calculate sight distance
    return std::sqrt(2 * radius * 6371000 * observationHeight + std::pow(observationHeight, 2)) / 1000;
}


// private functions
//      physical characteristics
float Planet::calculateDensity()const{
    if (mass > 0.6) {
        return 5.51 * std::pow(mass, 0.189) / std::pow(1.07 - 0.21 * coreMassFraction, 3);
    } else if ((5.51 * std::pow(mass, 0.189) / std::pow(1.07 - 0.21 * coreMassFraction, 3)) > 3.5 + 4.37 * coreMassFraction) {
        return 5.51 * std::pow(mass, 0.189) / std::pow(1.07 - 0.21 * coreMassFraction, 3);
    } else {
        return 3.5 * 4.37 * coreMassFraction;
    }
}

float Planet::calculateRadius()const{
    return std::pow(mass / (density / 5.51), 1.0 / 3.0);
}

float Planet::calculateGravity()const{
    return mass / std::pow(radius, 2);
}

float Planet::calculateEscapeVelocity()const{
    return std::sqrt(mass / radius);
}

std::string Planet::calculateRotationDirection()const{
    if (axialTilt == 90) {
        return "Undefined";
    } else if ((axialTilt >= 0) && (axialTilt < 90)) {
        return "Prograde";
    } else {
        return "Retrograde";
    }
}

std::vector<float> Planet::calculateTropics()const{
    std::vector<float> temp = {0, 0};
    if (axialTilt < 90) {
        temp[1] = axialTilt;
    } else {
        temp[1] = 180-axialTilt;
    }
    return temp;
}

std::vector<float> Planet::calculatePolarCircles()const{
    std::vector<float> temp = {90, 90};
    if (axialTilt < 90) {
        temp[0] = 90 - axialTilt;
    } else {
        temp[0] = 90 - (180 - axialTilt);
    }
    return temp;
}

float Planet::calculateAvgSurfaceTemp()const{
    const float STEFAN_BOLTZMAN_CONSTANT = 0.000056703;
    long double luminosity = 3846000000000000000000000000000000.0 * homeStar->getStarLuminosity();
    long double dist2Star = this->getSemiMajorAxisSI() * (100.0 * 1000.0); //convert distance to star to cm
    float tempGreenhouse = greenhouseEffect * 0.5841;
    long double numerator = std::sqrt((1 - albedo) * luminosity / (16.0 * M_PI * STEFAN_BOLTZMAN_CONSTANT));
    double denomenator = std::sqrt(dist2Star);
    double tempEffective = std::sqrt(numerator) / denomenator;
    double tempEquivalent = std::pow(tempEffective, 4.0) * (1 + (3.0 * tempGreenhouse / 4.0));
    float tempSurface = tempEquivalent / 0.9;

    return std::pow(tempSurface, 1.0 / 4.0);
}

//      orbital characteristics
float Planet::calculatePeriapsis()const{
    return semiMajorAxis * (1 - eccentricity);
}

float Planet::calculateApoapsis()const{
    return semiMajorAxis * (1 + eccentricity);
}

float Planet::calculateOrbitalPeriod()const{
    float earthDays = std::sqrt(std::pow(this->semiMajorAxis, 3) / this->homeStar->getStarMass()) * 365.256;
    return earthDays * 24 / rotationPeriod;
}

std::string Planet::calculateOrbitalDirection()const{
    if (inclination > 90) {
        return "Retrograde";
    } else if (inclination < 90) {
        return "Prograde";
    } else {
        return "Undefined";
    }
}

float Planet::calculateAtmPercentNitrogen()const{
    return 1 - (atmPercentOxygen + atmPercentCarbonDioxide + atmPercentArgon);
}

float Planet::calculateAtmoshpericDensity()const{
    const float O2_MOLECULAR_WEIGHT = 0.0319988; //kg/mol
    const float CO2_MOLECULAR_WEIGHT = 0.04401; //kg/mol
    const float AR_MOLECULAR_WEIGHT = 0.03995; //kg/mol
    const float N2_MOLECULAR_WEIGHT = 0.02801; //kg/mol

    float weightO2InAtm = atmPercentOxygen * O2_MOLECULAR_WEIGHT;
    float weightCO2InAtm = atmPercentCarbonDioxide * CO2_MOLECULAR_WEIGHT;
    float weightArInAtm = atmPercentArgon * AR_MOLECULAR_WEIGHT;
    float weightN2InAtm = atmPercentNitrogen * N2_MOLECULAR_WEIGHT;
    float atmWeight = weightO2InAtm + weightCO2InAtm + weightArInAtm + weightN2InAtm;
    float pres = this->getAtmosphericPressureSI();
    return (pres * atmWeight) / (avgSurfaceTemp * 8.3145);
}

int Planet::calculateNumAtmosphericCirculationCells()const{
    if (rotationPeriod >= 48) {
        return 1;
    } else if ((rotationPeriod >= 6) && (rotationPeriod < 48)) {
        return 3;
    } else if ((rotationPeriod >= 3) && (rotationPeriod < 6)) {
        return 7;
    } else if ((rotationPeriod > 0) && (rotationPeriod < 3)) {
        return 5;
    } else {
        return 0;
    }
}

std::vector<std::vector<float>> Planet::calculateCellBoundaries()const{
    std::vector<std::vector<float>> temp;
    if (numAtmosphereCirculationCells == 1) {
        temp.push_back({0, 90});
    } else if (numAtmosphereCirculationCells == 3) {
        temp.push_back({0, 30});
        temp.push_back({30, 60});
        temp.push_back({60, 90});
    } else if (numAtmosphereCirculationCells == 7) {
        temp.push_back({0, 24});
        temp.push_back({24, 27});
        temp.push_back({27, 31});
        temp.push_back({31, 41});
        temp.push_back({41, 58});
        temp.push_back({58, 71});
        temp.push_back({71, 90});
    } else if (numAtmosphereCirculationCells == 5) {
        temp.push_back({0, 23});
        temp.push_back({23, 30});
        temp.push_back({30, 47});
        temp.push_back({47, 56});
        temp.push_back({56, 90});
    }
    return temp;
}
