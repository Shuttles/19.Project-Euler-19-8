/*************************************************************************
	> File Name: 7.2.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月17日 星期二 19时58分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000

int prime[MAX_N + 5];
void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {  //注意为什么是i不是i * i!!!
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            prime[j] = i; //始终用素数i更新为j的最大素因子
        }
    }
    return ;
}


int main() {
    init_prime();
    int x;
    scanf("%d", &x);
    printf("max_factor(%d) = %d\n", x, prime[x]);
    return 0;
}
