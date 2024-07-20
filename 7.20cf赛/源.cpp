#define _CRT_SECURE_NO_WARNINGS


//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N = 1e6 + 10;
// 
//for (int i = 0; i < n; i++){}
//scanf("%d", &n);
//printf("%d", n);
// ½á¹¹Ìå
//struct Student {
//    int x;
//    string name;
//    char zy;
//    int sld;
//};

#include<bits/stdc++.h>
using namespace std;
#define in long long
signed main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m; cin >> m;
		vector <int> a;
		for (int i = 0; i < m; i++)
		{
			int num; cin >> num;
			a.push_back(num);
		}
		int max1, max2, p = 0, q = 0; int flag = 1, f2 = 0; int tep = 0, tmp = 0; int k;
		if (m == 2) k = 2; else k = (m + 1) / 2;
		for (int i = 0; i < k; i++)
		{
			//a
			flag = 0; max1 = 0; 
			for (int i = 0; i < m; i++) {
				if (a[i] > max1) {
					max1 = a[i];
					p = i;
				}
			}
			tep = max1;
			if (tep >= tmp) {
				flag = 1;
				a[p] = 0;
			}
			else
			{
				flag = 0;
				break;
			}
			//ds
			max2 = 0;
			for (int j = 0; j < m; j++) {
				if (a[j] > max2) {
					max2 = a[j];
					q = j;
				}
			}
			tmp = max2;
			if (tep>tmp)
			{
				flag = 1;
				break;
			}
			else {
				a[q] = 0;
			}
		}
		if (flag == 1)cout << "YES"<<endl;
		else
		{
			cout << "NO"<<endl;
		}
	}
	return 0;
}