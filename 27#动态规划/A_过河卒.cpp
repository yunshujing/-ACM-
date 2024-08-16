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

int n, m, x, y, dp[1001][1001];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m >> x >> y;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i == 0 && j == 0)
                continue;
            if(i != 0)
                dp[i][j] += dp[i - 1][j];
            if(j != 0)
                dp[i][j] += dp[i][j - 1];
            if(i == x && j == y)
                dp[i][j] = 0;
            else if(abs(i-x) == 1 && abs(j-y) == 2)
                dp[i][j] = 0;
            else if(abs(i-x) == 2 && abs(j-y) == 1)
                dp[i][j] = 0;
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}
