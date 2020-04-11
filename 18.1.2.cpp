/*************************************************************************
	> File Name: 18.1.数字三角形dp.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 16时18分07秒
 ************************************************************************/
//
//val[i][j]的语义信息是自下而上得到的最大值
//此种编程方法是逆向递推--for循环
#include <iostream>
using namespace std;
#define MAX_N 20

int val[MAX_N + 5][MAX_N + 5];

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i;j++) {
            cin >> val[i][j];
        }
    }    
    for (int i = 14; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", val[i][j]);
        }
        printf("\n");
    }
    return 0;
}
