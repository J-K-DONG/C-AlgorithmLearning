//
//  CSingleList.c
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/7.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include "CSingleLinkedList.h"



/*  遍历输出链表  */
void printSList(SNode *head)
{
    if(!head || !head->next)
        return;
    printf("Single Linked List is printed as followes : \n");
    SNode *p = head->next;
    while(p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*  创建单链表  */
SNode *createSList(int *array, int len)
{
    if(len < 1)
        return NULL;
    SNode *head = (SNode *)malloc(sizeof(SNode));
    head->data = 0;
    head->next = NULL;
    SNode *p = head;
    printf("构造单向链表：\n");
    for(int i = 0; i < len; ++i)
    {
        SNode *q = (SNode *)malloc(sizeof(SNode));
        q->data = array[i];
        p->next = q;
        p = q;
    }
    p->next = NULL;
    printSList(head);
    return head;
}

/*  计算链表中元素的个数  */
int getSListLen(SNode *head)
{
    if (!head || !head->next) {
        printf("元素个数为0 \n");
        return 0;
    }
    int len = 0;
    SNode *temp = head->next;
    while (temp) {
        ++len;
        temp = temp->next;
    }
    return len;
}

/*  找到尾节点  */
SNode *getEndNodeOfSList(SNode *head)
{
    if (!head || !head->next) {
        printf("链表为空。\n");
        return NULL;
    }
    SNode *end = head->next;
    while (end->next) {
        end = end->next;
    }
    return end;
}


/*  找到链表中的前驱节点  */
SNode *findPreNode(SNode *head, SNode *p)
{
    if(!p || p == head)
        return NULL;
    SNode *preNode = head;
    while(preNode->next != p)
    {
        preNode= preNode->next;
    }
    return preNode;
}

/*   默认是带头节点的单链表   */
/*  两个节点进行位置交换  */
void swapSNode(SNode *head, SNode *p, SNode *q)
{
    if(!q || !p || p == head || q == head || p == q)
    {
        printf("not swap\n");
        return;
    }
    
    SNode *pPrior = findPreNode(head, p);
    SNode *qPrior = findPreNode(head, q);
    SNode *pNext = p->next;
    SNode *qNext = q->next;
    
    /*  两节点相邻 p 是 q 的前驱节点  */
    if(p->next ==  q)
    {
        pPrior->next = q;
        q->next = p;
        p->next = qNext;
    }
    /*   q 是 p 的前驱节点   */
    else if(q->next == p)
    {
        qPrior->next = p;
        p->next = q;
        q->next = pNext;
    }
    /*  两个节点不相邻  */
    else
    {
        pPrior->next = q;
        q->next = pNext;
        qPrior->next = p;
        p->next = qNext;
        
    }
}

/* 传入一个桶链表的头节点  然后新创建一个指针指向它 循环输出  */
void printBuckets(struct Node *node)
{
    struct Node *list = node;
    
    while(list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
}


void freeSNode(SNode *head)
{
    if(!head)
    {
        printf("头节点为空\n");
        return;
    }
    SNode *node = head->next;
    free(head);
    while(node)
    {
        SNode *temp = node;
        node = node->next;
        free(temp);
    }
}
