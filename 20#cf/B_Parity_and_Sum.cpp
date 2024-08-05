#include <iostream>  
#include <vector>  
  
using namespace std;  
  
// 函数用于计算将数组所有元素变为相同奇偶性所需的最少操作数  
int minOperationsToUniformParity(const vector<int>& a) {  
    int oddCount = 0;  
    for (int num : a) {  
        if (num % 2 != 0) {  
            ++oddCount;  
        }  
    }  
    // 直接返回奇数数量，因为我们需要将它们变为偶数  
    return oddCount;  
}  

int main() {  
    int t; // 测试用例数  
    cin >> t;  
  
    while (t--) {  
        int n; // 当前测试用例的数组大小  
        cin >> n;  
  
        vector<int> a(n);  
        for (int i = 0; i < n; ++i) {  
            cin >> a[i];  
        }  
  
        // 计算并输出最少操作数  
        cout << minOperationsToUniformParity(a) << endl;  
    }  
  
    return 0;  
}