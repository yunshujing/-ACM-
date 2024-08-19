// #include<bits/stdc++.h>
#include <vector>  
#include <iostream>  
#include <cstdio>  
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
vector<int> siz(N);//集合大小
//初始化
void init(int n){
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;//自己是自己的监护人
        siz[i] = 1;
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
        siz[pv] += siz[pu];
        p[pu] = pv;
    }
}

signed main(){
    int n, m;
    int cnt = 1,sum=0;
    while(scanf("%lld %lld", &n, &m)&&n!=0&&m!=0){
        init(n);
        while(m--){
            int a, b;
            scanf("%lld %lld", &a, &b);
            merge(a, b);
        }

        sum = 0;
        for (int i = 1; i <= n; i++)
            if (p[i] == i)
                sum++;

        printf("Case %lld: %lld\n", cnt, sum);
        cnt++;
    }
    return 0;
}