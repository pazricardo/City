/**
 * @file HiveVisitor.h
 * @author Ricardo Paz
 *
 * Visits the Hive tile to Release the Virus
 */

#ifndef CITY_HIVEVISITOR_H
#define CITY_HIVEVISITOR_H

#include "TileVisitor.h"

/**
 * Visitor Class that visits the Hive tile to release the virus
 */
class HiveVisitor : public TileVisitor{
private:
    // Item location in the city
    int   mX = 0;     ///< X location for the center of the item
    int   mY = 0;     ///< Y location for the center of the item
    TileHive* mHive;  ///< hive we are visiting

public:
    void VisitHive(TileHive* hive) override;

    /**
     * Returns the x location of the hive
     * @return mX
     */
    double GetX() {return mX;}

    /**
     * Returns the y location of the hive
     * @return mY
     */
    double GetY() {return mY;}

    void ReleaseVirus();



};

#endif //CITY_HIVEVISITOR_H
