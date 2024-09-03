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

int a[5] = {1, 5, 10, 25, 50}; //表示5种硬币各自的价值 
int dp[110][260];  //表示dp[i][v]，用i个硬币凑成价值为v的方法数  

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n;
	while (cin >> n){
		memset(dp, 0, sizeof(dp)); //初始化dp数组全变为0 
		
		dp[0][0] = 1;  //边界，用0个硬币凑成0美分，有1种方法
		
		for (int i=0;i<5;i++){  //5种硬币的价值 
			for (int k=1;k<=100;k++){  //k个硬币
				for (int v=a[i];v<=n;v++){
					dp[k][v] += dp[k-1][v-a[i]];//状态转移方程
				}                        
			}
		}
		
		int ans=0;
		for (int i=0;i<=100;i++){
			ans += dp[i][n];
		}
		
		cout << ans << endl;
	}
    
    return 0;
}
