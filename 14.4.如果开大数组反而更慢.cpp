/*************************************************************************
	> File Name: 14.1.记忆化.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 14时48分49秒
 ************************************************************************/
 
 //为什么开大数组反而变得更慢呢，因为每次取数据，都得先从内存里取到高速缓存里
 //而L3里最多也就8MB(8百万个字节左右)，有可能你这次取的数据里没有你想要的，所以就要再次去内存里取数据，所以会变慢
 //启示：要想写好代码，还得懂OS、计组！！！

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define MAX_N 100000000

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
