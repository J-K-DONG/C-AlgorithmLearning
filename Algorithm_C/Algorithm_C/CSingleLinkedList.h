//
//  CSingleList.h
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/7.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#ifndef CSingleList_h
#define CSingleList_h

#include "LIbHeader.h"

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node SNode;

void printSList(SNode *head);
SNode *createSList(int *array, int len);
int getSListLen(SNode *head);
SNode *getEndNodeOfSList(SNode *head);
SNode *findPreNode(SNode *head, SNode *p);
void swapSNode(SNode *head, SNode *p, SNode *q);
void printBuckets(struct Node *node);
void freeSNode(SNode *head);

#endif /* CSingleList_h */
