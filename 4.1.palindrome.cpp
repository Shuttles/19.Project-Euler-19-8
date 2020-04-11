/*************************************************************************
	> File Name: 4.1.palindrome.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 18时11分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define MAX_N 1000

int is_palindromic(int x) {
    int temp = x, ans = 0;
    while (temp) {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    return x == ans;
}

int main() {
    int max = 0;
    for (int a = 101; a < MAX_N; a++) {
        for (int b = a; b < MAX_N; b++) {
            int temp = a * b;
            if (!is_palindromic(temp)) continue;
            if (temp > max) max = temp;
        }
    }
    printf("%d\n", max);
    return 0;
}
