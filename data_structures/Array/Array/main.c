//
//  main.c
//  Array
//
//  Created by JK DONG on 2019/9/30.
//  Copyright © 2019 JK DONG. All rights reserved.
//


#include "array_header.h"


Array *creatArray(int size)
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

void insertArrayData(Array *array, int position, int data){
    if (!array || !array->array || array->size == 0 || position < 0) {
        printf("array point null or position not correct\n");
        return;
    }
    array->array[position] = data;
}


void printArray(Array *array)
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


void swap(Array *array, int a, int b){
    if (!array || a < 0 || a > array->size - 1 || b < 0 || b > array->size - 1) {
        printf("array point null or data point null \n");
        return;
    }
    int temp = array->array[a];
    array->array[a] = array->array[b];
    array->array[b] = temp;
}

void reverseArray(Array *array){
    if (!array || !array->array || array->size < 1) {
        printf("array is null \n");
        return;
    }
    for (int i = 0; i < array->size / 2; ++i) {
        swap(array, i, array->size - i - 1);
    }
}


int getMinData(Array *array){
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


int getMaxData(Array *array){
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






int main(int argc, const char * argv[]) {
    
    int size = 10;
    Array *array = creatArray(size);
    printArray(array);
    array->array[0] = -1;
    array->array[9] = 2;
    swap(array, 0, 9);
    printArray(array);
    int min = getMinData(array);
    printf("min is %d\n", min);
    int max = getMaxData(array);
    printf("max is %d\n", max);
    reverseArray(array);
    printArray(array);
    
    return 0;
}
