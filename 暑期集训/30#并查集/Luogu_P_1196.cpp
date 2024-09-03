// [P1196](https://www.luogu.com.cn/problem/P1196)
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

vector<int> p(50010);//我的父亲是谁
vector<int> dis(50010);//我到祖宗(根节点)的距离
//初始化
void init(int n){
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;//自己是自己的监护人
    }
    
}
//找自己最上面的祖宗 近乎O(1)
int find(int x){
	if(x != p[x]){
        int root = find(p[x]);
        dis[x] += dis[p[x]];
        p[x] = root;
    }
    return p[x];
}
//合并
void merge(int u,int v){
    int pu = find(u);
    int pv = find(v);
    if(pu != pv){
        p[pu] = pv;//新爹，合并完成
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    init(n);
    while (m--){
        int u, v;
        cin >> u >> v;
        merge(u, v);//有亲戚关系的人合并
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}