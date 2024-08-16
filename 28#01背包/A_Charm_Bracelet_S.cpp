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

int n, m;
int v[N], w[N];
int f[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> v[i] >> w[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--){  //从大到小循环
			f[j] = max(f[j], f[j-v[i]] + w[i]);
		}
	}
	
	cout << f[m] << endl;
    
    return 0;
}