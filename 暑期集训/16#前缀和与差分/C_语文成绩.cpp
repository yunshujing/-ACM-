#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
const int maxn = 1e7 + 100;

//前缀和 ：某一序列前 n 项的和  (我昨天的C题就是用前缀和过的，否则会 TL)

/*
差分数组
原数组（差分数组的前缀和数组）
前缀和数组（原数组的前缀和数组）
*/
//修改差分 -> 原数组
//s2[x]+1 s2[x+1]-1 -> [x-y]

int a[maxn] = { 0 };
int b[maxn] = { 0 };

signed main() {
	int n, p; cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];//原数组
	}
	while (p--) {
		int x, y, z; cin >> x >> y >> z;//调整
		b[x] += z;
		b[y + 1] -= z;//y之后不要加分，提前减去用来后续不加上
	}
	int minn = a[1] + b[1];
	for (int i = 1; i <= n; i++) {
		b[i] = b[i] + b[i - 1];//将差分数组变成原数组，根据前面的差分进行相加
		a[i] = a[i] + b[i];    //将两个数组相加//原数字加上差分
		minn = min(minn, a[i]);
	}
	cout << minn << endl;
}