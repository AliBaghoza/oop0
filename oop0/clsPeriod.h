#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = DateTo;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }

     bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }
    static bool isDateInPeriod(clsDate Date, clsPeriod Period)
    {
        return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
    }
    static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
    {
        int count = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return count;
        while (clsDate::CompareDates(Period1.StartDate, Period1.EndDate) != clsDate::enDateCompare::Equal)
        {
            if (isDateInPeriod(Period1.StartDate, Period2))
            {
                count++;
                Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
            }
            else
            {
                Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
            }

        }
        return count;
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};
