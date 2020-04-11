/*************************************************************************
	> File Name: 5.1.最小公倍数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月17日 星期二 18时23分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans , i);
    }
    printf("%d\n", ans);
    return 0;
}
