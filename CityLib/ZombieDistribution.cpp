/**
 * @file ZombieDistribution.cpp
 * @author Ricardo Paz
 */

#include "pch.h"
#include "ZombieDistribution.h"
#include "TileBuilding.h"
#include "TileLandscape.h"
#include "TileHive.h"


/**
 * Constructor
 * @param zombies
 */
ZombieDistribution::ZombieDistribution(int zombies) : mZombiesAmount(zombies)
{

}

/**
 * Infecting the building tile
 * @param building
 */
void ZombieDistribution::VisitBuilding(TileBuilding* building)
{
    if(building->Infect()) // Can return a bool, true if newly infected, false if already infected
    {
        mZombiesAmount--;
    }
}

/**
 * Infecting the landscape tile
 * @param landscape
 */
void ZombieDistribution::VisitLandscape(TileLandscape* landscape)
{
    mLandscapeTiles.push_back(landscape);
    landscape->Infect();
}

/**
 * Distribution of the zombies
 * @return mZombiesAmount
 */
int ZombieDistribution::Distribute()
{
    if(mLandscapeTiles.size() == 0)
    {
        return mZombiesAmount;
    }
    std::uniform_int_distribution<int> random(0, mLandscapeTiles.size() - 1);
    if(mZombiesAmount < 0)
    {
        return 0;
    }
    for (auto zombie = 0; zombie<mZombiesAmount; zombie++)
    {
        mLandscapeTiles[random(GetRandom())]->ReceiveZombies(1);
    }
    mZombiesAmount = 0;
    return mZombiesAmount;
}
