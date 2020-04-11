/*************************************************************************
	> File Name: 15.1.C40,20.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年12月28日 星期六 15时39分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    long long m = 40, n = 20, ans = 1;
    while (n || m != 20) {
        if (m != 20) ans *= (m--);
        if (n && (ans % n == 0)) ans /= (n--);
    }
    cout << ans << endl;
    return 0;
}
