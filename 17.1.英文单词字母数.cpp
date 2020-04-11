/*************************************************************************
	> File Name: 17.1.英文单词字母数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月21日 星期六 15时16分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int get_letters(int n) {
    //定义静态数组
    static int arr1[20] = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
        6, 6, 8, 8, 7, 7, 9, 8, 8
    };
    static int arr2[10] = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6
    };
    if (n < 20) return arr1[n];
    if (n < 100) return arr2[n / 10] + arr1[n % 10];
    if (n < 1000) {
        if (n % 100 == 0) return arr1[n / 100] + 7;
        return arr1[n / 100] + 10 + get_letters(n % 100);
    }
    return 11;//1000
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += get_letters(i);
    }
    printf("%d\n", sum);
    return 0;
}
