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
        float getStarMass();
        /**
         * @brief getStarAge gets age of star
         * @return float star age in Gyr
         */
        float getStarAge();
        /**
         * @brief getStarClass gets class of star
         * @return string class of star
         */
        std::string getStarClass();
        /**
         * @brief getStarMaxAge gets maximum age the star can be
         * @return float maximum age of star in Gyr
         */
        float getStarMaxAge();
        /**
         * @brief getStarRadius gets radius of star
         * @return float star radius in Rsol
         */
        float getStarRadius();
        /**
         * @brief getStarDensity gets density of star
         * @return float star density in Dsol
         */
        float getStarDensity();
        /**
         * @brief getStarTemperature gets temperature of star
         * @return float star temperature in K
         */
        float getStarTemperature();
        /**
         * @brief getStarHabital gets habitual range of star
         * @return vector<float> first entry is lower bound (AU) second entry is upper bound (AU)
         */
        std::vector<float> getStarHabital();
        /**
         * @brief canStarSupportEarthLikeLife
         * @return true star can support earth-like life
         * @return false star cannot support earth-like life
         */
        bool canStarSupportEarthLikeLife();

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
         * @brief updateValues updates all the class variables
         */
        void updateValues();
        /**
         * @brief calculateLuminosity calculates star luminosity
         * @return float star luminosity (Lsol)
         */
        float calculateLuminosity();
        /**
         * @brief calculateMaxAge calculates star maximum age
         * @return float star max age (Gyr)
         */
        float calculateMaxAge();
        /**
         * @brief calculateRadius calculates star radius
         * @return float star radius (Rsol)
         */
        float calculateRadius();
        /**
         * @brief calculateDensity calculates star density
         * @return float star density (Dsol)
         */
        float calculateDensity();
        /**
         * @brief calculateTemperature calculates star temperature
         * @return star temperature (K)
         */
        float calculateTemperature();
        /**
         * @brief generateHabitalZone generates habital zone for star
         * @return habital zone of star, first entry lower bound (AU), second entry upper bound (AU)
         */
        std::vector<float> generateHabitalZone();
        /**
         * @brief determineSutabilityForEarthLikeLife determins if star can support earth-like life
         * @return true star can support earth-like life
         * @return false star cannot support earth-like life
         */
        bool determineSutabilityForEarthLikeLife();
};

#endif // STAR_H
