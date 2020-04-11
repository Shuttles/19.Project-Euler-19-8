/*************************************************************************
	> File Name: 3.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 16时36分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define MAX_N 600851475143LL

#define max_n 100

int prime[max_n + 5];

void is_prime() {
    for (int i = 2; i * i < max_n; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= max_n; j += i) {
                prime[j] = 1;
            }
        }
    }
    return ;
}

int main() {
    int64_t ans = 0, M = MAX_N, m = MAX_N;
    int64_t i = 2;
    //思路和素数筛异曲同工
    while (i * i <= M) {
        while (M % i == 0) ans = i, M /= i; //ans记录的一定是素因子
        i += 1;
    }
    if (M - 1) ans = M;//为什么这一行是有必要的？
    printf("%" PRId64 "\n", ans);
    return 0;
}
