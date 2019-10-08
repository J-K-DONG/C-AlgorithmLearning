//
//  CSort.c
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/8.
//  Copyright © 2019 JK DONG. All rights reserved.
//


#include "CSingleLinkedList.h"
#include "CDoubleLinkedList.h"
#include "CSort.h"

//========================================================================================
//                                      冒泡排序
//========================================================================================


//   冒泡排序+优化  时间复杂度：n^2 / n / n^2   稳定性：稳定
void bubbleSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    int temp = 0;
    int last_exchange_index = 0; // 上一次交换的位置
    int sorted_board = len - 1; // 每次扫描的右边界
    bool exchange_flag = TRUE; // 判断每一轮排序是否有交换位置（TRUE有交换 表明排序还在进行，FALSE没有交换 表明排序未完成）
    for(int i = 0; i < len; ++i)
    {
        exchange_flag = FALSE; // 没有交换位置  （初始化本次循环 ）
        for(int j = 0; j < sorted_board; ++j)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                last_exchange_index = j; //k记录上一次交换的位置
                exchange_flag = TRUE; // 有交换位置
            }
        }
        sorted_board = last_exchange_index; //赋值给下一轮排序的边界值
        if(!exchange_flag){
            break;
        }
    }
}

/*  冒泡排序的链表实现  */
void bubbleSortSList(SNode *head)
{
    if(!head || !head->next)
        return;
    SNode *p = head->next;
    SNode *q = p->next;
    
    /*  是否有交换  FALSE（无交换 表示排序完成） TRUE（有交换 表示排序未完成）  */
    bool flag = TRUE;
    
    /*  每次循环比较交换的最后一个节点  */
    SNode *last_exchange = NULL;
    SNode *sort_border = NULL;
    while(flag)
    {
        flag = FALSE;
        while(q != sort_border)
        {
            if(p->data > q->data)
            {
                swapSNode(head, p, q);  // 交换完位置 q 在 p 的前面
                q = p->next;
                flag = TRUE;  // 本次有交换 说明排序未完成
                last_exchange = p;  // 记录最后一次交换的后一个节点
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        sort_border = last_exchange;  // 记为下一次排序的边界
        p = head->next;  // 重置指针
        q = p->next;
    }
}

//========================================================================================
//                                      鸡尾酒排序
//========================================================================================
/*   鸡尾酒排序 ： 时间复杂度： n^2 / n / n^2   稳定性： 稳定*/
void cocktailSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    int sorted_left = 0;
    int sorted_right = len - 1;
    int last_exchange_index = 0;
    bool exchange_flag = TRUE;  //判断是否有交换 TRUE有 FALSE 没有
    while(exchange_flag)
    {
        exchange_flag = FALSE; //每次循环前置零
        for(int j = sorted_left; j < sorted_right; ++j) // 左到右
        {
            if(array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                exchange_flag = TRUE; //表示本次循环有交换
                last_exchange_index = j;
            }
        }
        sorted_right = last_exchange_index; // 设置右边界
        for(int k = sorted_right; k > sorted_left; --k)  //右到左
        {
            if(array[k] < array[k - 1])
            {
                swap(&array[k], &array[k - 1]);
                exchange_flag = TRUE;
                last_exchange_index = k;
            }
        }
        sorted_left = last_exchange_index;  // 设置左边界
    }
}

/*  鸡尾酒排序的双向链表实现  */
void cocktailSortDList(DNode *head)
{
    if(!head || !head->next )
        return;
    DNode *p = head->next;
    DNode *q = p->next;
    DNode *sorted_left = head;
    DNode *sorted_right = NULL;
    DNode *last_exchange = NULL;
    bool flag = TRUE;  // TRUE:排序未完成  FALSE : 排序完成
    
    while(flag)
    {
        flag = FALSE;
        while(q != sorted_right)
        {
            if(p->data > q->data)
            {
                swapDNode(head, p, q);
                last_exchange = p;
                q = p->next;
                flag = TRUE;
            }
            else
            {
                p = p->next;  // 指针后移一个节点
                q = p->next;
            }
        }
        if(flag)  // 排序未完成 则修改指针
        {
            sorted_right = last_exchange;
            p = sorted_right->prior;  // p 指向本次排序边界的前个节点
            q = p->next;
        }
        while(p != sorted_left)
        {
            if(p->data > q->data)
            {
                swapDNode(head, p, q);
                last_exchange = q;
                p = q->prior;
                flag = TRUE;
            }
            else
            {
                p = p->prior;  // 指针前移一个节点
                q = p->next;
            }
        }
        if(flag)  // 排序未完成 则修改指针
        {
            sorted_left = last_exchange;
            p = sorted_left->next;
            q = p->next;
            //            printf("p->data%d  q->data%d\n", p->data, q->data);
        }
    }
}


//========================================================================================
//                                      奇偶排序
//========================================================================================

/*  奇偶排序  时间复杂度： n^2    稳定性：稳定  */
void oddEvenSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    bool exchange_flag = TRUE;
    while(exchange_flag)
    {
        exchange_flag = FALSE;
        for(int i = 0; i < len - 1; i += 2)  // 先排偶数
        {
            if(array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                exchange_flag = TRUE;
            }
        }
        for(int j = 1; j < len - 1; j += 2)  // 再排奇数
        {
            if(array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                exchange_flag = TRUE;
            }
        }
    }
}

/*  奇偶排序的单向链表实现  */
void oddEvenSortSList(SNode *head)
{
    if(!head || !head->next)
    {
        printf("未排序\n");
        return;
    }
    SNode *p, *q;
    
    bool flag = TRUE;
    while(flag)
    {
        p = head->next;  // 奇数
        q = p->next;  // 偶数
        flag = FALSE;
        while(p && p->next)
        {
            if(p->data > p->next->data)
            {
                //                printf("odd exchange %d and %d\n", p->data, p->next->data);
                swapSNode(head, p, p->next);
                //                printSList(head);
                flag = TRUE;
                p = p->next;
            }
            else if(p->next->next)
                p = p->next->next;
            else
                break;
        }
        while(q && q->next)
        {
            if(q->data > q->next->data)
            {
                //                printf("even exchange %d and %d\n", q->data, q->next->data);
                swapSNode(head, q, q->next);
                flag = TRUE;
                //                printSList(head);
                q = q->next;
            }
            else if(q->next->next)
                q = q->next->next;
            else
                break;
        }
    }
}

//========================================================================================
//                                      地精排序
//========================================================================================
/* 地精排序  时间复杂度：n^2  稳定性： 稳定*/
void gnomeSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    int i = 0;
    while(i < len)
    {
        if(i == 0 || array[i] >= array[i - 1])
            ++i;
        else  // 比前一个小再交换
        {
            swap(&array[i], &array[i - 1]);
            --i;
        }
    }
}

/*  地精排序的双向链表实现  */
void gnomeSortDList(DNode *head)
{
    if(!head || !head->next)
    {
        printf("未排序\n");
        return;
    }
    DNode *p = head->next;
    
    while (p) {
        if (p == head->next || p->data > p->prior->data) {
            p = p->next;
        }
        else
            swapDNode(head, p->prior, p);
    }
}

//========================================================================================
//                                      选择排序
//========================================================================================

//  选择排序 时间复杂度：O(n^2) 稳定性：不稳定
void selectSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    int min = 0;
    int temp = 0;
    for(int i = 0; i < len; ++i)
    {
        min = i;
        for(int j = i + 1; j < len; ++j) // 找到最小的
            if(array[min] > array[j])
                min = j;
        temp = array[i];  // 与当前min索引交换
        array[i] = array[min];
        array[min] = temp;
    }
}

void selectSortSList(SNode *head)
{
    if(!head || !head->next)
    {
        printf("未排序 \n");
        return;
    }
    SNode *p = head->next;
    SNode *q, *min = p;
    while (p) {
        q = p;
        min = p;
        while (q) {
            if(min->data > q->data)
                min = q;
            q = q->next;
        }
        swapSNode(head, p, min);
        p = min->next;
    }
}


//========================================================================================
//                                      快速排序
//========================================================================================

//  快速排序 时间复杂度：n^2 / n*logn / n*logn  稳定行：不稳定  分治
void quickSort(int *array, int begin, int end)
{
    if(begin > end - 1){
        printf("未排序\n");
        return;
    }
    int mid = array[begin];
    int left_index = begin;
    int right_index = end;
    while(left_index < right_index)
    {
        while(left_index < right_index)
        {
            if(array[right_index] < mid)
            {
                array[left_index++] = array[right_index];
                break;
            }
            --right_index;
        }
        while(left_index < right_index)
        {
            if(array[left_index] >= mid)
            {
                array[right_index--] = array[left_index];
                break;
            }
            ++left_index;
        }
    }
    array[left_index] = mid;
    quickSort(array, begin, left_index);
    quickSort(array, right_index + 1, end);
}

/*  快速排序的双向链表实现  */
void quickSortDList(DNode *head, DNode *begin, DNode *end)
{
    if (!head || !head->next || begin == end) {
        printf("未排序\n");
        return;
    }
    //    DNode *mid = head->next;
    DNode *node_1 = begin;
    DNode *node_2 = end;
    
    while (node_1 != node_2) {
        while (node_1 != node_2) {
            if (node_2->data < node_1->data) {
                swapDNode(head, node_1, node_2);  // 2 在前  1 在后
                if (node_1 == begin) {
                    begin = node_2;
                }
                if (node_2 == end) {
                    end = node_1;
                }
                break;
            }
            node_2 = node_2->prior;
        }
        while (node_1 != node_2) {
            if (node_2->data > node_1->data) {
                swapDNode(head, node_1, node_2);
                if (node_2 == begin) {
                    begin = node_1;
                }
                if (node_1 == end) {
                    end = node_2;
                }
                break;
            }
            node_2 = node_2->next;
        }
    }
    quickSortDList(head, begin, node_2);
    quickSortDList(head, node_2->next, end);
    
}


//========================================================================================
//                                      插入排序
//========================================================================================

//  插入排序 时间复杂度：O(n^2)   稳定性：稳定
void insertSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    int i,j,temp;
    for(i = 1; i < len; ++i)  // 第一个不动 从第二个开始到最后一个
    {
        for(j = i - 1, temp = array[i];j >= 0 && array[j] > temp; --j)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}

/*  插入排序的双向链表实现  */
void insertSortDList(DNode *head)
{
    if (!head || !head->next) {
        printf("链表为空\n");
        return;
    }
    DNode *p ;  // 当前比较节点的前驱节点
    DNode *q = head->next;  // 下一轮循环中 准备比较插入的节点
    while (q) {
        p = q->prior;  // 指向前驱节点
        q = q->next;  // 指向下一轮插入比较的初始节点 q先移动指针 下面的比较和插入不改变 q 指针
        while (p != head && p->data > p->next->data) {  // 前大于后
            p = p->prior;  // 指针先移动 再进行交换
            swapDNode(head, p->next, p->next->next);  // p 指针指向不改变
        }
    }
}


//========================================================================================
//                                      希尔排序
//========================================================================================

//  希尔排序。  时间复杂度：O(n^3/2)   稳定性：不稳定
void shellSort(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    if (begin  == end - 1) {
        if (array[begin] > array[end]) {
            swap(&array[begin], &array[end]);
        }
        return;
    }
    
    for(int step = (end - begin) / 2; step > 0; step /= 2) //步长逐渐变成之前的一半
    {
        for(int i = begin; i < step; ++i) // 循环第一个步长中的每一个元素
        {
            for(int k = i + step; k <= end; k += step) // 循环后面其他的步长
            {
                while (array[k] < array[k - step] && (k - step >= begin)) {
                    swap(&array[k], &array[k - step]);
                    k = k - step;
                }
            }
        }
    }
}

//========================================================================================
//                                      堆排序
//========================================================================================

/*
 堆排序
 时间复杂度： O(n*logn)
 稳定性： 不稳定
 */
void maxToTop(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    int parrent = begin;
    int child = parrent * 2 + 1;
    while(child < end)
    {
        if((child < end - 1) && (array[child] < array[child + 1]))
            ++child;
        if(array[child] > array[parrent]) // 将最大的元素移动到最顶端
        {
            swap(&array[child], &array[parrent]);
        }
        else
            break;
        parrent = child;
        child = parrent * 2 - 1;
    }
}

void buildMaxHeap_1(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    int parrent = end / 2 - 1;
    while(parrent >= 0)
    {
        maxToTop(array, parrent, end);
        --parrent;
    }
}


void buildMaxHeap_2(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    int parrent;
    for(int i = end; i > 0; --i)
    {
        if(i % 2)
        {
            parrent = i / 2;
        }
        else
        {
            parrent = i / 2 - 1;
        }
        if(array[i] > array[parrent])
        {
            swap(&array[i], &array[parrent]);
        }
    }
}

void heapSort(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    while(end > 0)
    {
        buildMaxHeap_2(array, begin, end);
        swap(&array[begin], &array[end]);
        end--;
    }
}




//  归并排序  时间复杂度：O(n * logn)  稳定性： 稳定
void mergeSortOrder(int *array, int begin, int mid, int end)
{
    if(begin > end - 1)
        return;
    
    int *pBuf = (int *)malloc(sizeof(int) * (end - begin));
    int *pTemp = pBuf;
    int lindex = begin;
    int rindex = mid;
    
    while((lindex < mid) && (rindex < end))
        *pTemp++ = (array[lindex] < array[rindex] ? array[lindex++] : array[rindex++]);
    while(lindex < mid)
        *pTemp++ = array[lindex++];
    while(rindex <= end)
        *pTemp++ = array[rindex++];
    pTemp = pBuf;
    for(int i = begin; i <= end; ++i)
        array[i] = *pTemp++;
    free(pBuf);
}

void mergeSort(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    if(begin >= end - 1)
    {
        if(array[begin] > array[end])
        {
            swap(&array[begin], &array[end]);
        }
        return;
    }
    int mid = (end + begin) / 2;
    //    printf("%d %d %d\n", begin, mid, end);
    mergeSort(array, begin, mid);
    mergeSort(array, mid, end);
    mergeSortOrder(array, begin, mid, end);
    
}



/*
 桶排序
 稳定性：稳定  时间复杂度：O(n + k) 线性时间
 可应用于数据量分布比较均匀，或比较侧重于区间数量时
 在额外空间充足的情况下，尽量增大桶的数量
 使用的映射函数能够将输入的 N 个数据均匀的分配到 K 个桶中
 对于桶中元素的排序，选择何种比较排序算法对于性能的影响至关重要
 */

#define NBUCKET 5 /* bucket number */


/*  对桶中的元素排序  */
struct Node *nodeInsertSort(struct Node *list)
{
    if(list == NULL || list->next == NULL)
    {
        return list;
    }
    struct Node *nodeList, *k;
    nodeList = list; // 指针nodelist 指向桶子的头节点
    k = list->next; // 指针k 指向第二个节点
    nodeList->next = NULL; // 头节点独立出来
    
    while(k != NULL)
    {
        //        printBuckets(nodeList);
        //        printf("\n");
        struct Node *ptr;
        if(nodeList->data > k->data) // 第一个大于第二个
        {
            struct Node *temp;
            temp = k; // 指向第二个
            k = k->next; // 指向第三个
            temp->next = nodeList; // 较大的节点作为第二个节点
            nodeList = temp; // 头节点指向较小的节点
            continue;
        }
        
        for(ptr = nodeList; ptr->next != NULL; ptr = ptr->next)
        {
            if(ptr->next->data > k->data) break;
        }
        
        /*  前面的节点默认有序了  */
        /*  找到比 k 大的节点 进行插入排序   */
        if(ptr->next != NULL)
        {
            struct Node *temp;
            temp = k;
            k = k->next;
            temp->next = ptr->next;
            ptr->next = temp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = NULL;
            continue;
        }
    }
    return nodeList;
}

void bucketSort(int *array, int len)
{
    if (len < 2) {
        printf("未排序\n");
        return;
    }
    int i, j;
    int min = getMinData(array, len);
    int interval = (getMaxData(array, len) - min) / NBUCKET + 1; // 分开桶子
    struct Node **buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);
    
    /*  初始化到指到桶子的指针, 指针地址赋值为空  */
    for(i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }
    
    /*  判断每一个元素并放入对应的桶子中    */
    for(i = 0; i < len; ++i)
    {
        struct Node *current = (struct Node *)malloc(sizeof(struct Node)); // 新建节点
        int pos = (array[i] - min) / interval; //找到对应的桶子
        current->data = array[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }
    
    /*  输出每个桶中的元素  */
    printf("排序前桶中的元素顺序如下：\n");
    for(i = 0; i < NBUCKET; ++i)
    {
        printf("Bucket[\"%d\"] : ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }
    
    /*  对桶中元素排序 并输出排好序的桶中的节点  */
    printf("排序后的桶中的元素顺序如下：\n");
    for(i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = nodeInsertSort(buckets[i]);
        printf("Bucket[\"%d\"] : ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }
    
    /*  将链表的节点的值放回数组中   */
    for(i = 0, j = 0;i < NBUCKET; ++i)
    {
        struct Node *temp;
        temp = buckets[i];
        while(temp)
        {
            assert(j < len); // 检查参数的值
            array[j++] = temp->data;
            temp = temp->next;
        }
    }
    
    /*  释放节点  */
    for(i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            struct Node *temp;
            temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(buckets);
}

/*
 计数排序 不比较
 适用于数据比较密集 而且重复率比较大的数组
 优势在于在对一定范围内的整数排序时，它的复杂度为Ο(n+k)（其中k是整数的范围），快于任何比较排序算法。
 当然这是一种牺牲空间换取时间的做法，而且当O(k)>O(nlog(n))的时候其效率反而不如基于比较的排序
 （基于比较的排序的时间复杂度在理论上的下限是O(nlog(n)), 如归并排序，堆排序）
 
 */

void countingSort(int *array, int len)
{
    if(len < 2)
        return;
    int size = 0;
    int max = getMaxData(array, len);
    int min = getMinData(array, len);
    size = max - min + 1;
    int *array_temp = (int *)malloc(sizeof(int) * size);
    //    printf("size = %d\n", size);
    memset(array_temp, 0, sizeof(int) * size);
    //    printArray(array_temp, size);
    for(int i = 0; i < len; ++i)
    {
        array_temp[array[i] - min]++;
    }
    //    printArray(array_temp, size);
    int temp = 0;
    for(int j = 0; j < len; ++j)
    {
        
        while(array_temp[j + temp] == 0)
        {
            temp++;
        }
        array[j] = j + temp + min;
        array_temp[j + temp]--;
    }
}
