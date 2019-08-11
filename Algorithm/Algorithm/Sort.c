//
//  main.c
//  Algorithm
//
//  Created by JK DONG on 2019/7/24.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include <stdio.h>
typedef int bool;
#define TRUE 1;
#define FALSE 0;


// 冒泡排序+优化  时间复杂度：O(n^2) 稳定性：稳定
void bubbleSort(int *array, int length)
{
    int temp = 0;
    int last_exchange_index = 0; // 上一次交换的位置
    int sorted_board = length - 1; // 排序边界
    bool exchange_flag = TRUE; // 判断每一轮排序是否有交换位置（TRUE没有，FALSE有） 如果有，说明排序还在进行 没有，说明排序完成
    for(int i = 0; i < length; ++i)
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

// 选择排序 时间复杂度：O(n^2) 稳定性：不稳定
void selectSort(int *array, int array_length)
{
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

// 快速排序 时间复杂度：O(n*logn)   稳定行：不稳定  分治
void quickSort(int *array, int begin, int end)
{
    if(begin >= end - 1)
        return;
    int mid = array[begin];
    int left_index = begin;
    int right_index = end - 1;
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

//插入排序 时间复杂度：O(n^2)   稳定性：稳定
void insertSort(int *array, int array_length)
{
    int i,j,temp;
    for(i = 1; i < array_length; ++i)
    {
        for(j = i - 1, temp = array[i];j >= 0 && array[j] > temp; --j)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}


//希尔排序。  时间复杂度：O(n^3/2)   稳定性：不稳定
void shellSort(int *array, int begin, int end)
{
    for(int step = (end - begin) / 2; step > 0; step /= 2) //步长逐渐变成之前的一半
    {
        for(int i = begin; i < step; ++i) // 循环第一个步长中的每一个元素
        {
            for(int k = i + step; k < end; k += step) // 循环后面其他的步长
            {
                for(int j = k - step; j >= begin; j -= step) // 找到比当前检查的元素应该在的位置
                {
                    if(array[j] <= array[k])
                        break;
                    int temp = array[k];
                    for(int z = k; z >= j; z -= step)
                        array[z] = array[z - step];
                    array[j] = temp;
                }
            }
        }
    }
}

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
            parrent = i / 2;
        else
            parrent = i / 2 - 1;
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
    buildMaxHeap_2(array, begin, end);
    while(end > 0)
    {
        temp = array[begin];
        array[begin] = array[end];
        array[end--] = temp;
        buildMaxHeap_2(array, begin, end);
    }
}



int main(int argc, const char * argv[])
{
    // 排序结果都为从小到大
    int a[10] = {6, 24, 7, 2, 5, 19, 44, 1, 12, 15};
    
    int length = sizeof(a) / sizeof(int);
    printf("原始数组元素:\n");
    for(int i = 0; i<length; i++)
        printf("%d ", a[i]);
    printf("\n");

//    printf("%d\n", length);
//    bubbleSort(a, 10);
//    selectSort(*p, length);
//    quickSort(a, 0, length);
//    insertSort(a, length);
//    shellSort(a, 0, length);
    heapSort(a, 0, length - 1);
    
    printf("排序后元素的顺序:\n");
    for(int i = 0; i<length; i++)
        printf("%d ", a[i]);
    return 0;
}
