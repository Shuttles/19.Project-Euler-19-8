/*************************************************************************
	> File Name: 2.3.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 16时03分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define N 3
#define MAX_N 4000000

int fib[N] = {0, 1};


int main() {
    int sum = 0;
    int n = 2;
    while (fib[(n - 1) % N] + fib[(n - 2) % N] <= MAX_N) {
        fib[n % N] = fib[(n - 1) % N] + fib[(n - 2) % N];
        if (!(fib[n % N] & 1)) sum += fib[n % N];
        n += 1;
    }
    printf("%d\n", sum);
    return 0;
}
