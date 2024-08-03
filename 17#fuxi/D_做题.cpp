#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a+1, a + n+1);

    int k = 1;
    int cnt = 0;
    for (int i = 1; i <=n; i++)
    {
        if(a[i]>=k){
            k++;
        }
    }
    cout << k-1 << endl;

    return 0;
}