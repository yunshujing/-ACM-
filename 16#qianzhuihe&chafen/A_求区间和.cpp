#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
const int maxn = 1e5 + 100;

int s[maxn];
int s2[maxn];

signed main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s2[i] = s[i] + s2[i - 1];//累计前i个的和的数组
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;//区间
		cout << s2[r] - s2[l - 1] << endl;//前r个的和 - 前l-1个的和 == l~r之间的和
	}
	return 0;
}