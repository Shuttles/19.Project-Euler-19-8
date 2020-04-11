/*************************************************************************
	> File Name: 7.1.prime.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月17日 星期二 18时43分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) return 0;
    }
    return 1;
}

int main() {
    int i, cnt = 0;
    for (i = 2; cnt < 10001; i++) {
        if (!is_prime(i)) continue;
        cnt += 1;
    }
    printf("%d\n", i - 1);
    return 0;
}
