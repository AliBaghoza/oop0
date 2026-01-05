#include <iostream>
#include "clsPeriod.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
int main()

{

    int arr[100];
    int arrLength = 0;
    clsUtil::AddArrayElement(5, arr, arrLength);

    //arr[100] = clsUtil::ReadArray(arrLength);
    //clsUtil::PrintArray(arr,arrLength);

    cout << clsInputValidate::IsNumberBetween(5, 8, 8) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate() , clsDate(1,1,2026),clsDate(1,12,2026)) << endl;

    
    return 0;
}