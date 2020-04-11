/*************************************************************************
	> File Name: 9.1.素勾股数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月26日 星期四 19时02分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}


int main() {
    int ans = 0;
    for (int n = 1; n <= 10000; n++) {
        for (int m = n + 1; m * m + n * n < 1000000; m++) {
            if (gcd(m , n) - 1) continue;
            /*
            int a = 2 * m * n;
            int b = m * m * n * n - 1;
            int c = m * m * n * n + 1;//思考为什么这样枚举会漏很多？？？？
            */
            
            int a = 2 * m * n;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if (!(gcd(a, b) == 1 && (gcd(a, c) != 1 || gcd(b, c) != 1))) continue;
            printf("a = %d, b = %d, c = %d\n", a, b, c);
            /*
            if (1000 % (a + b + c) == 0) {
                int k = 1000 / (a + c + b);
                ans = k * k * k * a * b * c;
            }
            if (ans) {
                printf("n = %d, m = %d\n", n, m);
                break;
            }
            */
        }
        //if (ans) break;
    }
    //printf("%d\n", ans);
    return 0;
}
