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

vector<int> r(9);
int n, k;
int sum = 0;

void dfs(vector<int> g,int cnt,vector<int> r){
    if(cnt == n+1){
        if(sum%k==0){
            for(int i = 0 ;i < n; i++){
                cout << g[i] << " ";
            }
            cout  <<  endl;
        }
        return;
    }
    for(int i = 1 ; i <= r[cnt]; i++){
        g.push_back(i);
        sum += i;
        dfs(g, cnt + 1,r);
        g.pop_back();
        sum -= i;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> r[i];
    }

    dfs({}, 1, r);

    return 0;
}