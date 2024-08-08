#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
const int mod1 = 998244353;

//int a[N];
//vector <int> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;  
    cin >> n >> m;  
    vector<int> nums(n);  
    for (int i = 0; i < n; ++i) {  
        cin >> nums[i];  
    }  
  
    int maxXor = 0;  
    for (int i = 0; i < n; ++i) {  
        for (int j = i + 1; j < n; ++j) {  
            int xorResult = nums[i] & nums[j];  
            maxXor = max(maxXor, xorResult);  
        }  
    }  
  
    cout << maxXor << endl;  
    
    return 0;  
}
