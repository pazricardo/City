/**
 * @file ResetVisitor.h
 * @author Ricardo Paz
 *
 * Resets the tile we visit
 */

#ifndef CITY_RESETVISITOR_H
#define CITY_RESETVISITOR_H

#include "TileVisitor.h"
#include "TileBuilding.h"
#include "TileLandscape.h"
#include "TileHive.h"

/**
 * Visitor class to reset a tile
 */
class ResetVisitor : public TileVisitor{
private:

public:
    /**
     * Resets the building tile
     * @param building
     */
    void VisitBuilding(TileBuilding* building) override {building->Reset();}

    /**
     * Resets the landscape tile
     * @param landscape
     */
    void VisitLandscape(TileLandscape* landscape) override {landscape->Reset();}

    /**
     * Resets the hive tile
     * @param hive
     */
    void VisitHive(TileHive* hive) override {hive->Reset();}


};

#endif //CITY_RESETVISITOR_H
