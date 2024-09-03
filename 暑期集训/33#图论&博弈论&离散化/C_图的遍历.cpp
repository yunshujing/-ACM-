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

vector<int> g[100010];
int n, m,vis[100010];

void dfs(int x,int d){
    if(vis[x]) return;//如果已经被探过了就返回
    vis[x] = d;
    for (int i = 0; i < g[x].size();i++){
        dfs(g[x][i], d);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        g[y].push_back(x); // 反向图
    }
    for (int i = n; i >=1;i--){//反向探
        dfs(i,i);
    }
    for (int i = 1; i <= n;i++){
        cout << vis[i] << " \n"[i == n];
    }
        return 0;
}


#include<bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int v[100001],n,m;
void bfs(int u){
	queue<int>q;
	q.push(u);//推入起始点 
	if(v[u]==0)
	v[u]=u;
	while(q.size()){
		int t=q.front();
		q.pop();
		for(auto i : a[t]){//遍历所以边 
			if(v[i]!=0) continue;
			v[i]=u;
			q.push(i);
		}
	}
}
int main()
{
	for(int i=1;i<=n;i++){
		v[i]=0;
	}
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[y].push_back(x);
	}
	for(int i=n;i>=1;i--){
		bfs(i);
	}
	for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
}