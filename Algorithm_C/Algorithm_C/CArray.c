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



//========================================================================================
//                                      CArray
//========================================================================================


Array *creatCArray(int size)
{
    if (size < 1) {
        printf("array size not valuable");
    }
    Array *array = (Array *)malloc(sizeof(Array));
    array->array = (int *)malloc(sizeof(Array) * size);
    array->size = size;
    for (int i = 0; i < size; ++i) {
        array->array[i] = 0;
    }
    
    return array;
}

void insertCArrayData(Array *array, int position, int data)
{
    if (!array || !array->array || array->size == 0 || position < 0) {
        printf("array point null or position not correct\n");
        return;
    }
    array->array[position] = data;
}


void printCArray(Array *array)
{
    if (!array || array->size < 1) {
        printf("array point null \n");
        return;
    }
    printf("%d\n", array->size);
    for (int i = 0; i < array->size; ++i) {
        printf("%d  ", array->array[i]);
    }
    printf("\n");
    
}


void swapCArray(Array *array, int a, int b)
{
    if (!array || a < 0 || a > array->size - 1 || b < 0 || b > array->size - 1) {
        printf("array point null or data point null \n");
        return;
    }
    int temp = array->array[a];
    array->array[a] = array->array[b];
    array->array[b] = temp;
}

void reverseCArray(Array *array)
{
    if (!array || !array->array || array->size < 1) {
        printf("array is null \n");
        return;
    }
    for (int i = 0; i < array->size / 2; ++i) {
        swapCArray(array, i, array->size - i - 1);
    }
}


int getMinDataCArray(Array *array)
{
    if (!array || !array->array || array->size == 0) {
        printf("array point null\n");
        return -1;
    }
    int min = array->array[0];
    for (int i = 0; i < array->size; ++i) {
        if (min > array->array[i]) {
            min = array->array[i];
        }
    }
    return min;
}


int getMaxDataCArray(Array *array)
{
    if (!array || !array->array || array->size == 0) {
        printf("array point null\n");
        return -1;
    }
    int max = array->array[0];
    for (int i = 0; i < array->size; ++i) {
        if (max < array->array[i]) {
            max = array->array[i];
        }
    }
    return max;
}
