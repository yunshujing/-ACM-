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

vector<int> g[1001];
int n, m,vis[1001];

int bfs(int u){
    for (int i = 1; i <= n;i++){
        vis[i] = 0;
    }//清空标记
    queue<int> q;
    q.push(u);//推入初始点
    vis[u] = 1;
    int mx = u;
    while(q.size()){
        int t = q.front();//拿出一个点
        q.pop();
        for(auto i:g[t]){//遍历所有边
            if(vis[i]==1)//如果已经推进去了就跳过
                continue;
            vis[i] = 1;//标记
            mx = max(mx, i);
            q.push(i);//并推入
        }
    }
    return mx;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> m;

    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); // 有向图存数
        // g[y].push_back(x); // 无向图存数
    }
    for (int i = 1; i <= n;i++){
        cout << bfs(i) << " \n"[i == n];
    }
        return 0;
}