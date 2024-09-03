#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;
int a[N], b[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        b[i]=a[i]*a[i+1];
        cout<<b[i]<<(i < n - 1 ? " " : "\n");
    }

    return 0;
}