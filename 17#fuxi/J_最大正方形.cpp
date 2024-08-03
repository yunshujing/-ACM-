#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

int a[1000][1000], sum[1000][1000];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
        }
    }

    int max = 0;
    for (int x1 = 1; x1 <= n;x1++){
        for (int y1 = 1; y1 <= m;y1++){
            for (int x = 0; x <= (n-x1); x++)
            {
                int x2 = x1 + x;
                int y2 = y1 + x;
                int s = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
                if(s==(x+1)*(x+1)&&(x+1)>max)
                    max = x+1;
            }
            /* 
            for (int x2 = x1; x2 <= n; x2++)
            {
                int len = x2 - x1 + 1;
                int y2 = y1 + len - 1;
                int s = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
                if (s == len * len && len > max)
                {
                    max = len;
                }
            } 
            */
        }
        
    }
    cout << max;

    return 0;
}
