#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 2e5 + 10;
const double eps =1e-4;

set<int> st1;
set<int> st2;

void solve(){
    st1.clear();
    st2.clear();
    int cnt = 0;
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if(y==1){
            st1.insert(x);
        }
        else{
            st2.insert(x);
        }
    }
    for(auto x:st1){
        if(st2.count(x)){
            cnt += (n - 2);
        }
        if(st2.count(x-1)&&st2.count(x+1)){
            cnt++;
        }
    }
    for(auto x:st2){
        if(st1.count(x-1)&&st1.count(x+1)){
            cnt++;
        }
    }
    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}