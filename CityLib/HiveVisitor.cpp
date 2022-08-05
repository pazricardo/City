/**
 * @file HiveVisitor.cpp
 * @author Ricardo Paz
 */

#include "pch.h"
#include "HiveVisitor.h"
#include "TileHive.h"


/**
 * Visit a TileHive object
 * @param hive hive we are visiting
 */
void HiveVisitor::VisitHive(TileHive* hive)
{
    mX = hive->GetX();
    mY = hive->GetY();
    mHive = hive;
}

/**
 * Releases the virus from the hive we visit
 */
void HiveVisitor::ReleaseVirus()
{
    mHive->ReleaseTVirus();
}