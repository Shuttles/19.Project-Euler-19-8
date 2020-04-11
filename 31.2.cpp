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
int f[2][MAX_M + 5];


int main() {
    for (int k = 1; k <= MAX_N; k++) {
        int i = k % 2;
        f[i][0] = 1;
        for (int j = 1; j <= MAX_M; j++) {
            f[i][j] = f[i ^ 1][j];
            if(j >= w[k]) f[i][j] += f[i][j - w[k]];
        }
    }
    printf("%d\n", f[MAX_N % 2][MAX_M]);
    return 0;
}
