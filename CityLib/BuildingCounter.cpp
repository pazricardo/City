/**
 * @file BuildingCounter.cpp
 * @author Ricardo Paz
 */

#include "pch.h"
#include "BuildingCounter.h"

/**
 * Visit a TileBuilding object
 * @param building Building we are visiting
 */
void BuildingCounter::VisitBuilding(TileBuilding* building)
{
    mNumBuildings++;
}