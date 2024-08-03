#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a;
    for (int i = 1; i <=n; i++)
    {
        a.push_back(i);
    }
    if(l!=r)
    reverse(a.begin()+l-1, a.begin()+r);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}