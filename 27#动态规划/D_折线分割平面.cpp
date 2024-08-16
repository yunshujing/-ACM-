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
    
    vector<int> dp(10001); 
	dp[0]=1;	
	for(int i=1;i<=10000;i++){
		dp[i] = ((i-1)*2-1)*2 + dp[i-1]+3; 
	}

	int c;
	cin >> c;
	
	while(c--){
		int n;
		cin >> n;
		printf("%d\n", dp[n]);
	}
    
    return 0;
}
