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
int a[1000],t[1000],s[1000];
vector<int> dp(1000, 0);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m, k, r;
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n;i++){cin >> a[i];}
    for (int i = 1; i <= m;i++){cin >> t[i];}
    for (int i = 1; i <= m;i++){cin >> s[i];}

    for (int i = 1; i <= m;i++){
        for (int j = r; j >= t[i];j--){
            dp[j] = max(dp[j], dp[j - t[i]] + s[i]);
        }
    }
    
	for (int i = 0; i <= r; i++) {
		if (dp[i] >= k) {
			r -= i; break;
		}
	}

    int ans = 0;
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i++){
        if(r-a[i]>=0){
            ans++;
            r -= a[i];
        }
        else
            break;
    }
    cout << ans << endl;

    return 0;
}
