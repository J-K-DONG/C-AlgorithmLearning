//
//  main.c
//  Algorithm_C
//
//  Created by JK DONG on 2019/10/7.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include "Header.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[] = {11, 22, -3, 34, 1};
    int len = sizeof(a) / sizeof(int);
    SNode *SList = createSList(a, len);
    printSList(SList);
    
    
    DNode *DList = createDList(a, len);
    printDlist(DList);
    
    bubbleSortSList(SList);
    printSList(SList);
    return 0;
}
