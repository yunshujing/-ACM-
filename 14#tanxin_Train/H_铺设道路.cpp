#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int a[N];
    cin >> a[0];
    int min = a[0];
    int sum = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if(min<a[i]){
            sum += a[i] - min;
        }
        min = a[i];
    }
    cout << sum << endl;
    return 0;
}
