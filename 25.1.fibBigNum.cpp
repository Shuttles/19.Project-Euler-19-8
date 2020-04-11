/*************************************************************************
	> File Name: 25.1.fibBigNum.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月22日 星期日 14时13分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 1000

int fib[3][MAX_N + 5];

int main() {
    int n = 2;
    fib[1][0] = fib[1][1] = 1;
    fib[2][0] = fib[2][1] = 1;
    while (fib[n % 3][0] < 1000) {
        n += 1;
        int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        for (int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i];
        }
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
        printf("%d\n", a[0]);
    }
    printf("%d\n", n);
    return 0;
}
