#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		map<int, int>s;
		//种类 其的数目
		//存储
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			auto it = s.find(tmp);
			if (it != s.end()) {
				s[tmp]++;
			}
			else {
				s[tmp] = 1;
			}
		}
		int name; int max_num = 0; int sum_num = 0;
		for (auto x : s) {
			sum_num += x.second;
			if (x.second > max_num) {
				max_num = x.second; 
                name = x.first;
			}
		}

		int cnt = 0;
		while (max_num < sum_num) {//查杀
			cnt++; cnt += max_num;
			max_num *= 2;
		}
		cnt -= max_num - sum_num;
		printf("%d\n", cnt);
	}
	return 0;
}