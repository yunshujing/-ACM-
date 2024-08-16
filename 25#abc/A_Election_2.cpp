#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, t, a;
    cin >> n >> t >> a;
    int sum = n - t - a;
    if(t+sum>a&&t<a||a<t&&a+sum>t||a==t){
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;

    return 0;
}