/**
 * @file BuildingCounter.h
 * @author Ricardo Paz
 *
 * Counts the number of tiles in the simulation
 */

#ifndef CITY_BUILDINGCOUNTER_H
#define CITY_BUILDINGCOUNTER_H

#include "TileVisitor.h"

/**
 * Visit to count the building Tiles
 */
class BuildingCounter : public TileVisitor{
private:
    /// Buildings counter
    int mNumBuildings = 0;

public:
    /**
     * Get the number of buildings
     * @return Number of buildings
     */
    int GetNumBuildings() const { return mNumBuildings; }

    void VisitBuilding(TileBuilding* building) override;
};

#endif //CITY_BUILDINGCOUNTER_H
