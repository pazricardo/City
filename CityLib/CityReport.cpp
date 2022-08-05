/**
 * @file CityReport.cpp
 *
 * @author Charles B. Owen
 * @author Ricardo Paz
 */

#include "pch.h"
#include "CityReport.h"
#include "GrayCode.h"

using namespace std;

/// Length of keys that index report holders
const int KeyLength = 10;

/**
 * Constructor
 * @param city City this report is for. 
*/
CityReport::CityReport(City* city) : mCity(city)
{
}

/**
 * Add a new city report
 * @param report ReportHolder to add
*/
void CityReport::Add(std::shared_ptr<MemberReport> report)
{
    if(mNoReports)
    {
        // If there are no reports at all, we
        // make this be report #0
        mLast = 0;
        mNoReports = false;
    }
    else
    {
        mLast = GrayCode::Increment(mLast);
    }

    // Ensure the vector is large enough to handle
    // the newly added value.
    if(mReports.size() < mLast + 1)
    {
        mReports.resize(mLast + 1);
    }

    mReports[mLast] = report;
}

/**
 * Get an iterator for the end of the collection
 * @return Iter object at position past the end
 */
CityReport::Iter CityReport::end()
{
    if(mNoReports) {
        return Iter(this, 0);
    } else
    {
        return Iter(this, GrayCode::Increment(mLast));
    }
}