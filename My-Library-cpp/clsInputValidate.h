#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }
    static bool IsNumberBetween(short Number, short From, short To)
    {
        return (Number >= From && Number <= To);
    }
    static bool IsNumberBetween(float Number, float From, float To)
    {
        return (Number >= From && Number <= To);
    }
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From && Number <= To);
    }
    static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
    {
        if (clsDate::CompareDates(DateFrom, DateTo) == clsDate::enDateCompare::After)
        {
            clsDate::SwapDates(DateFrom, DateTo);
        }

        if (clsDate::CompareDates(Date, DateFrom) == clsDate::enDateCompare::After &&
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
    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter agane:")
    {
        float Number = 0;

        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
        }

        return Number;
    }

    static int ReadPositiveIntNumber()
    {
        int Number = 0;

        do
        {
            Number = ReadIntNumber();

        } while (Number <= 0);
        return Number;
    }
    static double ReadPositiveDblNumber()
    {
        double Number = 0;

        do
        {
            Number = ReadDblNumber();

        } while (Number <= 0);
        return Number;
    }
    static float ReadPositiveFloatNumber()
    {
        float Number = 0;

        do
        {
            Number = ReadDblNumber();

        } while (Number <= 0);
        return Number;
    }


    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again:")
    {
        int Number = ReadIntNumber();

        while (!(IsNumberBetween(Number, From, To)))
        {

            cout << ErrorMessage << endl;
            Number = ReadIntNumber();
        }
        return Number;
    }
    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again:")
    {
        double Number = ReadDblNumber();

        while (!(IsNumberBetween(Number, From, To)))
        {

            cout << ErrorMessage << endl;
            Number = ReadIntNumber();
        }
        return Number;
    }
    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, enter again:")
    {
        short Number = ReadDblNumber();

        while (!(IsNumberBetween(Number, From, To)))
        {

            cout << ErrorMessage << endl;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static void ReadArray(int array[100], short& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        arrLength = ReadPositiveIntNumber();

        cout << "\nEnter array elements: \n";
        int Number = 0;
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "]:";
            Number = ReadIntNumber();
            array[i] = Number;

        }

    }
    static void ReadArray(double array[100], short& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        arrLength = ReadPositiveIntNumber();

        cout << "\nEnter array elements: \n";
        double Number = 0;
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "]:";
            Number = ReadDblNumber();
            array[i] = Number;

        }

    }
    static void ReadArray(string array[100], short& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        arrLength = ReadPositiveIntNumber();

        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "]:";
            cin >> array[i];
        }

    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string  S1 = "";
        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, S1);
        return S1;
    }

};

