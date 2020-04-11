/*************************************************************************
	> File Name: 13.1.大整数加法.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 15时58分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 52

char str[MAX_N + 5];
int ans[MAX_N + 5];

int main() {
    while (~scanf("%s", str)) {
        int len = strlen(str);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; str[i]; i++) {
            ans[len - i] += str[i] - '0';
        }
        //下面的for循环处理进位
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]); //处理最后的进位
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}

