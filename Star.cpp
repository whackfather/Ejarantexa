#include "Star.h"
#include "UnitConversion.h"
#include <vector>
#include <string>
#include <cmath>

// constructors
Star::Star(float starMass, float starAge){
    this->mass = starMass;
    this->currentAge = starAge;
    this->recalculateStar();
}

Star::Star(){
    this->mass = 1;
    this->currentAge = 4.5;
    this->recalculateStar();
}

// getters/setters
//      setters
void Star::setStarMass(float starMass){
    this->mass = starMass;
    this->recalculateStar();
}

void Star::setCurrentAge(float starAge){
    this->currentAge = starAge;
    this->recalculateStar();
}

//      getters
float Star::getStarMass()const{
    return this->mass;
}

long double Star::getStarMassSI()const{
    return relMass2SI(this->mass, 'S');
}

float Star::getStarAge()const{
    return this->currentAge;
}

std::string Star::getStarClass()const{
    return this->starClass;
}

float Star::getStarMaxAge()const{
    return this->maximumAge;
}

float Star::getStarRadius()const{
    return this->radius;
}

float Star::getStarRadiusSI()const{
    return relDist2SI(this->mass, 'S');
}

float Star::getStarLuminosity()const{
    return this->luminocity;
}

long double Star::getStarLuminositySI()const{
    return relLum2SI(this->luminocity, 'S');
}

float Star::getStarDensity()const{
    return this->density;
}

float Star::getStarDensitySI()const{
    return this->density * 1.408;
}

float Star::getStarTemperature()const{
    return this->temperature;
}

std::vector<float> Star::getStarHabital()const{
    return this->habitalRange;
}

std::vector<float> Star::getStarHabitalSI()const{
    std::vector<float> SIHabital = this->habitalRange;
    for(int i = 0; i < SIHabital.size(); i++){
        SIHabital[i] = relDist2SI(this->habitalRange[i], 'A');
    }
    return SIHabital;
}

bool Star::canStarSupportEarthLikeLife()const{
    return this->earthLikeLife;
}


// public functions
void Star::recalculateStar(){
    this->luminocity = this->calculateLuminosity();
    this->maximumAge = this->calculateMaxAge();
    this->radius = this->calculateRadius();
    this->density = this->calculateDensity();
    this->temperature = this->calculateTemperature();
    this->habitalRange = this->generateHabitalZone();
    this->earthLikeLife = this->determineSutabilityForEarthLikeLife();
    this->starClass = this->determinStarClass();
}


// private functions
std::string Star::determinStarClass()const{
    const int O_CUTOFF_UPPER = 95000;
    const int B_CUTOFF_UPPER = 33000;
    const int A_CUTOFF_UPPER = 10000;
    const int F_CUTOFF_UPPER = 7500;
    const int G_CUTOFF_UPPER = 6000;
    const int K_CUTOFF_UPPER = 5200;
    const int M_CUTOFF_UPPER = 3700;
    const int M_CUTOFF_LOWER = 2000;

    const int M_THING = 1700;
    const int K_THING = 1500;
    const int G_THING = 800;
    const int F_THING = 1500;
    const int A_THING = 2500;
    const int B_THING = 23000;
    const int O_THING = 62000;

    std::string letter("");
    std::string value("");

    bool validClass = 0;
    int thing1 = 0;
    int thing2 = 0;
    if (M_CUTOFF_UPPER > temperature && temperature > M_CUTOFF_LOWER)  {
        letter = "M";
        validClass = 1;
        thing1 = M_CUTOFF_UPPER;
        thing2 = M_THING;
    } else if (K_CUTOFF_UPPER > temperature && temperature > M_CUTOFF_UPPER) {
        letter = "K";
        validClass = 1;
        thing1 = K_CUTOFF_UPPER;
        thing2 = K_THING;
    } else if (G_CUTOFF_UPPER > temperature && temperature > K_CUTOFF_UPPER) {
        letter = "G";
        validClass = 1;
        thing1 = G_CUTOFF_UPPER;
        thing2 = G_THING;
    } else if (F_CUTOFF_UPPER > temperature && temperature > G_CUTOFF_UPPER) {
        letter = "F";
        validClass = 1;
        thing1 = F_CUTOFF_UPPER;
        thing2 = F_THING;
    } else if (A_CUTOFF_UPPER > temperature && temperature > F_CUTOFF_UPPER) {
        letter = "A";
        validClass = 1;
        thing1 = A_CUTOFF_UPPER;
        thing2 = A_THING;
    } else if (B_CUTOFF_UPPER > temperature && temperature > A_CUTOFF_UPPER) {
        letter = "B";
        validClass = 1;
        thing1 = B_CUTOFF_UPPER;
        thing2 = B_THING;
    } else if (O_CUTOFF_UPPER > temperature && temperature > B_CUTOFF_UPPER) {
        letter = "O";
        validClass = 1;
        thing1 = O_CUTOFF_UPPER;
        thing2 = O_THING;
    }

    if (validClass) {
        float temp = 1 - (temperature - thing1) /thing2;

        // shift and round
        temp = temp * 100;
        temp = std::floor(temp);
        temp = temp / 10;

        value = std::to_string(temp) + "V";
    }

    if (mass >= 0.075 && mass <= 100) {
        return letter + value;
    } else {
        return "NA";
    }
}

float Star::calculateLuminosity()const{
    if (this->mass < 0.43) {
        return 0.23 * std::pow(this->mass, 2.3);
    } else if (this->mass < 2) {
        return std::pow(this->mass, 4);
    } else {
        return 1.4 * std::pow(this->mass, 3.5);
    }
}

float Star::calculateMaxAge()const{
    return (this->mass / this->luminocity) *  10;
}

float Star::calculateRadius()const{
    if (this->mass < 1) {
        return std::pow(this->mass, 0.8);
    } else {
        return std::pow(this->mass, 0.57);
    }
}

float Star::calculateDensity()const{
    return this->mass / std::pow(this->radius, 3);
}

float Star::calculateTemperature()const{
    return std::pow((this->luminocity / std::pow(this->radius, 2)), 0.25) * 5776;
}

std::vector<float> Star::generateHabitalZone()const{
    std::vector<float> temp = {std::sqrt(this->luminocity / 1.1), std::sqrt(this->luminocity / 0.53)};
    return temp;
}

bool Star::determineSutabilityForEarthLikeLife()const{
    if (this->mass >= 0.5 && this->mass <= 1.4) {
        if (this->currentAge >= 3.5) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
