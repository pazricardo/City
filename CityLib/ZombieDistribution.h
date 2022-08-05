/**
 * @file ZombieDistribution.h
 * @author Ricardo Paz
 *
 * Distributes Zombies between hive, landscape, and building tiles
 */

#ifndef CITY_ZOMBIEDISTRIBUTION_H
#define CITY_ZOMBIEDISTRIBUTION_H

#include "TileVisitor.h"
#include <random>

/**
 * Visitor Class to distribute zombies between tiles
 */
class ZombieDistribution : public TileVisitor {
private:
    /// Total amount of zombies at the tile
    int mZombiesAmount;

    /// list of the neighboring landscape tiles
    std::vector<TileLandscape*> mLandscapeTiles;

    /// Random number generator
    std::mt19937 mRandom;

public:
    ZombieDistribution(int zombies);

    void VisitBuilding(TileBuilding* building) override;

    void VisitLandscape(TileLandscape* landscape) override;

    int Distribute();

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

};

#endif //CITY_ZOMBIEDISTRIBUTION_H
