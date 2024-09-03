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

int hi[1000],ti[1000],ki[1000];
int dp[10000][10000];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int hmax, tmax,n;
    cin >> hmax >> tmax >> n;
    for (int i = 1; i <= n;i++){
        cin >> hi[i] >> ti[i] >> ki[i];
    }

    for (int i = 1; i <= n;i++){
		for (int j = hmax; j >= hi[i]; j--){
			for(int z = tmax;z >= ti[i];z--){
				dp[j][z] = max(dp[j][z], dp[j - hi[i]][z - ti[i]] + ki[i]);
			}
		}
	}
    cout << dp[hmax][tmax] << endl;
    return 0;
}