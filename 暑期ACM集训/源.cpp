#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>

/*
//����ȫƽ����

int main() {
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			int n = a * 1100 + b * 11;
			double x = sqrt(n);
			if (fabs(x - (int)x) < 1e-6) {//��ȫƽ���� ��0.000001�ж� 
				printf("%d %.0f\n", n, x);
			}
		}
	}
}



//�׳�֮�͵�ĩ6λ�� 
#include<bits/stdc++.h>
const int M = 1e6;
int main() {
	freopen("2.in", "r", stdin);//�����ض���2.in
	freopen("2.out", "w", stdout);//����ض���2.out 
	int n;
	while (~scanf("%d", &n)) {
		long long s = 0, f = 1;
		for (int i = 1; i <= n; i++) {
			f = f * i % M;   //i!
			s = (s + f) % M; //�׳˺� 
		}
		printf("%lld %lld\n", n, s);
	}
}



//c(n,m)=n!/(m!*(n-m)!)
#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;  //ll 2^63-1>>unsigned 2^64-1 ���һ��
//��׳�
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


//��������
//``c++
#include<cstdio>
#include<iostream>     //���������
using namespace std;   //ʹ�����ֿռ�std
//�ж�x�Ƿ�����
bool isPrime(int x);
int main() {
	int m;
	while (cin >> m)  //cin��������istream�����>>����ȡ��������浽m��
	{
		//�Ӵ�Сö��
		for (int i = m; i >= 5; i--)
		{
			if (isPrime(i) && isPrime(i - 2)) {
				//cout�������ostream��Ķ���<<�ǲ������������˳�����С�ġ��ո񡢴�ġ����У�endl�ǻ���
				cout << i - 2 << " " << i << endl; break;
			}
		}
	}
	return 0;
}
//�������壬�����ж�
bool isPrime(int x) {
	if (x < 2)
	{
		return false;
	}
	//�Գ���
	for (int i = 2; i <= x/i; i++)
	{
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}


//��������
#include<cstdio>
#include<iostream>       //���������
using namespace std;     //ʹ�����ֿռ�std
//����2������
void swap(int&, int&);   //����������Ϊ�����β�,������ָ��

int main() {
	int a,b;
	while (cin >> a >> b)  //cin��������istream�����>>����ȡ��������浽m��
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