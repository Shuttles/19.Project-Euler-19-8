/*************************************************************************
	> File Name: 36.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 20时47分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000000

int is_palindromic(int x, int base) {
    int temp = x, ans = 0;
    while (temp) {
        ans = ans * base + temp % base;
        temp /= base;
    }
    return x == ans;
}

int main() {
    int sum = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (is_palindromic(i, 10) && is_palindromic(i, 2))
            sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
