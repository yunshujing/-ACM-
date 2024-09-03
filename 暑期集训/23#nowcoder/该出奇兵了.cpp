#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
int b[N][2];
int a[N];
//vector <int> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> b[i][0] >> b[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    


    return 0;
}