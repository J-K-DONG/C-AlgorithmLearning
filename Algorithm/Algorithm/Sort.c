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


// 冒泡排序+优化
// 时间复杂度：O(n^2) 稳定性：稳定
void bubbleSort(int *array, int length){
    int temp = 0;
    int last_exchange_index = 0; // 上一次交换的位置
    int sorted_board = length - 1; // 排序边界
    bool exchange_flag = TRUE; // 判断每一轮排序是否有交换位置（TRUE没有，FALSE有） 如果有，说明排序还在进行 没有，说明排序完成
    for(int i = 0; i < length; i++){
//        for(int i = 0; i<length; i++){
//            printf("%d ", array[i]);
//        }
//        printf("\n");
        exchange_flag = TRUE; // 没有交换位置
        for(int j = 0; j < sorted_board; j++){
            if(array[j] > array[j + 1]){
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
void selectSort(int *array, int array_length){
    int min = 0;
    int temp = 0;
    for(int i = 0; i < array_length; i++){
        min = i;
        for(int j = i + 1; j < array_length; j++){
            if(array[min]>array[j]){
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// 快速排序 时间复杂度：O(n*logn)   稳定行：不稳定
void quickSort(int *array, int begin, int end){
    if(begin >= end - 1)
        return;
    int mid = array[begin];
    int left_index = begin;
    int right_index = end - 1;
    while(left_index < right_index){
        while(left_index < right_index){
            if(array[right_index] < mid){
                array[left_index++] = array[right_index];
                break;
            }
            --right_index;
        }
        while(left_index < right_index){
            if(array[left_index] >= mid){
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


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[10] = {6, 24, 7, 2, 5, 19, 44, 1, 12, 15};
    
    int (*p)[10];
    p = &a;
    int length = sizeof(a) / sizeof(int);
    
    for(int i = 0; i<length; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

//    printf("%d\n", length);
//    bubbleSort(a, 10);
//    selectSort(*p, length);
    quickSort(a, 0, length);
    
    
    
//    printf("%d\n%d\n", a, a+1);
//    printf("%d\n%d\n%d\n", &a, &a[9], &a+1);

    for(int i = 0; i<length; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
