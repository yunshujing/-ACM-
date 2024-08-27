#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 2e5 + 10;
const double eps =1e-4;
int n, k;
vector<int> v[N];
vector<int>s[N];
int sum = 0;
map<int, int> mp;

void dfs(int x,vector <int> g){
    if(mp.find(g.back())!= mp.end()){
        sum += vis.size();
        break;
    }
    for()
    
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> k;
    for (int i = 1; i <= n - 1;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= k;i++){
        cin >> s[i];
        mp[s[i]] = 1;
    }
    for (int i = 1; i <= k;i++){
        dfs(s[i],{});
    }


        return 0;
}