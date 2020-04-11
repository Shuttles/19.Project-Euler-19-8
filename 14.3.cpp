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

int64_t keep[MAX_N + 5];

int64_t get_len(int64_t n) {
    if (n == 1) return 1;
    if (n <= MAX_N && keep[n])  return keep[n];
    int64_t temp = 0;
    if (n & 1) temp = get_len(3 * n + 1) + 1;
    else temp = get_len(n >> 1) + 1;
    if (n <= MAX_N) keep[n] = temp;
    return temp;
} 

int main() {
    int64_t num = 0, len = 0;
    for (int i = 2; i < MAX_N; i++) {
        int64_t temp = get_len(i);
        if (temp > len) {
            num = i;
            len = temp;
        }
    }
    printf("num = %" PRId64 ", max_len = %" PRId64 "\n", num, len);
    return 0;
}
