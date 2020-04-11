/*************************************************************************
	> File Name: 21.3.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月29日 星期日 18时53分12秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cinttypes>
using namespace std;
#define MAX_N 4000000

int prime[MAX_N + 5];
int f[MAX_N + 5];
int cnt[MAX_N + 5];//存放下标的最小素因子的幂次

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (pow(prime[j], cnt[i] + 1) - 1) * (pow(prime[j], cnt[i] + 2) - 1);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
    return;
}


int main() {
    int64_t sum = 0;
    init();
    for (int i = 2; i < MAX_N; i++) {
        f[i] -= i;
    }
    for (int i = 2; i < MAX_N; i++) {
        if (f[i] != i && f[i] < MAX_N && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
