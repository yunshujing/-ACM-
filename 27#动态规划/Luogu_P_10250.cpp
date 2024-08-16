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

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n;i++){
        for (int j = 1; j <= 3;j++){
            if( i+j > n) break;
            dp[i + j] += dp[i];
        }
    }
    cout << dp[n] << endl;

    return 0;
}