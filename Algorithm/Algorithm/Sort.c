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

void BubbleSort(int *array, int length){
    int temp = 0;
    int last_exchange_index = 0;
    int sorted_board = length - 1;
    bool exchange_flag = TRUE;
    for(int i = 0; i < length; i++){
        for(int i = 0; i<length; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
        exchange_flag = TRUE;
        for(int j = 0; j < sorted_board; j++){
            if(array[j] > array[j + 1]){
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                last_exchange_index = j;
                exchange_flag = FALSE;
            }
        }
        
        sorted_board = last_exchange_index;
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
