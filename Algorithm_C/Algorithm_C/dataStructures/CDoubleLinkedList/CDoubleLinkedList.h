//
//  CDoubleLinkedList.h
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/8.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#ifndef CDoubleLinkedList_h
#define CDoubleLinkedList_h

#include "../../LIbHeader.h"

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
}DNode;


void printDlist(DNode *head);
int getDListLen(DNode *head);
DNode *getEndNodeOfDList(DNode *head);
DNode *createDList(int *array, int len);
void swapDNode(DNode *head, DNode *p, DNode *q);
void freeDNode(DNode *head);
void gnomeSortDList(DNode *head);



#endif /* CDoubleLinkedList_h */
