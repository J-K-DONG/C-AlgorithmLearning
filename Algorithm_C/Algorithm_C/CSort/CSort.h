//
//  CSort.h
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/8.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#ifndef CSort_h
#define CSort_h

#include "../dataStructures/CArray/CArray.h"
#include "../dataStructures/CSIngleLinkedList/CSingleLinkedList.h"
#include "../dataStructures/CDoubleLinkedList/CDoubleLinkedList.h"

typedef int bool;  //定义TRUE  FALSE
#define TRUE 1;
#define FALSE 0;

void bubbleSort(int *array, int len);
void bubbleSortSList(SNode *head);

void cocktailSort(int *array, int len);
void cocktailSortDList(DNode *head);

void oddEvenSort(int *array, int len);
void oddEvenSortSList(SNode *head);

void gnomeSort(int *array, int len);
void gnomeSortDList(DNode *head);

void selectSort(int *array, int len);
void selectSortSList(SNode *head);

void quickSort(int *array, int begin, int end);
void quickSortDList(DNode *head, DNode *begin, DNode *end);

void insertSort(int *array, int len);
void insertSortDList(DNode *head);

void shellSort(int *array, int begin, int end);

void maxToTop(int *array, int begin, int end);
void buildMaxHeap_1(int *array, int begin, int end);
void buildMaxHeap_2(int *array, int begin, int end);
void heapSort(int *array, int begin, int end);

void mergeSortOrder(int *array, int begin, int mid, int end);
void mergeSort(int *array, int begin, int end);

struct Node *nodeInsertSort(struct Node *list);
void bucketSort(int *array, int len);

void countingSort(int *array, int len);



#endif /* CSort_h */
