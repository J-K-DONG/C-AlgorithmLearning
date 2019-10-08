//
//  CArray.c
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/8.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include "CArray.h"

//========================================================================================
//                                     数组工具函数
//========================================================================================

/*  取数组的最大值    */
int getMaxData(int *array, int len)
{
    int max = array[0];
    for(int i = 1; i < len; ++i)
    {
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

/*  取数组的最小值   */
int getMinData(int *array, int len)
{
    int min = array[0];
    for(int i = 1; i < len; ++i)
    {
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

/*  用指针交换两个元素  */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int *array, int len)
{
    //    printf("%d\n", length);
    for(int i = 0; i < len; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

