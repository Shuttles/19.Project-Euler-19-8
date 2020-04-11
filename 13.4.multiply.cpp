/*************************************************************************
	> File Name: 13.4.multiply.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 19时08分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 100

char str_a[MAX_N + 5], str_b[MAX_N + 5];
int a[MAX_N + 5], b[MAX_N + 5], c[MAX_N << 1 + 5];

void get_num(char *str, int num[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        num[i] = str[len - i - 1] - '0';
    }
    return;
}

void get_product(int *a, int *b) {
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] < 10) continue;
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    int len_c = len_a + len_b;
    while (!c[len_c]) len_c--;
    for (int i = len_c; i >= 0; i--) printf("%d", c[i]);
    printf("\n");
    return;
}

int main() {
    memset(c, 0, sizeof(c));
    scanf("%s%s", str_a, str_b);
    get_num(str_a, a);
    get_num(str_b, b);
    get_product(a, b);
    return 0;
}
