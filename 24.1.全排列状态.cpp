/*************************************************************************
	> File Name: 24.1.全排列状态.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 19时18分53秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10

int factorial[MAX_N];
int num[MAX_N];

void init(int n) {
    factorial[0] = 1;
    num[0] = 1;//1代表可用
    for (int i = 1; i <= n; i++) {
        factorial[i] = i * factorial[i - 1];
        num[i] = 1;
    }
    return;
}


//这个函数是核心中的核心
//要想理解for循环里的东西，必须得手工举个栗子！！！！
int get_num(int k, int n, int &x) {
    int step = k / n;//这个位置可以往上增大几个一点点
    x = 0;
    for (int t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    //最后这个位置上的值增大成了x;
    k %= n;
    num[x] = 0;
    return k;
}

int main() {
    init(MAX_N);
    int k = 1000000 - 1;//剩余的要跳的状态数
    for (int i = MAX_N; i > 0; i--) {
        //if (!k) break;
        int x;
        k = get_num(k, factorial[i - 1], x);
        cout << x;
    }
    cout << endl;
    return 0;
}
