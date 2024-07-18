#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>����ͷ

//Day1
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
*/

//Day2
/*
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


//��������
```c
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
```

//��������
```c
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
```
*/

//Day3
/*
## �ݹ�
1���ݹ����
2���ݹ����


### ����1�����һ����׳˵ĵݹ麯��

1����ʽ����д��һ������������ֻ��һ��
��f(n) = n!

2���ֽ����⣬β�ݹ飬��n�ó������������ɣ�n - 1����

3���ҵ������ԣ��õ�����ʽ
n!= (n - 1)!*n
f(n) = f(n - 1) * n

4���ݹ����
n > n - 1 > n - 2 > n - 3 > ...... > 0


### ����2�����һ����⺺ŵ���ĵݹ麯��

1����ʽ����д��һ��������������4��
```c
//��n�����Ӵ�a���Ƶ�c���������м���b
void hanoi(int n, char a, char b, char c);
```
2���ֽ����⣬β�ݹ飬����������n�ó������ֽ��n�����Ӻ������n - 1������

3���ҵ������ԣ��õ�����ʽ
```c
//1�������n-1�����Ӵ�a���Ƶ��м���b������c
hanoi(n - 1, a, c, b);
//2����������n��a���ƶ���c��
printf("move %d# from %c to %c\n", n, a, c);
//3�������n-1�����Ӵ�b����c��
hanoi(n - 1, b, a, c);
```
4���ݹ����
n > n - 1 > n - 2 > n - 3 > ...... > 0

�������룺
```c
#include<bits/stdc++.h>
using namespace std;
void hanoi(int n, char a, char b, char c);
int main() {
	int n;
	while (cin >> n) {
		hanoi(n, 'A', 'B', 'C');
	}
	return 0;
}
//��n�����Ӵ�a���Ƶ�c���������м���b
void hanoi(int n, char a, char b, char c) {
	if (n == 0) return ;
	//1�������n-1�����Ӵ�a���Ƶ��м���b������c
	hanoi(n - 1, a, c, b);
	//2����������n��a���ƶ���c��
	printf("move %d# from %c to %c\n", n, a, c);
	//3�������n-1�����Ӵ�b����c��
	hanoi(n - 1, b, a, c);
}
```


### ����3���ַ�������

1����ʽ����д��һ��������������1��
```c
//�ַ���s����
void reverse(char *s);
```
2���ֽ����⣬β�ݹ飬�ѵ�һ���ַ�s[0]�ó������ֳ�2�������ַ�s[0]��ʣ����ַ�������ʼ��ַ��s + 1��

3���ҵ������ԣ��õ�����ʽ
```c
//1���ѵ�һ���ַ��ŵ�����
char ts[2] = { s[0] };
strcat(s + 1, ts);
```
4���ݹ����
n > n - 1 > n - 2 > n - 3 > ...... > 0

�������룺
```c
```


### ����4��x����

1����ʽ����д��һ��������������1��
```c
//�ַ���s����
void reverse(char* s);
```
2���ֽ����⣬������ѡ��
��1�����ӿ������վ��f(a - 1, b + 1)
��2�����վ����1������f(a, b - 1)

3���ҵ������ԣ��õ�����ʽ
```c
f(a, b) = f(a - 1, b + 1) + f(a, b - 1);
```
4���ݹ����
n > n - 1 > n - 2 > n - 3 > ...... > 0

��������
```c
#include<bits/stdc++.h>
using namespace std;
int f(int, int);
int main() {
	int n;
	while (cin >> n) {
		cout << f(n, 0) << endl;
	}
	return 0;
}
//��վ���򣬳�����a���������վ��b����
int f(int a, int b) {
	if (a == 0) {
		return 1;
	}
	if (b == 0) {
		return f(a-1,1);
	}
	return f(a - 1, b + 1) + f(a, b - 1);
}
```

*/

//Day4
/*
## ָ��
```c
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a = 10;
	scanf("%d",&a);				//& Ϊȡ��ַ��
	cout << *(&a) << endl;		//* Ϊ�����÷���ȡ����ַ�е�ֵ
	return 0;
 }

int main() {
	int a = 10;
	int* pa = &a;
	*pa = 11;
	cout << *pa << endl;	//11
	cout << a << endl;		//11	
	return 0;
 }
```

## sort()����ʹ�÷���
#### sort()�Ķ���
sort()�������ԶԸ�����������Ԫ�ؽ�������
������������sort(begin, end, cmp)��
beginΪָ���sort()������ĵ�һ��Ԫ�ص�ָ�룬
endΪָ���sort()����������һ��Ԫ�ص���һ��λ�õ�ָ�룬
cmp����Ϊ����׼��cmp�������Բ�д��Ĭ�ϴ�С�����������

����ֵ����
ʱ�临�Ӷȣ�O(nlogn)
����Χ��[first,last)
```c
int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	sort(a + 0, a + 2 + 1,cmp);		//����ǰ��λ
	for(int i = 0;i < 10;i++)
	cout << a[i] << endl;	
	return 0;
}
```
#### bool����cmp�Զ�������
```c
bool cmp(int e1, int e2) {	//int ��Ӧ int a[10]
	return e1 > e2;	//����Ϊtrue������������Ϊfalse����
}
```
#### �ṹ������
sort()Ҳ���ԶԽṹ���������
�������Ƕ���һ���ṹ�庬��ѧ���������ͳɼ��Ľṹ��Student��
Ȼ�����ǰ���ÿ��ѧ���ĳɼ��Ӹߵ��׽��������������ǽ��ṹ�嶨��Ϊ��
```c
struct Student {
	string name;
	int score;
};
```
��������Ҫ�����ǿ��Խ�����׼����дΪ��
```c
bool cmp_score(Student x, Student y) {
	return x.score > y.score;
}
```
�������룺
```c
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Student {
	string name;
	int score;
	Student() {}
	Student(string n, int s) :name(n), score(s) {}
};

bool cmp_score(Student x, Student y) {
	return x.score > y.score;
}

int main() {
	Student stu[3];
	string n;
	int s;
	for (int i = 0; i < 3; i++) {
		cin >> n >> s;
		stu[i] = Student(n, s);
	}

	sort(stu, stu + 3, cmp_score);

	for (int i = 0; i < 3; i++) {
		cout << stu[i].name << " " << stu[i].score << endl;
	}

	return 0;
}
```
### ������
boolֻ��0Ϊ�٣�������Ϊ��

cin, cout:���ݴﵽ1e6��1e7����������Ϊscanf��printf 

#define int long long
������һ����ʱ���������ˣ���
#define ll long long

�����飺
const int N = 1e6 + 10;
int a[N];




#### ���⣺
#B3827[NICA #2] �߿�����

##��Ŀ����

�߿����ܾ���ÿ���������˵Ŀ��ԣ������Ϊ����˵� Aya ���߿������Ϊ����֮�ء����� Aya �� $n$ ����ѡ�ĸ߿��⡣

����ÿһ������ѡ���Ծ�ĸ߿��⣬���� $k$ ��ָ�������������������ά�ȣ������Ѷȡ���ӱ�ȡ�����ʵ����Ľ���Եȡ�ÿ��ָ���Ϊһ����������

Aya ��Ϊ��һ���ⱻ����߿���ı�Ҫ�ԣ�����Щָ���ƽ��ֵ������Ϊ����Ҫ��ǰ���ߵ��������Ҫ���Ž��߿��Ծ����ж����Ҫ��ǰ�����������ѡ�������ֵ��Ǹ�������� Aya �ĸ���Ŀ�Ǳ���Ҫ�Ž��߿��Ծ�ġ�

##�����ʽ

��һ���������������� $n,k$����������������

�ڶ��п�ʼ������ $n$ �У�ÿ������ $k$ �����������Կո�������� $i$ �б�ʾ�� $i-1$ ����ĸ���ָ���Ƕ��١�

##�����ʽ

������У���ʾ��Ҫ��ǰ������������������⡣���������Ҫ����ߵģ����ж����Ŀ��Ҫ����ͬ�����������������ֵġ�

##���� #1

###�������� #1

```
3 2
10 20
15 25
20 30
```

###������� #1

```
3
2
```

##���� #2

###�������� #2

```
3 2
10 20
5 25
1 2
```

###������� #2

```
1
2
```

##��ʾ

���ݱ�֤��$2 \leq n \leq 100$��$1 \leq k \leq 10$��$1 \leq$ һ������ĸ���ָ�� $\leq 100$��


```c
#include<bits/stdc++.h>
using namespace std;
struct Student {
	int X;
	double Num;
};

typedef Student student;
student a[100];
bool cmp(student e1, student e2);

int main() {
	int n, k;
	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < k; j++) {
				int tmp;
				cin >> tmp;
				sum += tmp;
			}
			a[i].X = i + 1;
			a[i].Num = sum/k;
		}
		sort(a, a + n, cmp);
		cout << a[0].X << endl << a[1].X << endl;

	}

}

bool cmp(student e1, student e2) {	
	if(e1.Num!=e2.Num)
	return e1.Num > e2.Num;
	else return e1.X < e2.X;
}
```
*/

