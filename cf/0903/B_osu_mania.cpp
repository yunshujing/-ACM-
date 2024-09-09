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
    int m;
    cin >> m;
    deque<int> x;
    char t;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < 4;j++){
            cin >> t;
            if(t=='#'){
                x.push_front(j);
            }
        }
    }
    for (int i = 0; i < x.size();i++)
    {
        cout << x[i]+1 << " \n"[i == x.size() - 1];
    }
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