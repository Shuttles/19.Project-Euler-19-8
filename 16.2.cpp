/*************************************************************************
	> File Name: 16.大数2^n.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 15时51分25秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 400

int ans[MAX_N + 10] = {1, 1};

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= ans[0]; j++) ans[j] *= 1024;
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
