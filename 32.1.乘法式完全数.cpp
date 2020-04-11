/*************************************************************************
	> File Name: 32.1.乘法式完全数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月22日 星期日 16时27分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 10000

int digits(int x) {
    if (!x) return 1;
    return floor(log10(x)) + 1;
}

int add_to_num(int n, int *num) {
    while (n) {
        if (num[n % 10]) return 0;
        num[n % 10] += 1;
        n /= 10;
    }
    return 1;
}


int is_pandigital(int a, int b) {
    if (digits(a * b) + digits(a) + digits(b) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int flag = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num);
    flag = flag && add_to_num(a * b, num);
    return flag;
}

int keep[MAX_N + 5];

int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if (!is_pandigital(a, b)) continue;
            if (keep[a * b]) continue;
            //printf("%d * %d = %d\n", a, b, a * b);
            sum += a * b;
            keep[a * b] = 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}
