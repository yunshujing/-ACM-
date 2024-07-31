#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e6+10;
int a[maxn];

signed main(){
    int n, c;
    cin >> n >> c;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    // i 是用来枚举b
    // j and k are used to determine the interval range of a
    // i is used to determine the left endpoint of the interval
    // k is used to determine the right endpoint of the interval
    long long ans = 0;
    for(int i = 1, j = 1, k = 1; i <= n; i++) {
        while(j <= n && a[j] - a[i] < c) j++;
        while(k <= n && a[k] - a[i] <= c) k++;
        ans += k - j;
    }

    cout << ans << "\n";
    return 0;
}