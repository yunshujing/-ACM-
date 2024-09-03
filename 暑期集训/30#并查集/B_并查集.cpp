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
        p[x] = find(p[x]);//路径压缩[better!]
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

    int n, m;
    cin >> n >> m ;
    init(n);
    while (m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z==1){
        merge(x, y);//有亲戚关系的人合并
        }
        if(z==2){
            if(find(x) == find(y)){
                cout << "Y" << endl;
            }
            else{
                cout << "N" << endl;
            }
        }
    }
    return 0;
}