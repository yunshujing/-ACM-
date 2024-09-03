#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t, m;
	cin >> t >> m; //采药的总时间、草药的数目 
	
	vector<int> dp(t+1, 0);  //初始化为0 
	
	int w[100000], c[100000];
	for(int i=1;i<=m;i++){
		cin >> w[i] >> c[i]; //采摘某株草药的时间和价值 
	} 
	
	for(int i=1;i<=m;i++){
		for(int j=w[i];j<=t;j++){
			dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
		} 
	} 
	
	cout << dp[t] << '\n';

			
	return 0;
}