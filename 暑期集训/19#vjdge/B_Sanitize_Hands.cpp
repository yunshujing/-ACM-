#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n>>m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // sort(a + 1, a + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if(m>=a[i]){
            m -= a[i];
            cnt++;
        }
        else
            break;
    }
    cout << cnt << endl;
    return 0;
}