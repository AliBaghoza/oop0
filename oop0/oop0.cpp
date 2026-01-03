#include <iostream>
#include "clsPeriod.h"
#include"clsUtil.h"
int main()

{

    int arr[100];
    int arrLength = 0;
    clsUtil::AddArrayElement(5, arr, arrLength);

    //arr[100] = clsUtil::ReadArray(arrLength);
    clsUtil::PrintArray(arr,arrLength);

    return 0;
}