//
//  CDoubleLinkedList.c
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/8.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include "CDoubleLinkedList.h"


/*  循环l遍历双向链表并输出  */
void printDlist(DNode *head)
{
    if(!head || !head->next)
        return;
    printf("Double Linked List is printed as followes : \n");
    DNode *node = head->next;
    while(node)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}

/*  计算链表中元素的个数  */
int getDListLen(DNode *head)
{
    if (!head || !head->next) {
        printf("元素个数为0 \n");
        return 0;
    }
    int len = 0;
    DNode *temp = head->next;
    while (temp) {
        ++len;
        temp = temp->next;
    }
    return len;
}

/*  找到链表的尾节点  */
DNode *getEndNodeOfDList(DNode *head)
{
    if (!head || !head->next) {
        printf("链表为空。 \n");
        return NULL;
    }
    DNode *end = head->next;
    while (end->next) {
        end = end->next;
    }
    return end;
}


/*  创建双向链表  */
DNode *createDList(int *array, int len)
{
    if(len < 1)
        return NULL;
    DNode *head = (DNode *)malloc(sizeof(DNode));
    DNode *p = (DNode *)malloc(sizeof(DNode));
    head->data = 0;
    head->prior = NULL;
    head->next = p;
    p->data = array[0];
    p->prior = head;
    p->next = NULL;
    if(len == 1)
        return head;
    
    for(int i = 1; i < len; ++i)
    {
        DNode *q = (DNode *)malloc(sizeof(DNode));
        q->data = array[i];
        q->prior = p;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    printDlist(head);
    return head;
}

/*  交换双向列表中的两个节点  */
void swapDNode(DNode *head, DNode *p, DNode *q)
{
    if(!p || !q || p == q || p == head || q == head)
    {
        printf("交换失败\n");
        return;
    }
    DNode *pPrior = p->prior;  // p 的前驱节点
    DNode *pNext = p->next;  // p 的后继节点
    DNode *qPrior = q->prior;  // q 的前驱节点
    DNode *qNext = q->next;  // q 的后继节点
    if(pNext == q)
    {
        pPrior->next = q;
        q->prior = pPrior;
        q->next = p;
        p->prior = q;
        p->next = qNext;
        if(qNext)
            qNext->prior = p;
    }
    else if(qNext == p)
    {
        qPrior->next = p;
        p->prior = qPrior;
        p->next = q;
        q->prior = p;
        q->next = pNext;
        if(pNext)
            pNext->prior = q;
    }
    else{
        pPrior->next = q;
        q->prior = pPrior;
        q->next = pNext;
        if(pNext)
            pNext->prior = q;
        qPrior->next = p;
        p->prior = qPrior;
        p->next = qNext;
        if(qNext)
            qNext->prior = p;
    }
}


void freeDNode(DNode *head)
{
    if(!head){
        printf("头节点为空\n");
        return;
    }
    DNode *node = head;
    DNode *temp;
    
    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
}
