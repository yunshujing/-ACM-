#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    
    int cnt=max(2*((x+k-1)/k)-1,2*((y+k-1)/k));
    cout << cnt << endl;
    /* if(x<k&&y<k){
        cnt += 2;
        cout << cnt << endl;
        return;
    } */
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    while(n--){
        solve();
    }

    return 0;
}
