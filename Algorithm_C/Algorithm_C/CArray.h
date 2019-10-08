//
//  CArray.h
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/8.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#ifndef CArray_h
#define CArray_h

#include "LIbHeader.h"


int getMaxData(int *array, int len);
int getMinData(int *array, int len);
void swap(int *a, int *b);
void printArray(int *array, int len);


//========================================================================================
//                                      CArray
//========================================================================================

typedef struct CArray{
    int *array;
    int size;
}Array;

Array *creatCArray(int size);
void insertCArrayData(Array *array, int position, int data);
void printCArray(Array *array);
void swapCArray(Array *array, int a, int b);
void reverseCArray(Array *array);
int getMinDataCArray(Array *array);
int getMaxDataCArray(Array *array);



#endif /* CArray_h */
