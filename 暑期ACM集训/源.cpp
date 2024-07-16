#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>

/*
//找完全平方数

int main() {
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			int n = a * 1100 + b * 11;
			double x = sqrt(n);
			if (fabs(x - (int)x) < 1e-6) {//完全平方数 用0.000001判断 
				printf("%d %.0f\n", n, x);
			}
		}
	}
}



//阶乘之和的末6位数 
#include<bits/stdc++.h>
const int M = 1e6;
int main() {
	freopen("2.in", "r", stdin);//输入重定向到2.in
	freopen("2.out", "w", stdout);//输出重定向到2.out 
	int n;
	while (~scanf("%d", &n)) {
		long long s = 0, f = 1;
		for (int i = 1; i <= n; i++) {
			f = f * i % M;   //i!
			s = (s + f) % M; //阶乘和 
		}
		printf("%lld %lld\n", n, s);
	}
}



//c(n,m)=n!/(m!*(n-m)!)
#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;  //ll 2^63-1>>unsigned 2^64-1 变大一倍
//求阶乘
ull f(int);
int main() {
	int n, m;
	while (~scanf("%d %d", &n,&m)) {
		int x = f(n) / (f(m) * f(n - m));
		printf("c(%d,%d) = %d\n", x);
	}
	return 0;
}

ull f(int n) {
	int x = 1;
	for (int i = 1; i <= n; i++)
	{
		x *= i;
	}
	return x;
}
*/


//孪生素数
//``c++
#include<cstdio>
#include<iostream>     //输入输出流
using namespace std;   //使用名字空间std
//判断x是否素数
bool isPrime(int x);
int main() {
	int m;
	while (cin >> m)  //cin是输入流istream类对象，>>是提取运算符，存到m中
	{
		//从大到小枚举
		for (int i = m; i >= 5; i--)
		{
			if (isPrime(i) && isPrime(i - 2)) {
				//cout是输出流ostream类的对象，<<是插入运算符，按顺序输出小的、空格、大的、换行，endl是换行
				cout << i - 2 << " " << i << endl; break;
			}
		}
	}
	return 0;
}
//函数定义，素数判断
bool isPrime(int x) {
	if (x < 2)
	{
		return false;
	}
	//试除法
	for (int i = 2; i <= x/i; i++)
	{
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}


//引用类型
#include<cstdio>
#include<iostream>       //输入输出流
using namespace std;     //使用名字空间std
//交换2个整数
void swap(int&, int&);   //引用类型作为函数形参,来代替指针

int main() {
	int a,b;
	while (cin >> a >> b)  //cin是输入流istream类对象，>>是提取运算符，存到m中
	{
		swap(a, b);
		cout << a << "," << b << endl;
	}
	return 0;
}

void swap(int&x, int&y) {
	int t = x;
	x = y;
	y = t;
}