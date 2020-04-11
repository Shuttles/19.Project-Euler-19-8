/*************************************************************************
	> File Name: 28.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 19时11分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1001

int main() {
    int sum = 1;
    for (int m = 3; m <= MAX_N; m += 2) {
        sum += (4 * m * m - 6 * m + 6);
    }
    printf("%d\n", sum);
    //如何将时间复杂度提到O(1)? 试着推导奇数的平方和公式
    return 0;
}
