#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    static bool IsNumberBetween(int Number , int From , int To)
    {
        return (Number > From && Number < To);
    }
    static bool IsNumberBetween(float Number, float From, float To)
    {
        return (Number > From && Number < To);
    }
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number > From && Number < To);
    }
    static bool IsDateBetween(clsDate Date , clsDate DateFrom, clsDate DateTo)
    {
        if (clsDate::CompareDates(DateFrom, DateTo) == clsDate::enDateCompare::After)
        {
            clsDate::SwapDates(DateFrom, DateTo);
        }

        if (clsDate::CompareDates(Date , DateFrom ) == clsDate::enDateCompare::After && 
            clsDate::CompareDates(Date, DateTo) == clsDate::enDateCompare::Before)
            return 1;
        else
            return 0;
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter agane:")
    {
        int Number = 0;

        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }
        
        return Number;
    }
    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter agane:")
    {
        double Number = 0;

        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }

        return Number;
    }
   
    static int ReadPositiveIntNumber(string Message)
    {
        int Number = 0;

        do
        {
            cout << Message << endl;
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one:" << endl;
                cin >> Number;
            }

        } while (Number <= 0);
        return Number;
    }
    static double ReadPositiveDblNumber(string Message)
    {
        double Number = 0;

        do
        {
            cout << Message << endl;
            cin >> Number;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Number, Enter a valid one:" << endl;
                cin >> Number;
            }

        } while (Number <= 0);
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To,string ErrorMessage = "Number is not within range, enter again:")
    {
        int Number = ReadIntNumber();

        while (!(IsNumberBetween(Number, From, To)))
        {
            
            cout << ErrorMessage << endl;
            Number = ReadIntNumber();
        }

    }
    static double ReadDblNumberBetween(double From, double To,string ErrorMessage = "Number is not within range, enter again:")
    {
        double Number = ReadDblNumber();

        while (!(IsNumberBetween(Number, From, To)))
        {
            
            cout << ErrorMessage << endl;
            Number = ReadIntNumber();
        }

    }
    
    static bool IsValidDate(clsDate Date)
    {
       return clsDate::IsValidDate(Date);
    }
};

