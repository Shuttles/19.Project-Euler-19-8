/*************************************************************************
	> File Name: 7.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月17日 星期二 18时51分27秒
 ************************************************************************/
 //对比泽哥前后两版代码以及张泽的代码！！！！
//注意为什么18行可以写成i * i!!!
//如果写成i也行，但是20行的int j会爆掉并且18行的int i也会爆掉！！因为20行在计算的时候是先计算i*i然后存到i里面的！！！
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define MAX_N 200000

int prime[MAX_N + 5];

void init_prime() {
    for (int i = 2; i * i<= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
        //if (i * i > MAX_N) break;
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
    }
    return;
}


int main() {
    init_prime();
    printf("%d\n", prime[10001]);
    return 0;
}
