#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;

int fastPower(int a, int b, int mod/* 取模 */) {
    int result = 1; // 初始化结果为1
    a = a % mod; // 将a对m取模
    while (b > 0) {
        // 如果b的当前位是1，则将当前的a乘到result上
        if (b & 1) { // 等价于 if (b % 2 == 1)
            result *= a;
			result %= mod;
        }
        // 将a平方，准备处理下一位
        a *= a;
		a %= mod;
        // b右移一位
        b >>= 1; // 等价于 b = b / 2;
    }
    return result;
}

signed main() {
    int a, b, m;
    cin >> a >> b >> m;
    printf("%d^%d mod %d=%d", a, b, m, fastPower(a, b, m));
    return 0;
}