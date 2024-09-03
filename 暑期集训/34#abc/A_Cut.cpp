#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n, k;
    cin >> n >> k;
    deque<int> v;
    for (int i = 0; i < n;i++){
        int c;
        cin >> c;
        v.push_back(c);
    }
    while(k--){
        int u = v[n - 1];
        v.push_front(u);
        v.pop_back();
    }
    for(auto t:v){
        cout << t << ' ';
    }
        return 0;
}