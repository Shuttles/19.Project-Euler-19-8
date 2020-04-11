/*************************************************************************
	> File Name: 31.1.钱币问题.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月22日 星期日 14时47分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 8
#define MAX_M 200

int w[MAX_N + 5] = {
    0, 1, 2, 5, 10, 20, 50, 100, 200
};
int f[MAX_N + 5][MAX_M + 5];

int main() {
    for (int i = 1; i <= MAX_N; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= MAX_M; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) f[i][j] += f[i][j - w[i]];
        }
    }
    printf("%d\n", f[MAX_N][MAX_M]);
    return 0;
}
