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

    vector<int> dp(56);
    dp[1] = 1, dp[2] = 2, dp[3] = 3,dp[4]=4;	//第1年到第4年都只有一只老母牛在生产一只小母牛 
    //往后的年份中，计算上一年的母牛数和三年前的母牛数（今年是第四年，他们已经长大了）
    for(int i=5;i<=55;i++){
        dp[i] = dp[i-1] + dp[i-3]; 
    }

    int n;
    while(cin >> n&&n!=0){
        cout << dp[n] << endl;
    }
    return 0;
}