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
vector<int> a(100010);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    while(m--){
        int l,r,ans=0;
        cin >> l >> r;
        int sum = a[l];
        for (int i = l+1; i <= r;i++){
            int x1 = a[i];
            sum = sum & x1;
        }
        cout << sum << endl;
    }
    return 0;
}

// for (int j = 1; j < n;j++){
//                 int x1 = a[i], x2 = a[j + 1];
//                 int y1 = i & x1 & x2;
//                 if(y1 == i){
//                     ans = i;
//                     continue;
//                 }
//             }