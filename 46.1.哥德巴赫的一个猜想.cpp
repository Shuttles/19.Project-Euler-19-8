/*************************************************************************
	> File Name: 46.1.哥德巴赫的一个猜想.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月29日 星期日 16时10分13秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5], is_prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_sqrt(int x) {
    return 2 * x * x;
}

bool binary_search(int (*func)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

int main() {
    init();
    int ans = 0;
    for (int i = 9; i <= MAX_N; i += 2) {
        if (!is_prime[i]) continue;
        int flag = 0;
        for (int j = 1; prime[j] < i && j <= prime[0]; j++) {
            if (binary_search(is_sqrt, 1, i - prime[j], i - prime[j])) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
