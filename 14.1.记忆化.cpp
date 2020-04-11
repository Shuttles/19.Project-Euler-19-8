/*************************************************************************
	> File Name: 14.1.记忆化.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 14时48分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define MAX_N 1000000

int get_len(int64_t n) {
    if (n == 1) return 1;
    if (n % 2) return get_len(3 * n + 1) + 1;
    return get_len(n / 2) + 1;
} 

int main() {
    int num = 0, len = 0;
    for (int i = 2; i < MAX_N; i++) {
        int temp = get_len(i);
        if (temp > len) {
            num = i;
            len = temp;
        }
    }
    printf("num = %d, max_len = %d\n", num, len);
    return 0;
}
