// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// const int N = 1e6 + 10;
// const double eps =1e-4;
// //int a[N];
// //vector <int> a;

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while(t--){
//         int l, r;
//         cin >> l >> r;


//     }
    
//     return 0;
// }
#include <iostream>  
#include <vector>  
#include <cmath>  
  
using namespace std;  
  
// 这是一个启发式的函数，用于估计将数字n变为0所需的操作次数  
// 注意：这个函数是近似的，并且可能不是最优的  
int estimateOperations(int n) {  
    if (n == 0) return 0;  
    if (n % 3 == 0) return 1 + estimateOperations(n / 3); // 如果是3的倍数，则除以3  
    else return 2 + estimateOperations(n % 3 == 2 ? (n / 3) * 3 + 2 : (n / 3) * 3 + 1); // 否则，先除以3取整再乘以3，然后加上额外的操作  
    // 注意：这里的策略是近似的，并没有考虑到最优的合并和重排操作  
}  
  
// 计算区间[l, r]中所有数字变为0所需的最小操作次数（启发式解法）  
int minOperationsInRange(int l, int r) {  
    int totalOperations = 0;  
    for (int i = l; i <= r; ++i) {  
        totalOperations += estimateOperations(i);  
    }  
    return totalOperations;  
}  
  
int main() {  
    int t;  
    cin >> t; // 读取测试用例数量  
    while (t--) {  
        int l, r;  
        cin >> l >> r; // 读取每个测试用例的l和r  
        cout << minOperationsInRange(l, r) << endl; // 输出所需的最少操作次数的近似值  
    }  
    return 0;  
}