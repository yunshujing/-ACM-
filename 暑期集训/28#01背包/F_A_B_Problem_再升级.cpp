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

int dp[10010];
bool isPrime(int x) {
    if (x < 2)
    {
        return false;
    }
    //ÊÔ³ý·¨
    for (int i = 2; i <= x/i; i++)
    {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 2; i <= n; i++){
        if(!isPrime(i))continue;
        for (int j = 0; j <= n; j++){
            if(j+i>n)
                break;
            dp[j + i] += dp[j];
        }
    }
    cout << dp[n] << endl;

    return 0;
}
