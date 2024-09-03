#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;

int a[N][2];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, s, m; cin >> n >> s >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1];
		}
		if (a[1][0] >= s) {//ͷ
			cout << "YES" << "\n"; continue;
		}
		if (m - a[n][1] >= s) {//β
			cout << "YES" << "\n"; continue;
		}
		int l = a[1][0], r = a[1][1];
		int flag = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i][0] - r >= s) {
				flag = 1; break;
			}
			l = a[i][0], r = a[i][1];
		}
		if (flag == 1) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}