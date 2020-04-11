/*************************************************************************
	> File Name: 21.1.因子和.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月29日 星期日 18时30分50秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;
#define MAX_N 1000000

int f[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        for (int j = 1; j * j < i; j++) {
            if (i % j) continue;
            f[i] += j;
            f[i] += i / j;
        }
        f[i] -= i;
    }
    return;
}


int main() {
    int64_t sum = 0;
    init();
    for (int i = 2; i < MAX_N; i++) {
        if (f[i] != i && f[i] < MAX_N && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
