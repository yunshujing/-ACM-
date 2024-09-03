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
vector<int> a(N);
vector<int> s(N);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cin >> a[1];
    s[1] = a[1];
    for (int i = 2; i <= n;i++){
        cin >> a[i];
        s[i] = s[i] & s[i - 1];
    }
    while(m--){
        int l,r,ans=0;
        cin >> l >> r;
        // int sum = a[l];
        for (int i = l; i <= r;i++){
            int x1 = a[i];
            sum = sum & x1;
        }
        cout << sum << endl;
    }
    return 0;
}