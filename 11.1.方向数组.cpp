/*************************************************************************
	> File Name: 11.1.方向数组.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月19日 星期四 20时00分07秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20

int grid[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {
    {-1, -1}, {-1, 0},
    {-1, 1}, {0, 1}
};

int calc(int x, int y) {
    int max = 0;
    for (int k = 0; k < 4; k++) {
        int temp = 1;
        for (int step = 0; step < 4; step++) {
            int dx = x + dir[k][0] * step;
            int dy = y + dir[k][1] * step;
            if (dx < 0 || dx >= MAX_N || dy < 0 || dy >= MAX_N) break;
            temp *= grid[dx][dy];
        }
        if (temp > max) max = temp;
    }
    return max;
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int max = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            int temp = calc(i, j);
            if (temp > max)  max = temp;
        }
    }
    printf("%d\n", max);
    return 0;
}
