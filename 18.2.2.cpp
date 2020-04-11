/*************************************************************************
	> File Name: 18.2.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 17时22分56秒
 ************************************************************************/
//dfs(i, j)的语义信息是从上往下到达(i, j)时的最大值
//这种编程方法是逆向递归--for循环
#include <iostream>
using namespace std;
#define MAX_N 15

int val[MAX_N + 5][MAX_N + 5];
//int keep[MAX_N + 5][MAX_N + 5];

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = 1; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            int temp = val[i - 1][j];
            if (j - 1 >= 0 && val[i - 1][j - 1] > temp) temp = val[i - 1][j - 1];
            val[i][j] += temp;
        }
    }
    int max = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (val[14][i] > max) max = val[14][i];
    }
    cout << max << endl;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", val[i][j]);
        }
        printf("\n");
    }
    return 0;
}
