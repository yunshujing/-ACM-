#define _CRT_SECURE_NO_WARNINGS

//A
//#include<bits/stdc++.h>
//#include<cmath>
//using namespace std;
//double f(double x, double n) {
//	if ((n == 1)) return sqrt(x + 1);
//	if ((n == 0)) return 0.00;
//	return sqrt(n + f(x,n - 1));
//}
//int main() {
//	double x, n;
//	while (cin >> x >> n) {
//		cout << fixed << setprecision(2) << f(x, n) << endl;
//	}
//	return 0;
//}


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
////��n�����Ӵ�a���Ƶ�c���������м���b
//void hanoi(int n, char a, char b, char c) {
//	if (n == 0) return;
//	//1�������n-1�����Ӵ�a���Ƶ��м���b������c
//	hanoi(n - 1, a, c, b);
//	//2����������n��a���ƶ���c��
//	printf("%c->%d->%c\n",a, n, c);
//	//3�������n-1�����Ӵ�b����c��
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
////��n�����Ӵ�a���Ƶ�c���������м���b
//void hanoi(int n, char a, char b, char c) {
//	if (n == 0) return;
//	//1�������n-1�����Ӵ�a���Ƶ��м���b������c
//	hanoi(n - 1, a, c, b);
//	//2����������n��a���ƶ���c��
//	printf("move %d# from %c to %c\n", n, a, c);
//	//3�������n-1�����Ӵ�b����c��
//	hanoi(n - 1, b, a, c);
//}


//F
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, l, i, a[10000];//a�����ÿλ
//
//void mul() {//�߾���2
//	for (int i = 1; i <= l; i++)a[i] *= 2;//ÿλ��2
//
//	for (int i = 1; i <= l; i++)//��ʮ��һ(������ֽ�2�����)
//		if (a[i] > 9) {
//			a[i + 1]++;
//			a[i] -= 10;
//		}
//
//	if (a[l + 1] > 0)l++;//���λ��λ�����ȼ�1
//
//	return;
//}
//
//int main() {
//	cin >> n;
//	a[1] = 1;
//	l = 1;//�𰸳�ʼ����Ϊ1
//
//	for (i = 0; i < n; i++)mul();//��2^n
//
//	for (i = l; i > 1; i--)cout << a[i];//��ӡ��λ
//	cout << a[1] - 1;//���ڲ����ܳ���ĩλΪ0����������ĩλ��1����
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
//		}//��ʼ��
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
////����
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
////	int sum = half; // ��ʼֵΪ��������
////	for (int i = 1; i <= half; i++) {
////		sum += f(i); // �ۼ�ÿ��x��x/2��ֵ
////	}
////	return sum;
////}
//
//#define MAX_N 1000000  // ���� n �����ֵΪ 1000000�����Ը�����Ҫ����  
//
//// ʹ�� long long �Է����  
//long long dp[MAX_N + 1];
//
//// ��ʼ�� dp ����Ϊ -1����ʾ��Щֵ��δ����  
//void initDP() {
//    for (int i = 0; i <= MAX_N; i++) {
//        dp[i] = -1;
//    }
//}
//
//// �ݹ麯����ʹ�ü��仯�����ظ�����  
//long long f(int n) {
//    // ��� dp[n] �Ѿ������������ֱ�ӷ��ؽ��  
//    if (dp[n] != -1) {
//        return dp[n];
//    }
//
//    // ��ʼ�� dp[n] Ϊ 1����Ϊ������һ���Ϸ������У�ֻ���� n ����  
//    dp[n] = 1;
//
//    // ��������С�� n/2 ���������ۼ����ǵ� dp ֵ�� dp[n]  
//    for (int i = 1; i <= n / 2; i++) {
//        dp[n] += f(i);
//    }
//
//    // ���ؼ���õ��Ľ��  
//    return dp[n];
//}