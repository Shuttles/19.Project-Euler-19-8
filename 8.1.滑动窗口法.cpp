/*************************************************************************
	> File Name: 8.1.滑动窗口法.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月19日 星期四 18时24分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define MAX_N 1000

char num[MAX_N + 5];


int main() {
    int len = 0;
    //以字符数组形式读进来那个表
    while (~scanf("%s", num + len)) {
        len += strlen(num + len);
    }   
    int64_t max = 0, temp = 1, zero = 0;
    for (int64_t i = 0; num[i]; i++) {
        num[i] -= '0';
        if (num[i]) temp *= num[i];
        else zero += 1;
        if (i < 13) continue;
        if (num[i - 13]) temp /= num[i - 13];
        else zero -= 1;
        if (zero == 0 && temp > max) max = temp;
    }
    printf("%" PRId64 "\n", max);
    return 0;
}
