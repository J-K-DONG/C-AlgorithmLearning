//
//  main.c
//  Algorithm
//
//  Created by JK DONG on 2019/7/24.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int bool;
#define TRUE 1;
#define FALSE 0;


// 1. 冒泡排序+优化  时间复杂度：O(n^2) 稳定性：稳定
void bubbleSort(int *array, int array_length)
{
    if(array_length < 2)
        return;
    int temp = 0;
    int last_exchange_index = 0; // 上一次交换的位置
    int sorted_board = array_length - 1; // 排序边界
    bool exchange_flag = TRUE; // 判断每一轮排序是否有交换位置（TRUE没有，FALSE有） 如果有，说明排序还在进行 没有，说明排序完成
    for(int i = 0; i < array_length; ++i)
    {
//        for(int i = 0; i<length; i++){
//            printf("%d ", array[i]);
//        }
//        printf("\n");
        exchange_flag = TRUE; // 没有交换位置
        for(int j = 0; j < sorted_board; ++j)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                last_exchange_index = j; //k记录上一次交换的位置
                exchange_flag = FALSE; // 有交换位置
            }
        }
        sorted_board = last_exchange_index; //赋值给下一轮排序的边界值
        if(exchange_flag){
            break;
        }
    }
}

// 2. 选择排序 时间复杂度：O(n^2) 稳定性：不稳定
void selectSort(int *array, int array_length)
{
    if(array_length < 2)
        return;
    int min = 0;
    int temp = 0;
    for(int i = 0; i < array_length; ++i)
    {
        min = i;
        for(int j = i + 1; j < array_length; ++j)
            if(array[min]>array[j])
                min = j;
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// 3. 快速排序 时间复杂度：O(n*logn)   稳定行：不稳定  分治
void quickSort(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
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

// 4. 插入排序 时间复杂度：O(n^2)   稳定性：稳定
void insertSort(int *array, int array_length)
{
    if(array_length < 2)
        return;
    int i,j,temp;
    for(i = 1; i < array_length; ++i)
    {
        for(j = i - 1, temp = array[i];j >= 0 && array[j] > temp; --j)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}


// 5. 希尔排序。  时间复杂度：O(n^3/2)   稳定性：不稳定
void shellSort(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    for(int step = (end - begin) / 2; step > 0; step /= 2) //步长逐渐变成之前的一半
    {
        for(int i = begin; i < step; ++i) // 循环第一个步长中的每一个元素
        {
            for(int k = i + step; k <= end; k += step) // 循环后面其他的步长
            {
                int j = k - step;
                for(; j >= begin; j -= step) // 找到比当前检查的元素应该在的位置
                {
                    if(array[j] <= array[k])
                        break;
                }
                if(j != k - step)
                {
                    int temp = array[k];
                    for(int z = k; z > j + step; z -= step)
                        array[z] = array[z - step];
                    array[j + step] = temp;
                }
            }
        }
    }
}


/*
 6. 堆排序
 时间复杂度： O(n*logn)
 稳定性： 不稳定
 */
void maxToTop(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    int parrent = begin;
    int child = parrent * 2 + 1, temp;
    while(child < end)
    {
        if((child < end - 1) && (array[child] < array[child + 1]))
            ++child;
        if(array[child] > array[parrent]) // 将最大的元素移动到最顶端
        {
            temp = array[parrent];
            array[parrent] = array[child];
            array[child] = temp;
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
    int parrent, temp;
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
            temp = array[parrent];
            array[parrent] = array[i];
            array[i] = temp;
        }
    }
}

void heapSort(int *array, int begin, int end)
{
    if(begin > end - 1)
        return;
    int temp;
    while(end > 0)
    {
        buildMaxHeap_2(array, begin, end);
        temp = array[begin];
        array[begin] = array[end];
        array[end--] = temp;
    }
}


// 7. 归并排序  时间复杂度：O(n * logn)  稳定性： 稳定
void mergeSortOrder(int *array, int begin, int mid, int end)
{
//    printf("小范围排序：");
//    printf("%d %d %d\n", begin, mid, end);
    int *pBuf = (int *)malloc(sizeof(int) * (end - begin));
    int *pTemp = pBuf;
    int lindex = begin;
    int rindex = mid;
    
    while((lindex < mid) && (rindex < end))
        *pTemp++ = (array[lindex] < array[rindex] ? array[lindex++] : array[rindex++]);
//    printf("比较完成\n");
    while(lindex < mid)
        *pTemp++ = array[lindex++];
    while(rindex <= end)
        *pTemp++ = array[rindex++];
    pTemp = pBuf;
    for(int i = begin; i <= end; ++i)
        array[i] = *pTemp++;
//    for(int i = begin; i <= end; i++)
//        printf("%d ", array[i]);
//    printf("\n");
    
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
            int temp = array[begin];
            array[begin] = array[end];
            array[end] = temp;
//            printf("交换的两个元素:\n");
//            printf("%d %d\n", array[begin], array[end]);
        }
        return;
    }
    int mid = (end + begin) / 2;
//    printf("%d %d %d\n", begin, mid, end);
    mergeSort(array, begin, mid);
    mergeSort(array, mid, end);
    mergeSortOrder(array, begin, mid, end);
    
}

void printArray(int *array, int array_length)
{
    //    printf("%d\n", length);
    for(int i = 0; i < array_length; ++i)
    {
        printf("%d ", array[i]);
    }
}

/*
 8. 桶排序
 稳定性：稳定  时间复杂度：O(n + k) 线性时间
 可应用于数据量分布比较均匀，或比较侧重于区间数量时
 在额外空间充足的情况下，尽量增大桶的数量
 使用的映射函数能够将输入的 N 个数据均匀的分配到 K 个桶中
 对于桶中元素的排序，选择何种比较排序算法对于性能的影响至关重要
 */

#define NBUCKET 5 /* bucket number */

struct Node
{
    int data;
    struct Node *next;
};

//  传入一个桶链表的头节点  然后新创建一个指针指向它 循环输出
void printBuckets(struct Node *node)
{
    struct Node *list = node;
    while(list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
}

int getMaxData(int *array, int array_length)
{
    int max = array[0];
    for(int i = 1; i < array_length; ++i)
    {
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

int getMinData(int *array, int array_length)
{
    int min = array[0];
    for(int i = 1; i < array_length; ++i)
    {
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

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

void bucketSort(int *array, int array_length)
{
    int i, j;
    int min = getMinData(array, array_length);
    int interval = (getMaxData(array, array_length) - min) / NBUCKET + 1; // 分开桶子
    struct Node **buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);
    
    /*  初始化到指到桶子的指针, 指针地址赋值为空  */
    for(i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }
    
    /*  判断每一个元素并放入对应的桶子中    */
    for(i = 0; i < array_length; ++i)
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
            assert(j < array_length); // 检查参数的值
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


int main(int argc, const char * argv[])
{
    // 排序结果都为从小到大
    int a[] = {21,125,-1,49,9,37,27,43,-41,45};
    int length = sizeof(a) / sizeof(int);
    
    printf("元素个数为： %d\n", length);
    printf("原始数组元素:\n");
    printArray(a, length);
    printf("\n--------------------------\n");
//    bubbleSort(a, length);
//    selectSort(a, length);
//    quickSort(a, 0, length - 1);
//    insertSort(a, length);
//    shellSort(a, 0, length - 1);
//    heapSort(a, 0, length - 1);
    mergeSort(a, 0, length - 1);
//    bucketSort(a, length);

    printf("--------------------------\n");
    printf("排序后元素的顺序:\n");
    printArray(a, length);
    printf("\n--------------------------\n");
    return 0;
}



