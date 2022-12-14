/**
 * @file CityReport.h
 *
 * @author Charles B. Owen
 * @author Ricardo Paz
 *
 * The city report is generated by the members of the city.
 * It is a collection of objects of type MemberReport.
 */

#pragma once

#include "GrayCode.h"
#include <memory>
#include <vector>

class City;
class MemberReport;

/**
 * The city report is generated by the members of the city.
 * It is a collection of objects of type MemberReport.
*/
class CityReport
{
private:
    /// The city this report is for
    City* mCity;

protected:
    /// Vector containing all city reports in Gray Code order
    std::vector<std::shared_ptr<MemberReport>> mReports;

    /// Indication that the collection is empty
    bool mNoReports = true;

    /// Last added location in the collection
    /// Only valid if mNoReports is false, so we initialize
    /// it with an arbitrary value.
    unsigned int mLast = 47;

public:
    explicit CityReport(City* city);

    void Add(std::shared_ptr<MemberReport> report);

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * @param cityReport The city report we are iterating over
         * @param pos Position in the collection
         */
        Iter(CityReport* cityReport, unsigned int pos) : mCityReport(cityReport), mPos(pos) {}

        /**
         * Compare two iterators
         * @param other The other iterator we are comparing to
         * @return  true if this position is not equal to the other position
        */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<MemberReport> operator *() const { return mCityReport->mReports[mPos]; }

        /**
         * Increment the iterator
         * @return Reference to this iterator */
        const Iter& operator++()
        {
            mPos = GrayCode::Increment(mPos);
            return *this;
        }

    private:
        CityReport* mCityReport;   ///< City we are iterating over
        unsigned int mPos;       ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    Iter begin() { return Iter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    Iter end();
};

