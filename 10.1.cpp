/*************************************************************************
	> File Name: 10.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月19日 星期四 18时48分01秒
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000

int64_t sum = 0;

int prime[MAX_N + 5];
void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum += i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (!(i % prime[j])) break;
        }
    }
    return ;
}


int main() {
    init_prime();
    printf("%" PRId64 "\n", sum);
    return 0;
}
