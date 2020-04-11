/*************************************************************************
	> File Name: 2.0.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 15时44分54秒
 ************************************************************************/

//正向递推：递归 + memory(没加记忆化之前时间是逆向递推的82倍) 

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 4000000

int fib1[50];
int fib(int n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    if (fib1[n]) return fib1[n];
    fib1[n] = fib(n - 1) + fib(n - 2);
    return fib1[n];
}

int main() {
    int i = 1;
    int sum = 0;
    while (fib(i) <= MAX_N) {
        int temp = fib(i);
        if (temp % 2 == 0) sum += temp;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}
