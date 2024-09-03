#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int N, M;  
    cin >> N >> M;  
    vector<int> A(N + 1); // +1 是为了方便计算，A[0] 不用
    vector<int> sums(N + 1, 0);
    for (int i = 1; i <= N; ++i) {  
        cin >> A[i];
        sums[i] = (sums[i - 1] + A[i]) % M;   
    }  


    // 统计每个前缀和出现的次数  
    map<int, int> count;  
    for (int sum : sums) {  
        count[sum]++;  
    }  

    // 计算答案  
    int ans = 0;  
    for (auto& p : count) {  
        int sum = p.first;  
        int freq = p.second;  
        if (freq > 1) {  
            // 对于每个前缀和，我们都可以选择两个相同的休息区（除了自己），  
            // 或者选择一个休息区并配对其他具有相同前缀和的休息区  
            // 注意要排除自己到自己的情况  
            ans += (int)freq * (freq - 1); // 组合数 C(freq, 2)  
        }  
    }  

    cout << ans << endl;  
    return 0;
}
