/*************************************************************************
	> File Name: 21.1.因子和.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月29日 星期日 18时30分50秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;
#define MAX_N 1000000

int f[MAX_N + 5];


//思考一下为什么？？？？
void init() {
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 2; i * j <= MAX_N; j++) {
            f[i * j] += i;
        }
    }
    return;
}


int main() {
    int64_t sum = 0;
    init();
    for (int i = 2; i < MAX_N; i++) {
        if (f[i] != i && f[i] < MAX_N && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
