/*************************************************************************
	> File Name: 26.分数循环节.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 20时35分40秒
 ************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;
#define MAX_N 1000

int r_len[MAX_N + 5];

int get_len(int d) {
    int r = 1, t = 1;
    r_len[r] = 1;
    while (r) {
        //while (r < d) r *= 10; 想一想为什么要注释掉这一行
        r *= 10;
        r %= d;
        t += 1;
        cout << "r = " << r << endl;
        if (r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
    return 0;
}


int main() {
    int d = 1, len = -1;
    for (int i = 2; i < MAX_N; i++) {
        memset(r_len, 0, sizeof(r_len));
        int temp = get_len(i);
        if (len < temp) len = temp, d = i;
    }
    cout << d << endl << len << endl;
    return 0;
}
