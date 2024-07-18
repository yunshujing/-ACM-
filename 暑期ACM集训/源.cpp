#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>万能头

//Day1
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
*/

//Day2
/*
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


//孪生素数
```c
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
```

//引用类型
```c
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
```
*/

//Day3
/*
## 递归
1、递归调用
2、递归出口


### 案例1：设计一个求阶乘的递归函数

1）形式化，写成一个函数，参数只有一个
令f(n) = n!

2）分解问题，尾递归，把n拿出来，子问题变成（n - 1）！

3）找到相似性，得到递推式
n!= (n - 1)!*n
f(n) = f(n - 1) * n

4）递归出口
n > n - 1 > n - 2 > n - 3 > ...... > 0


### 案例2：设计一个求解汉诺塔的递归函数

1）形式化，写成一个函数，参数有4个
```c
//把n给盘子从a柱移到c柱，借助中间柱b
void hanoi(int n, char a, char b, char c);
```
2）分解问题，尾递归，把最大的盘子n拿出来，分解成n号盘子和上面的n - 1个盘子

3）找到相似性，得到递推式
```c
//1）上面的n-1个盘子从a柱移到中间柱b，借助c
hanoi(n - 1, a, c, b);
//2）最大的盘子n从a柱移动到c柱
printf("move %d# from %c to %c\n", n, a, c);
//3）上面从n-1个盘子从b柱到c柱
hanoi(n - 1, b, a, c);
```
4）递归出口
n > n - 1 > n - 2 > n - 3 > ...... > 0

完整代码：
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
//把n给盘子从a柱移到c柱，借助中间柱b
void hanoi(int n, char a, char b, char c) {
	if (n == 0) return ;
	//1）上面的n-1个盘子从a柱移到中间柱b，借助c
	hanoi(n - 1, a, c, b);
	//2）最大的盘子n从a柱移动到c柱
	printf("move %d# from %c to %c\n", n, a, c);
	//3）上面从n-1个盘子从b柱到c柱
	hanoi(n - 1, b, a, c);
}
```


### 案例3：字符串逆序

1）形式化，写成一个函数，参数有1个
```c
//字符串s逆序
void reverse(char *s);
```
2）分解问题，尾递归，把第一个字符s[0]拿出来，分成2部分首字符s[0]和剩余的字符串（起始地址是s + 1）

3）找到相似性，得到递推式
```c
//1）把第一个字符放到后面
char ts[2] = { s[0] };
strcat(s + 1, ts);
```
4）递归出口
n > n - 1 > n - 2 > n - 3 > ...... > 0

完整代码：
```c
```


### 案例4：x星球

1）形式化，写成一个函数，参数有1个
```c
//字符串s逆序
void reverse(char* s);
```
2）分解问题，有两种选择
（1）车队开进检查站，f(a - 1, b + 1)
（2）检查站开出1辆车，f(a, b - 1)

3）找到相似性，得到递推式
```c
f(a, b) = f(a - 1, b + 1) + f(a, b - 1);
```
4）递归出口
n > n - 1 > n - 2 > n - 3 > ...... > 0

完整代码
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
//出站次序，车队有a辆车，检查站有b辆车
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
## 指针
```c
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a = 10;
	scanf("%d",&a);				//& 为取地址符
	cout << *(&a) << endl;		//* 为解引用符，取出地址中的值
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

## sort()基本使用方法
#### sort()的定义
sort()函数可以对给定区间所有元素进行排序。
它有三个参数sort(begin, end, cmp)，
begin为指向待sort()的数组的第一个元素的指针，
end为指向待sort()的数组的最后一个元素的下一个位置的指针，
cmp参数为排序准则，cmp参数可以不写，默认从小到大进行排序。

返回值：无
时间复杂度：O(nlogn)
排序范围：[first,last)
```c
int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	sort(a + 0, a + 2 + 1,cmp);		//排序前三位
	for(int i = 0;i < 10;i++)
	cout << a[i] << endl;	
	return 0;
}
```
#### bool控制cmp自定义排序
```c
bool cmp(int e1, int e2) {	//int 对应 int a[10]
	return e1 > e2;	//降序为true不交换，升序为false交换
}
```
#### 结构体排序
sort()也可以对结构体进行排序，
比如我们定义一个结构体含有学生的姓名和成绩的结构体Student，
然后我们按照每个学生的成绩从高到底进行排序。首先我们将结构体定义为：
```c
struct Student {
	string name;
	int score;
};
```
根据排序要求我们可以将排序准则函数写为：
```c
bool cmp_score(Student x, Student y) {
	return x.score > y.score;
}
```
完整代码：
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
### 技巧性
bool只有0为假，其他都为真

cin, cout:数据达到1e6或1e7后会变慢，改为scanf，printf 

#define int long long
加上这一行有时候程序过不了，则
#define ll long long

开数组：
const int N = 1e6 + 10;
int a[N];




#### 例题：
#B3827[NICA #2] 高考组题

##题目描述

高考是能决定每个考生命运的考试，因此作为组卷人的 Aya 将高考组卷视为重中之重。现在 Aya 有 $n$ 个备选的高考题。

对于每一道可能选入试卷的高考题，其有 $k$ 个指标来评判它各个方面的维度，例如难度、新颖度、与现实生活的结合性等。每个指标均为一个正整数。

Aya 认为，一个题被放入高考卷的必要性，是这些指标的平均值。他认为，必要性前二高的试题必须要被放进高考试卷。若有多个必要性前二大的试题则选择较早出现的那个。请告诉 Aya 哪个题目是必须要放进高考试卷的。

##输入格式

第一行输入两个正整数 $n,k$，含义如题所述；

第二行开始，往下 $n$ 行，每行输入 $k$ 个正整数，以空格隔开，第 $i$ 行表示第 $i-1$ 道题的各个指标是多少。

##输出格式

输出两行，表示必要性前两大的试题是哪两个题。优先输出必要性最高的；若有多个题目必要性相同，则优先输出较早出现的。

##样例 #1

###样例输入 #1

```
3 2
10 20
15 25
20 30
```

###样例输出 #1

```
3
2
```

##样例 #2

###样例输入 #2

```
3 2
10 20
5 25
1 2
```

###样例输出 #2

```
1
2
```

##提示

数据保证，$2 \leq n \leq 100$，$1 \leq k \leq 10$，$1 \leq$ 一道试题的各个指标 $\leq 100$。


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

