/*************************************************************************
	> File Name: 18.1.数字三角形dp.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 16时18分07秒
 ************************************************************************/

//dfs(i, j)的语义信息是自下而上到达i,j这个位置的最大值
#include <iostream>
using namespace std;
#define MAX_N 20

int val[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5];

int dfs(int i, int j) {
    if (i + 1 == 15) return keep[i][j] = val[i][j];
    int val1 = dfs(i + 1, j);
    int val2 = dfs(i + 1, j + 1);
    return keep[i][j] = (val1 > val2 ? val1 : val2) + val[i][j];
}

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i;j++) {
            cin >> val[i][j];
        }
    }    
    cout << dfs(0, 0) << endl;
    return 0;
}
