/*************************************************************************
	> File Name: 13.3.factorial.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 18时05分32秒
 ************************************************************************/

//想想为什么原先的代码50!还是对的but500!就是错的??
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1500

int ans[MAX_N + 5] = {1, 1};
void factorial(int x) {
    memset(ans, 0, sizeof(ans));
    ans[0] = ans[1] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= ans[0]; j++) ans[j] *= i;
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    return;
}


int main() {
    int x;
    while (~scanf("%d", &x)) {
        factorial(x);
        for (int i = ans[0]; i > 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
