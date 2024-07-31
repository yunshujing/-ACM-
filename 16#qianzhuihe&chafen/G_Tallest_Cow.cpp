#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

#define int long long
#define double long double
const int maxn = 1e5 + 100;

map<pair<int, int>, bool>cow;//去重
int s[maxn] = { 0 };

signed main() {
	int n, I, h, r; cin >> n >> I >> h >> r;
	// 几头  编号  高度  行
	while (r--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		if (cow[make_pair(a, b)]) {
			continue;
		}
		s[a+1]--; s[b]++;
		cow[make_pair(a, b)] = true;
	}
	for (int i = 1; i <= n; i++) {
		s[i] = s[i] + s[i - 1];
		cout << s[i] + h << "\n";
	}
	return 0;
}

