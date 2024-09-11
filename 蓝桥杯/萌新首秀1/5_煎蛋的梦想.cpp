#include <iostream>
using namespace std;

// 函数用于计算n的最小热量消耗
int minHeat(int n) {
    int heat = 0;
    // 处理质因数为2的情况
    while (n % 2 == 0) {
        heat += 2;
        n /= 2;
    }
    
    // 处理奇数的质因数
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            heat += i;
            n /= i;
        }
    }
    
    // 如果n本身是质数，直接加n
    if (n > 1) {
        heat += n;
    }
    
    return heat;
}

int main() {
    int n;
    cin >> n;
    cout << minHeat(n) << endl;
    return 0;
}
