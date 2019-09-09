//
//  main.c
//  OperationResearch
//
//  Created by JK DONG on 2019/9/9.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 64
int k = 0, len;
int a[MAXSIZE][MAXSIZE], b[MAXSIZE];

void dfs(int index)
{
    int i;
    for(i = 0; i < len; ++i)
    {
        if(a[index][i] == 1)
        {
            a[index][i] = 0;
            a[i][index] = 0;
            dfs(i);
        }
    }
    b[++k] = index;
//    printf("%d ", i);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("------\n");
    int i, j, sum_row = 0, num_odd = 0, first_index = 0;
    scanf("%d", &len);
    
    for(i = 0; i < len; ++i)
    {
        for(j = 0; j < len; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    
    for(i = 0; i < len; ++i)
    {
        for(j = 0; j < len; ++j)
        {
            if(a[i][j] == 1)
                sum_row++;
        }
        if(sum_row % 2 == 1)
        {
            if(num_odd == 0)
                first_index = i;
            num_odd++;
        }
        sum_row = 0;
    }
    
    printf("first_index = %d\n", first_index);
    if(num_odd == 1 || num_odd > 2)
    {
        printf("no solution!");
        return -1;
    }
    
    dfs(first_index);
//    printf("\n");
    printf("节点顺序如下：\n");
    for(int z = k; z > 0; --z)
    {
        printf("%d\n", b[z]);
    }
//    printf("Hello, World!\n");
    return 0;
}
