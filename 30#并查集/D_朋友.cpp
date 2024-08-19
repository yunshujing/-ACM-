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

vector<int> p(N);//我的父亲是谁
vector<int> sise(N);//集合大小
//初始化
void init(int n){
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;//自己是自己的监护人
        sise[i] = 1;
    }
    
}
//找自己最上面的祖宗 近乎O(1)
int find(int x){
	if(x != p[x]){
        p[x] = find(p[x]);//路径压缩[better!]
    }
    return p[x];
}
//合并
void merge(int u,int v){
    int pu = find(u);
    int pv = find(v);
    if(pu!=pv){
        sise[pv] += sise[pu];
        p[pu] = pv;
    }
}

signed main(){
    int n, m, p, q;
    scanf("%lld %lld %lld %lld", &n, &m, &p, &q);

    init(n);
    while (p--){
        int u, v;
        cin >> u >> v;
        merge(u, v);//有亲戚关系的人合并
    }
    int x = sise[find(1)];

    init(m);
    while (q--){
        int u, v;
        cin >> u >> v;
        u *= -1, v *= -1;
        merge(u, v);//有亲戚关系的人合并
    }
    int y = sise[find(1)];
    int sum = min(x, y);
    printf("%lld\n", sum);
    return 0;
}
