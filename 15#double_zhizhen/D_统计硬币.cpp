#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        int cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                int k = n - i - j;
                {
                    if ( i + 2 * j + 5 * k == m)
                    {
                        cnt++;
                    }
                }
            }
        }
    cout << cnt << endl;
    }
    return 0;
}