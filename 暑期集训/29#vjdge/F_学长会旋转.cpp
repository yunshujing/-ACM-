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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    int a[n + 1][n + 1],b[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    k = k % 4;
    if(k==0){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n;j++){
                cout << a[i][j]<<" ";
            }
        cout << endl;
        }
        return 0;
    }
    if(k==1){
        for (int i = 1; i <= n; i++){
            for (int j = n; j >= 1;j--){
                cout << a[j][i]<<" ";
            }
        cout << endl;
        }
        return 0;
    }
    if(k==2){
        for (int i = n; i >= 1; i--){
            for (int j = n; j >= 1;j--){
                cout << a[i][j]<<" ";
            }
        cout << endl;
        }
        return 0;
    }
    if(k==3){
        for (int i = n; i >= 1; i--){
            for (int j = 1; j <= n;j++){
                cout << a[j][i]<<" ";
            }
        cout << endl;
        }
        return 0;
    }
    return 0;
}