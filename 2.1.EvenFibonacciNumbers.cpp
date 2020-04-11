/*************************************************************************
	> File Name: 2.1.EvenFibonacciNumbers.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 15时17分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 44
#define Ceil 4000000

int fib[MAX_N + 5];

int main() {
    fib[1] = 1, fib[2] = 2;
    int sum = 2;
    for (int i = 3; i <= MAX_N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= Ceil) break;
        if (fib[i] & 1) continue;
        sum += fib[i];
    }    
    printf("%d\n", sum);
    return 0;
}
