#define _CRT_SECURE_NO_WARNINGS

//A
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
double f(double x, double n) {
	if ((n == 1)) return sqrt(x + 1);
	if ((n == 0)) return 0.00;
	return sqrt(n + f(x,n - 1));
}
int main() {
	double x, n;
	while (cin >> x >> n) {
		cout << fixed << setprecision(2) << f(x, n) << endl;
	}
	return 0;
}


//B	
//#include<bits/stdc++.h>
//#include<cmath>
//using namespace std;
//double f(double x, double n) {
//	if ((n == 1)) return x / (1+x);
//	if ((n == 0)) return 0.00;
//	return x/(n+f(x,n-1));
//}
//int main() {
//	double x, n;
//	while (cin >> x >> n) {
//		cout << fixed << setprecision(2) << f(x, n) << endl;
//	}
//	return 0;
//}


//C
//#include<bits/stdc++.h>
//#include<cmath>
//using namespace std;
//#define lli long long int
//lli M(lli, lli);
//lli Max(lli, lli);
//lli Maxx(lli, lli);
//lli a[500005];
//int main() {
//	int n; 
//	while (cin >> n) {
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		cout << M(1, n) << endl;
//	}
//	return 0;
//}
//
//lli M(lli l, lli r) {
//	if (r - l <= 5) {
//		 return Max(l, r);
//	}
//	else {
//		lli mid = floor((l + r) / 2 );
//		lli left = M(l, mid);
//		lli right = M(mid + 1, r);
//		lli rightmax = Maxx(right, 7);
//		return (left % rightmax) + (a[mid-1] - 1);
//	}
//}
//
//lli Max(lli n, lli m) {
//	if (n > m) {
//		lli tmp = n;
//		n = m;
//		m = tmp;
//	}
//	lli maxx = a[n-1];
//	for (int j = n-1; j < m; j++) {
//		if (a[j] > maxx) {
//			maxx = a[j];
//		}
//	}
//	return maxx;
//}
//
//lli Maxx(lli q, lli w) {
//	if (q >= w)return q;
//	else return w;
//}


//D
//#include<bits/stdc++.h>
//using namespace std;
//void hanoi(int n, char a, char b, char c);
//int main() {
//	int n; char a, b, c;
//	while (~scanf("%d %c %c %c",&n,&a,&b,&c) ){
//		hanoi(n, a, c, b);
//	}
//	return 0;
//}
////把n给盘子从a柱移到c柱，借助中间柱b
//void hanoi(int n, char a, char b, char c) {
//	if (n == 0) return;
//	//1）上面的n-1个盘子从a柱移到中间柱b，借助c
//	hanoi(n - 1, a, c, b);
//	//2）最大的盘子n从a柱移动到c柱
//	printf("%c->%d->%c\n",a, n, c);
//	//3）上面从n-1个盘子从b柱到c柱
//	hanoi(n - 1, b, a, c);
//}


//E
//#include<bits/stdc++.h>
//using namespace std;
//void hanoi(int n, char a, char b, char c);
//int main() {
//	int n;
//	while (cin >> n) {
//		hanoi(n, 'A', 'B', 'C');
//	}
//	return 0;
//}
////把n给盘子从a柱移到c柱，借助中间柱b
//void hanoi(int n, char a, char b, char c) {
//	if (n == 0) return;
//	//1）上面的n-1个盘子从a柱移到中间柱b，借助c
//	hanoi(n - 1, a, c, b);
//	//2）最大的盘子n从a柱移动到c柱
//	printf("move %d# from %c to %c\n", n, a, c);
//	//3）上面从n-1个盘子从b柱到c柱
//	hanoi(n - 1, b, a, c);
//}


//F
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, l, i, a[10000];//a倒序放每位
//
//void mul() {//高精乘2
//	for (int i = 1; i <= l; i++)a[i] *= 2;//每位乘2
//
//	for (int i = 1; i <= l; i++)//满十进一(不会出现进2的情况)
//		if (a[i] > 9) {
//			a[i + 1]++;
//			a[i] -= 10;
//		}
//
//	if (a[l + 1] > 0)l++;//如高位进位，长度加1
//
//	return;
//}
//
//int main() {
//	cin >> n;
//	a[1] = 1;
//	l = 1;//答案初始长度为1
//
//	for (i = 0; i < n; i++)mul();//求2^n
//
//	for (i = l; i > 1; i--)cout << a[i];//打印高位
//	cout << a[1] - 1;//由于不可能出现末位为0的情况，输出末位减1即可
//
//	return 0;
//}


//G
//#include<bits/stdc++.h>
//using namespace std;
//
//#define LEN 1024
//int s[LEN][LEN];
//void Sm(int n, int ii, int jj);
//
//int main() {
//	int n;
//	while (cin >> n) {
//		n = (int)pow(2, n);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				s[i][j] = 1;
//			}
//		}//初始化
//
//		Sm(n, 0, 0);
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("%d ", s[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
////赦免
//void Sm(int n, int ii, int jj){
//		if (n >= 2) {
//			for (int i = ii; i < ii + n / 2; i++) {
//				for (int j = jj; j < jj + n/ 2; j++) {
//					s[i][j] = 0;
//				}
//
//			}
//		}
//		else return;
//
//		n = n / 2;
//		Sm(n, ii + n, jj);
//		Sm(n, ii, jj + n);
//		Sm(n, ii + n, jj + n);
//}


//H
//#include<bits/stdc++.h>
//#include<cmath>
//using namespace std;
//long long f(int);
//void initDP();
//int sum = 0;
//int main() {
//	int n;
//	while (cin >> n) {
//        initDP();
//		cout << f(n) << endl;
//	}
//	return 0;
//}
////int f(int x) {
////	if (x == 0) return 0;
////	int half = x / 2;
////	int sum = half; // 初始值为半数本身
////	for (int i = 1; i <= half; i++) {
////		sum += f(i); // 累加每个x的x/2的值
////	}
////	return sum;
////}
//
//#define MAX_N 1000000  // 假设 n 的最大值为 1000000，可以根据需要调整  
//
//// 使用 long long 以防溢出  
//long long dp[MAX_N + 1];
//
//// 初始化 dp 数组为 -1，表示这些值尚未计算  
//void initDP() {
//    for (int i = 0; i <= MAX_N; i++) {
//        dp[i] = -1;
//    }
//}
//
//// 递归函数，使用记忆化避免重复计算  
//long long f(int n) {
//    // 如果 dp[n] 已经被计算过，则直接返回结果  
//    if (dp[n] != -1) {
//        return dp[n];
//    }
//
//    // 初始化 dp[n] 为 1，因为至少有一个合法的数列（只包含 n 本身）  
//    dp[n] = 1;
//
//    // 遍历所有小于 n/2 的数，并累加它们的 dp 值到 dp[n]  
//    for (int i = 1; i <= n / 2; i++) {
//        dp[n] += f(i);
//    }
//
//    // 返回计算得到的结果  
//    return dp[n];
//}