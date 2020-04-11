/*************************************************************************
	> File Name: 7.3.线性筛.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月17日 星期二 20时26分53秒
 ************************************************************************/

//其实19行的判断j <= prime[0]完全没有必要！！！
//为什么17行的判断不能写i <= (MAX_N / 2)???
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 200000

int prime[MAX_N + 5];

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (!(i % prime[j])) break;
        }
    }
    return;
}

int main() {
    init_prime();
    printf("%d\n", prime[10001]);
    return 0;
}
