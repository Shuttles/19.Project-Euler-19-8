/*************************************************************************
	> File Name: 12.1.因子个数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月26日 星期四 19时49分24秒
 ************************************************************************/

//首先将时间复杂度降为O(N)
//接着将空间复杂度将为O(n)
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000

int prime[MAX_N + 5];
int f[MAX_N + 5];
int cnt[MAX_N + 5];//记录i的最小素因子的幂次


void init_prime() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            //如果i是素数
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                //i prime[j]互素
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
    return ;
}

int main() {
    init_prime();
    int n = 0, fac = 0;
    while (fac < 500) {
        n += 1;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
