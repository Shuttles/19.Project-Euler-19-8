/*************************************************************************
	> File Name: 18.2.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 17时22分56秒
 ************************************************************************/
//dfs(i, j)的语义信息是从上往下到达(i, j)时的最大值
//这种编程方法是正向递推--递归+记忆化
#include <iostream>
using namespace std;
#define MAX_N 15

int val[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5];

int dfs(int i, int j) {
    if (i < 0 || j < 0) return 0;
    return keep[i][j] = val[i][j] + max(dfs(i - 1, j), dfs(i - 1, j - 1));
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            dfs(i, j);
        }
    }
    int max = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (keep[14][i] > max) max = keep[14][i];
    }
    cout << max << endl;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", keep[i][j]);
        }
        printf("\n");
    }
    return 0;
}
