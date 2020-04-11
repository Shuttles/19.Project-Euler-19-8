/*************************************************************************
	> File Name: 47.1.四个连续整数有四个不同素因子.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月29日 星期日 18时10分31秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            prime[j] += 1;
        }
    }
    return;
}


int main() {
    init();
    int ans = 0;
    for (int i = 1000; i <= MAX_N; i++) {
        int flag = 1;
        for (int j = 0; j < 4; j++) {
            flag = (prime[i + j] == 4);
            if (!flag) break;
        }
        if (!flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
