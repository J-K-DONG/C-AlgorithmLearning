//
//  main.cpp
//  c++project
//
//  Created by JK DONG on 2019/3/25.
//  Copyright © 2019 JK DONG. All rights reserved.
//

#include <iostream>
using namespace std;

//补码加法溢出检验
int tadd_ok(int x, int y){
    int sum = x + y;
    cout<<sum<<endl; // 负值表示溢出
//    return (sum - x == y) && (sum - y == x);
    int neg_over = x < 0 && y < 0 && sum >= 0;//下溢出
    int pos_over = x > 0 && y > 0 && sum <= 0;//上溢出
    return !neg_over && !pos_over;
}

//乘法溢出检验
int tmult_ok_div(int x, int y){
    int p = x*y;
    /*either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

//乘法溢出检验
int tmult_ok_int64(int x, int y){
    int64_t pll = (int64_t) x*y; //强制类型转化 很关键
    /*see if casting to int preserves value */
    return pll == (int) pll;
}

//除法(除以2的k次幂)
int div_2_k(int x, int k){
    // 判断除法的结果是否为负数 （正数：逻辑右移 向下舍入  负数：算数右移 向上舍入）
    int result = (x < 0 ? (x + (1 << k) - 1) : x) >> k;
    return result;
}

int main(int argc, const char * argv[]) {
    int result;
    result = tadd_ok(-1, -2147483648); // -2147483648 int型最小值 保证溢出
    cout<<"溢出的结果为（1:不溢出， 0:溢出）："<<result<<endl;
//    cout<<1<<endl;
    printf("%d\n",div_2_k(44, 3));
    return 0;
    
}
