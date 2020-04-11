/*************************************************************************
	> File Name: 34.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 20时01分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N  2903040

int factorial[15] = {1};

int is_val(int n) {
    int temp = n, ans = 0;
    while (temp) {
        ans += factorial[temp % 10];
        temp /= 10;
    }
    return n == ans;
}

void init_factorial() {
    for (int i = 1; i < 10; i++) {
        factorial[i] = i * factorial[i - 1];
    }    
    return ;
}

int main() {
    init_factorial();
    int sum = 0;
    for (int i = 3; i <= MAX_N; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
