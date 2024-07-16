#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<math.h>
//int rn(int);
//int main() {
//	int n = 0, x, y; int a[10000] = { 0 };
//	while (~scanf("%d %d", &x,&y)&&x<y ) {
//		if ((y - x) > 4) {
//			while (1) {
//				if (x % 4 == 0) {
//					break;
//				}
//				else {
//					x++;
//				}
//			}
//			for (int i = x; i <= y; i += 4) {
//				if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
//					a[n] = i;
//					n++;
//
//				}
//			}
//		}
//		else {
//			for (int i = x; i <= y; i++)
//			{
//				if (rn(i)) {
//					a[n] = i;
//					n++;
//				}
//			}
//		}
//		printf("%d\n", n);
//		for (int i = 0; i < n; i++)
//		{
//			printf("%d ", a[i]);
//		}
//	}
//	return 0;
//}
//
//int rn(int m) {
//	if ((m % 4 == 0 && m % 100 != 0) || m % 400 == 0) {
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}


//#include<bits/stdc++.h>
//bool isPrime(int x);
//int main() {
//	int n; 
//	while (~scanf("%d",&n))
//	{
//		for (int i = 4; i <= n; i=i+2)//waicen
//		{
//			int flag = 1;
//			for (int j = 2; j < i; j++) {//neicen
//				
//				if (isPrime(j)) {
//					if (isPrime(i - j))
//						if (flag)
//						{
//							printf("%d=%d+%d\n", i, j, i - j); 
//							flag = 0;
//						}
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//bool isPrime(int x) {
//	if (x < 2)
//	{
//		return false;
//	}
//	//试除法
//	for (int i = 2; i <= x / i; i++)
//	{
//		if (x % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}


//#include<cstdio>
//#include<math.h>
//bool isPrime(int);
//int panduan(int);
//
//int main(){
//	int a, b;
//	while (~scanf("%d %d",&a,&b))
//	{
//		for (int i = a; i <= b; i++) {
//			printf("%d", panduan(i));
//			if (i!=b)
//			{
//				printf(",");
//			}
//		}
//	}
//	return 0;
//}
//
//bool isPrime(int x) {
//		if (x < 2)
//		{
//			return false;
//		}
//		//试除法
//		for (int i = 2; i <= x / i; i++)
//		{
//			if (x % i == 0) {
//				return false;
//			}
//		}
//		return true;
//	}
//
//int panduan(int i) {
//	if (isPrime(i)) {
//		return i;
//	}
//	else {
//		int max=2;
//		for (int j = 2; j < i; j++) {
//			if (i % j == 0 && isPrime(j)) {
//				if (j > max)max = j;
//			}
//		}
//		return max;
//	}
//}


//
//#include<stdio.h>
//bool huiwen(int);
//bool isPrime(int);
//int main() {
//	int a, b;
//	while (~scanf("%d %d", &a, &b)&&a>=5&&b<=1e8) {
//		for (int i = a; i <= b; i++) {
//			if (i == 9989900) break;
//			if(huiwen(i)&&(isPrime(i))){
//				printf("%d\n", i);
//			}
//		}
//	}
//	return 0;
//}
//
//bool isPrime(int x) {
//	if (x < 2)return false;
//	if (x == 2 || x == 3) return true; // 2 和 3 是质数
//	if (x % 2 == 0) return false;       // 排除偶数  
//	for (int i = 3; i*i <= x ; i+=2){   //试除法
//		if (x % i == 0) return false;
//	}
//	return true;
//}
//
//
//bool huiwen(int x) {
//		int b = x;
//		int c, s = 0;
//		while (b) {
//			c = b % 10;
//			b /= 10;
//			s = s * 10 + c;
//		}
//		return s == x;
//}

#include<bits/stdc++.h>
using namespace std;

void TH(string &y);//替换排序
int main() {
	string x, y, z, k;
	while (cin >> x >> y) {//输入流
		TH(y);
		int length = y.length();
		char a[1000], b[1000]; int i = 0, flag = 0;
		for (char& c : y) {
			a[i] = c;
			i++;
		}
		for (char& c : x) {
			b[i] = c;
			i++;
		}
		for (int i = 0; i < length; i++)
		{
			for (int j = i; j < length; j++)
			{
				flag = 0;
				if (a[i] == b[j])flag = 1;
			}
		}
		if (flag) {
			cout << "YES" << endl;//输出流
		}
		else cout << "NO" << endl;
	}
	return 0;
}
void TH(string &y) {  //&y为提取y值,实参到形参
	for (char &c : y) //for循环遍历字符串中的每个字符，把y提取到字符c
		c = (c - 'A' + 1) % 26 + 'A';
}



//#include<bits/stdc++.h>
//int main() {
//
//
//
//}

//#include<bits/stdc++.h>
//int main() {
//
//}

//#include<stdio.h>
//int main() {
//	int n, m; double a[100] = { 0.00 };
//	int x = 0, sum = 0;
//	double f = 0.00;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		int max = 0, min = 10;
//		for (int j = 0; j < m; j++) {
//			scanf("%d", &x);
//			if (x >= max) {
//				max = x;
//			}
//			if (x <= min) {
//				min = x;
//			}
//			sum += x;
//		}
//		double f = (sum - max - min) * 1.00 / (m - 2);
//		a[i] = f;
//		sum = 0;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (a[i] < a[j]) {
//				double tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp;
//			}
//		}
//	}
//	printf("%.2lf", a[0]);
//	return 0;
//}


//#include<stdio.h>
//struct Student
//{
//	char name[10];
//	int yuwen;
//	int shuxue;
//	int yinyu;
//}a[1000];
//
//int main() {
//	int n, m = 0, max = 0; 
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%s %d %d %d", &a[i].name, &a[i].yuwen, &a[i].shuxue, &a[i].yinyu);
//		int sum = a[i].yuwen + a[i].shuxue + a[i].yinyu;
//		if (sum>m)
//		{
//			m = sum;
//			max = i;
//		}
//	}
//	printf("%s %d %d %d", a[max].name, a[max].yuwen, a[max].shuxue, a[max].yinyu);
//	return 0;
//}