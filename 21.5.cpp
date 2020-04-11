/*************************************************************************
	> File Name: 21.5.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月29日 星期日 20时11分52秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5], f[MAX_N + 5];
int64_t cnt[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 1 + i;
            cnt[i] = i * i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] * (cnt[i] * prime[j]- 1) / (cnt[i] - 1); 
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = prime[j] * prime[j];
            }
        }
    }
    return;
}


int main() {
    init();
    int max = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (f[i] > max) max = f[i];
    }
    cout << max << endl;
    return 0;
}
