#ifndef STAR_H
#define STAR_H

#include <vector>
#include <string>

class Star{
public:
    /**
         * @brief construct and new Star object
         * @param starMass mass of the star in Msol
         * @param starAge age of the star in Gyr
         */
    Star(float starMass, float starAge);
    /**
         * @brief Star default constructor, initializes star mass and star age as same as sol
         */
    Star();

    /**
         * @brief setStarMass updates star mass
         * @param starMass new mass of star in Msol
         */
    void setStarMass(float starMass);
    /**
         * @brief setCurrentAge updates star age
         * @param starAge new age of star in Gsol
         */
    void setCurrentAge(float starAge);

    /**
         * @brief getStarMass gets mass of star
         * @return float star mass in Msol
         */
    float getStarMass()const;
    /**
         * @brief getStarMassSI gets mass of star
         * @return long double star mass in kg
         */
    long double getStarMassSI()const;
    /**
         * @brief getStarAge gets age of star
         * @return float star age in Gyr
         */
    float getStarAge()const;
    /**
         * @brief getStarClass gets class of star
         * @return string class of star
         */
    std::string getStarClass()const;
    /**
         * @brief getStarMaxAge gets maximum age the star can be
         * @return float maximum age of star in Gyr
         */
    float getStarMaxAge()const;
    /**
         * @brief getStarRadius gets radius of star
         * @return float star radius in Rsol
         */
    float getStarRadius()const;
    /**
         * @brief getStarRadiusSI gets radius of star
         * @return float star radius in km
         */
    float getStarRadiusSI()const;
    /**
         * @brief getStarLuminosity gets luminosity of star
         * @return float star luminosity in Lsol
         */
    float getStarLuminosity()const;
    /**
         * @brief getStarLuminositySI gets luminosity of star
         * @return long double star luminosity in W
         */
    long double getStarLuminositySI()const;
    /**
         * @brief getStarDensity gets density of star
         * @return float star density in Dsol
         */
    float getStarDensity()const;
    /**
         * @brief getStarDensitySI
         * @return float star density in g/cm^3
         */
    float getStarDensitySI()const;
    /**
         * @brief getStarTemperature gets temperature of star
         * @return float star temperature in K
         */
    float getStarTemperature()const;
    /**
         * @brief getStarHabital gets habital range of star
         * @return vector<float> first entry is lower bound (AU) second entry is upper bound (AU)
         */
    std::vector<float> getStarHabital()const;
    /**
         * @brief getStarHabitalSI gets habital range of star
         * @return vector<float> first entry is lower bound (million km) second entry is upper bound (million km)
         */
    std::vector<float> getStarHabitalSI()const;
    /**
         * @brief canStarSupportEarthLikeLife
         * @return true star can support earth-like life
         * @return false star cannot support earth-like life
         */
    bool canStarSupportEarthLikeLife()const;

    /**
         * @brief recalculateStar updates all the class variables
         */
    void recalculateStar();

private:
    //inputs
    float mass; //mass of star (Msol)
    float currentAge; //age of star (Gyr)

    //internal variables and outputs
    std::string starClass; //class of star
    float maximumAge; //maximum age of star (Gyr)
    float radius; //radius of star (Rsol)
    float luminocity; //luminosity of star (Lsol)
    float density; //density of star (Dsol)
    float temperature; //temperature of star (K)
    std::vector<float> habitalRange; //habital zone of star (AU)
    bool earthLikeLife; //can the star support earth-like life

    //internal functions
    /**
         * @brief determinStarClass determins star class
         * @return sring star class
         */
    std::string determinStarClass()const;
    /**
         * @brief calculateLuminosity calculates star luminosity
         * @return float star luminosity (Lsol)
         */
    float calculateLuminosity()const;
    /**
         * @brief calculateMaxAge calculates star maximum age
         * @return float star max age (Gyr)
         */
    float calculateMaxAge()const;
    /**
         * @brief calculateRadius calculates star radius
         * @return float star radius (Rsol)
         */
    float calculateRadius()const;
    /**
         * @brief calculateDensity calculates star density
         * @return float star density (Dsol)
         */
    float calculateDensity()const;
    /**
         * @brief calculateTemperature calculates star temperature
         * @return star temperature (K)
         */
    float calculateTemperature()const;
    /**
         * @brief generateHabitalZone generates habital zone for star
         * @return habital zone of star, first entry lower bound (AU), second entry upper bound (AU)
         */
    std::vector<float> generateHabitalZone()const;
    /**
         * @brief determineSutabilityForEarthLikeLife determins if star can support earth-like life
         * @return true star can support earth-like life
         * @return false star cannot support earth-like life
         */
    bool determineSutabilityForEarthLikeLife()const;
};

#endif // STAR_H
