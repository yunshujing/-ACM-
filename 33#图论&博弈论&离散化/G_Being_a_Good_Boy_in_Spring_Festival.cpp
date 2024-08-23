#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;
int a[1001000];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    while(cin>>n&&n){
        int sum = 0;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            sum ^= a[i];
        }
    
        int ans=0;
        for (int i = 1; i <= n;i++){
            if(a[i] >= (sum^a[i])){
                ans++;
            }
        }
        if (sum == 0)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}
