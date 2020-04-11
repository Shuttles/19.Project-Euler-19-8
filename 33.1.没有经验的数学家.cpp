/*************************************************************************
	> File Name: 33.1.消去数字的分数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月22日 星期日 18时15分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}


/*
int is_val(int a, int b) {
    int i = a / 10;
    int j = b % 10;
    int temp = gcd(a, b);
    int numerator = a / temp;
    int denominator = b / temp;
    return i * denominator != j * numerator;
}
*/

int is_val(int x, int y) {
    int x1 = x / 10, x2 = x % 10;
    int y1 = y / 10, y2 = y % 10;
    if (!x2 || !y2) return 0;
    if (x1 == y1 && x2 * y == x * y2) return 1;
    if (x1 == y2 && x2 * y == x * y1) return 1;
    if (x2 == y1 && x1 * y == x * y2) return 1;
    if (x2 == y2 && x1 * y == x * y1) return 1;
    return 0;
}



int main() {
    int numerator  = 1;
    int denominator = 1;
    for (int i = 10; i < MAX_N; i++) {
        for (int j = i + 1; j < MAX_N; j++) {
            if (!is_val(i, j))  continue;
            numerator *= i;
            denominator *= j;
            int temp = gcd(numerator, denominator);
            numerator /= temp, denominator /= temp;
        }
    }
    printf("%d\n", denominator);
    return 0;
}
