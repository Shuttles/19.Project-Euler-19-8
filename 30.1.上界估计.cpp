/*************************************************************************
	> File Name: 30.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 19时33分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 354294

int is_val(int n) {
    int temp = n, ans = 0;
    while (temp) {
        ans += (int)pow(temp % 10, 5);
        temp /= 10;
    }
    return n == ans;
}

int main() {
    int sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
