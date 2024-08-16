// #include<iostream>
// #include<cstdio>
// using namespace std;

// int n, f[1000000];//用f数组存放数量

// /*
// f[0]=0;
// f[1]=f[0]+1=1;
// f[2]=f[1]+1=2;
// */

// int main(){
// 	cin >> n;  //n元 
// 	for(int i=1;i<=n;i++){  //从最底层判断开始
	
// 		if(i >= 11){  //i>=11,可以用一张11元钱的替换
// 			f[i] = min(f[i-1], min(f[i-5],f[i-11])) + 1;  //钱币数量叠加(最小)
			
// 		}else if(i>=5){ //i=5~10,可以用一张5元钱的替换5张1元钱的
// 			f[i]=min(f[i-1],f[i-5])+1;  //钱币数量叠加(最小)
			
// 		}else{ //i=1~4,只能用1元钱的 
// 			f[i]=f[i-1]+1;  //钱币数量叠加
// 		}
		
// 	}
// 	cout<<f[n]<<endl;//f[n]代表凑出n块钱需要的最少钱币数
	
	
// 	return 0;
// }


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
const int maxn = 1e6 + 100;
const double eps = 1e-5;

signed main() {
	int a[3] = { 1,5,11 };
	int n; cin >> n;
	
	vector<int>dp(n + 1, 0x3f3f3f3f);//dp(长度，值)
    //0x3f3f3f3f 是一个很大的数  默认需要无穷的金币
	dp[0] = 0;//需要的金币的数量
	for (int i = 0; i < 3; i++) {//遍历每一种金币
		for (int j = a[i]; j <= n; j++) {// j 是 钱的sum
			dp[j] = min(dp[j - a[i]]+ 1, dp[j]) ;//类似记忆
		}
	}
	cout << dp[n] << endl;//输出组成金额n 所需要的最少金币的数量
	return 0;
}

//也可以使用 BFS

