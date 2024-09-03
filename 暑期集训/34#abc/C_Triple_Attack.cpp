#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
const int maxn = 2e5 + 100;
const double eps = 1e-5;

int s[maxn] = { 0 };

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int t = 1; int I = 1;//敌人的编号
    int k = 5;//3 1 1
    while (I <= n) {
        if (s[I] <= 0) {
            I++; continue;
        }
        if (t % 3 != 0) {
            t++; s[I]--; continue;
        }
        t += (s[I] / 5) * 3; s[I] %= 5;
        while (s[I] > 0) {
            if (t % 3 == 0) {
                t++; s[I] -= 3;
            }
            else {
                t++; s[I]--;
            }
        }
    }
    cout << t - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);//控制小数位数
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}