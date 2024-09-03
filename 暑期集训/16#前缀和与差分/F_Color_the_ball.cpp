#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int x[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    while(cin >> n&&n!=0){
        fill(x, x + N, 0);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            x[a]++;
            x[b + 1]--;
        }
        for (int k = 1; k <= n;k++){
            x[k] += x[k - 1];
            cout << x[k] << (k < n ? " " : "\n");
        }
    }
    return 0;
}