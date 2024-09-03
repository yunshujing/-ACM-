#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;
int a[1000],x[1000][1000],sum[1000];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x[i][j];
            sum[j] += x[i][j];
        }
    }

    for (int z = 1; z <= m;z++){
        if(a[z]>sum[z]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}