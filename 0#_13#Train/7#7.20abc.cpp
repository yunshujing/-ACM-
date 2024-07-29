#define _CRT_SECURE_NO_WARNINGS


//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N = 1e6 + 10;
// 
//for (int i = 0; i < n; i++){}
//scanf("%d", &n);
//printf("%d", n);
// 结构体
//struct Student {
//    int x;
//    string name;
//    char zy;
//    int sld;
//};

//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//int main() {
//	int n;
//	cin >> n;
//	if (n >= 1 && n <= 99) {
//		cout << 100 - n;
//	}
//	if (n >= 100 && n <= 199) {
//		cout << 200 - n;
//	}
//	if (n >= 200 && n <= 299) {
//		cout << 300 - n;
//	}
//	if (n >= 300 && n <= 299) {
//		cout << 400 - n;
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//int main() {
//	int n, t, p,cnt=0;
//	int a[10000];
//	cin >> n >> t >> p;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		if (a[i] >= t)cnt++;
//	}
//	if (cnt >= p) {
//		cout << '0';
//	}
//	else {
//		for (int i = 0; i < n; i++) {
//			for (int j = i; j < n; j++) {
//				if (a[i] > a[j]) {
//					int temp = a[i];
//					a[i] = a[j];
//					a[j] = temp;
//				}
//			}
//		}
//		cout << t - a[n - p];
//	}
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
#define int long long
//bool huiwen(int);
static long find(int index);
signed main() {
	int n; int cnt = 0;
	cin >> n;
    if (n == 1)cout << '0';
    else if (n == 2)cout << '1';
    long res = find(n-2);
    cout << res;
	return 0;
}
static long find(int index) {
    int count = 0;
    int number = 9;                        //记录数位上的回文数，如个位回文数为9
    int w = 0;                            //记录数位

    long half;                            //保存回文数的左半边的结果
    long h = 1;                            //回文数的左半边的起始基数
    long res;                            //结果

    while (true) {
        if (w > 0 && w % 2 == 0) {            //每进两个数位，回文数乘以10
            number *= 10;
        }
        w++;                            //数位加一
        if (count + number > index)        //回文数大于查找的回数,跳出
            break;

        count += number;                //回文数加上当前数位上的回文数
    }

    index -= count;                        //在当前数位上的位置。如w=5,index=50,则万位上的第50个回文数是我们所求

    for (int i = 0; i < (w - 1) / 2; i++) {    //求回文数的左半边的基数，如回文数在万位上，则为100
        h *= 10;
    }

    half = h + index;                        //回文数的左半边，如100 + 50 = 150

    res = half;

    if (w % 2 != 0)                            //如果为奇数，则中间那个数不必算入右半边了！
        half /= 10;

    while (half != 0) {                        //拼接回文数
        res = res * 10 + half % 10;
        half /= 10;
    }

    return res;
}
