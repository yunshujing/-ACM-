#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int p[30005];  //我的父亲是谁 
int dis[30005]; //我到祖宗的距离 
int siz[30005];

//初始化n个人（独立的个体） 
void init(int n){
	for(int i=1;i<=n;i++){
		p[i] = i; //自己是自己的监护人 
		dis[i] = 0;
		siz[i] = 1;  //自己是第一 
	}
}

//查询（找自己最上面的祖宗） 
int find(int x){
	if(x != p[x]){
		int root = find(p[x]);
		dis[x] += dis[p[x]];
		p[x] = root;
	}
	return p[x];
}

//合并有亲戚关系的 
void merge(int u, int v){
	int pu = find(u);  //找u的爹 
	int pv = find(v);  //找v的爹 
	if(pu != pv){
		dis[pu] = siz[pv];
		siz[pv] += siz[pu]; 
		p[pu] = pv;
	}
	
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cout << fixed << setprecision(6);
    
    int q;
	cin >> q;
	
	init(30000); 
	
	while(q--){
		char op;
		int i, j;
		cin >> op >> i >> j;
		if(op == 'M'){
			merge(i, j);
		}else if(op == 'C'){
			if(find(i) == find(j)){  //同为一个祖宗 
				int ans = max(0, abs(dis[i] - dis[j])- 1 ); 
				cout << ans << endl;
			} else{
				cout << "-1\n";
			}
		}
		
	}
	return 0;
}