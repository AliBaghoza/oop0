
#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }
    
    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static void PrintArray(int array[100], short length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << array[i] << " ";

        }
        cout << endl;
    }
    static void PrintArray(float array[100], short length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << array[i] << " ";

        }
        cout << endl;
    }
    static void PrintArray(double array[100], short length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << array[i] << " ";

        }
        cout << endl;
    }
    static void PrintArray(string array[100], short length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << array[i] << " ";

        }
        cout << endl;
    }
   

    static int MiniNumberInArray(int arr[100], short arrLength)
    {
        short min = 0;


        min = arr[0];

        for (int i = 1; i < arrLength; i++)
        {

            if (arr[i] < min)
                min = arr[i];

        }

        return min;
    }
    static double MiniNumberInArray(double arr[100], short arrLength)
    {
        double min = 0;


        min = arr[0];

        for (int i = 1; i < arrLength; i++)
        {

            if (arr[i] < min)
                min = arr[i];

        }

        return min;
    }
    static float  MiniNumberInArray(float arr[100], short arrLength)
    {
        float min = 0;


        min = arr[0];

        for (int i = 1; i < arrLength; i++)
        {

            if (arr[i] < min)
                min = arr[i];

        }

        return min;
    }

    static int NaxNumberInArray(int array[100], short length)
    {
        int max = 0;
        for (int i = 0; i < length; i++)
        {

            if (array[i] > max)
                max = array[i];

        }

        return max;
    }
    static double NaxNumberInArray(double array[100], short length)
    {
        double max = 0;
        for (int i = 0; i < length; i++)
        {

            if (array[i] > max)
                max = array[i];

        }

        return max;
    }


    static void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        //its a new element so we need to add the length by 1
        arrLength++;
        arr[arrLength - 1] = Number;
    }

    static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }

    static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        /*This function will search for a number in array and return
       its index, or return -1 if it does not exists*/
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;// and return the index
        }
        //if you reached here, this means the number is not found
        return -1;
    }

    static bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }


    static enum enchekPrimeNum { Prime, notPrime };

    static enchekPrimeNum ChekPrimeNum(int number)
    {
        int num = round(number / 2);

        for (int i = 2; i <= num; i++)
        {
            if (number % i == 0)
                return enchekPrimeNum::notPrime;

        }

        return enchekPrimeNum::Prime;

    }

    static void ResetScreen() {
        system("color F");
        system("cls");
    }

};

