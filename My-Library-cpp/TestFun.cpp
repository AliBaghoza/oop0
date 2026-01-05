#include <iostream>
#include "clsPeriod.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
int main()

{

    int arr[100];
    short arrLength = 5;
   clsInputValidate::ReadArray(arr , arrLength);
   

    
    clsUtil::PrintArray(arr, arrLength);

    cout << clsInputValidate::IsNumberBetween(5, 8, 8) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate() , clsDate(1,1,2026),clsDate(1,12,2026)) << endl;

   // UpDate clsInputValidate.h & clsUtil.h
    return 0;
}