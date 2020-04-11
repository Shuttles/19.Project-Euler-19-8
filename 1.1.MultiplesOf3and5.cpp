/*************************************************************************
	> File Name: 1.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月15日 星期日 14时50分25秒
 ************************************************************************/
//时间复杂度O(n)
#include <stdio.h>
#include <stdlib.h>

int is_val(int n) {
    if (n % 3 == 0 || n % 5 == 0)
        return 1;
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
