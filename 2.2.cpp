/*************************************************************************
	> File Name: 2.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 15时52分36秒
 ************************************************************************/

 
//空间复杂度为O(1)
//因为不需要存每个数
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 4000000


int main() {
    int sum = 0;
    int a = 0, b = 1;
    while (a + b <= MAX_N) {
        b = a + b;
        a = b - a;
        if (b % 2 == 0) sum += b;
    }
    printf("%d\n", sum);
    return 0;
}
