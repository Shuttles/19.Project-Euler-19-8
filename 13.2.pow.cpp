/*************************************************************************
	> File Name: 13.1.大整数加法.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 15时58分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 520

int ans[MAX_N + 5];

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    ans[0] = ans[1] = 1;
    for (int i = 1; i <= b; i++) {
        for (int i = 1; i <= ans[0]; i++) {
            ans[i] *= a;
        }
        //下面的for循环处理进位
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]); //处理最后的进位
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
