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
void BubbleSort(int *array, int length){
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


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int length = 6;
    int a[6] = {6, 24, 7, 2, 5, 19};
    
    BubbleSort(a, 6);
    for(int i = 0; i<length; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
