
[TOC]


//#include<bits/stdc++.h>万能头

# Day1
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

# Day2
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

# Day3
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

# Day4
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

# Day5
/*
## STL
STL是C语言标准中的重要组成部分
以模板类和函数的形式提供数据结构和算法优化
STL大致分为3类，容器，算法，迭代器

STL的主要组成部分
容器：用于存储数据集合的通用类模板，包括序列容器（如vector、list、deque）、关联容器（如set、multiset、map、multimap）和容器适配器（如stack、queue、priority_queue）。
算法：用于对容器中的元素进行各种操作的通用函数模板，例如排序、搜索、复制等。
迭代器：实现STL算法与容器交互所需的通用指针


### vector动态数组
在 C++ 中，vector 是一个模板类，用于存储一个动态数组, 运行时根据需要改变数组大小
	`vector <数据类型> 变量名；`
e.g.vector <int> a;       默认初始化，a为空
e.g.vector <int> b(a);	  用a定义b
e.g.vector <int> a(100);  a有100个值为0的元素
开辟空间后可以直接访问a[0]...a[99]，没有用（）开辟则无法访问，会溢出

#### 多维数组
定义多维数组，例如定义一个二维数组 : `vector<int> a[MAXN];`
它的第一维大小是固定的MAXN，第二维是动态的。
用这个方式，可以实现图的邻接表存储。

#### vector语法
| 功能 | 例子 | 说明|
|-------- | --------- | -------- |
|赋值 | a.push back(100); | 在尾部添加元素|
|元素个数 | int size = a.size(); | 元素个数|
|是否为空 | bool isEmpty = a.empty(); | 是否为空|
|打印 | cout << a[0] << endl; | 打印第一个元素|
|中间插入 | a.insert(a.begin() + i, k); | 在第i个元素前面插入k|
|尾部插入 | a.push_back(8); | 尾部插入为8的元素|
|尾部插入 | a.insert(a.end(), 10, 5); | 尾部插入10个值为5的元素|
|删除尾部 | a.pop_back(); | 删除尾部元素|
|删除区间 | a.erase(a.begin() + i, a.begin() + j); | 删除区间[i, j - 1]的元素|
|删除元素 | a.erase(a.begin() + 2); | 删除第3个元素|
|调整大小 | a.resize(n); | 数组大小变为n|
|清空 | a.clear(); |
|翻转 | reverse(a.begin(), a.end()); | 用函数reverse翻转数组 |
|排序 | sort(a.begin(), a.end()); | 用函数sort排序，从小到大|

#### 样例代码
```c
#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> a;
	vector <int> a(100);  //a设置100个值为0的元素
	//开辟空间后可以直接访问a[0]...a[99]，没有用（）开辟则无法访问 会溢出
	a.push_back(8);
	a.push_back(7);
	cout << a.size();//元素个数
	cout << *a.begin();//a[0],a.begin()迭代器类似于指针，要用解引用符
	cout << *(a.end()-1);//a.end()指向最后元素的后一位
	return 0;
}
```

#### 迭代器&&循环遍历
迭代器（Iterator）是一种设计模式，在编程语言中用于访问容器的元素，而不需要暴露集合的内部表现方式。
迭代器提供了一种统一的方式来遍历不同类型的集合，使得代码更加灵活和可复用。
使用* 操作符可以解压或展开迭代器或可迭代对象（Iterable），将其内容依次提取出来。
```c
	vector<int>::iterator it;
	for(it=a.begin(); it != a.end();it++){}
		cout << *it;	//解引用符解迭代器
	for (auto it = a.begin(); it != a.end(); it++){}
		cout << *it;	//解引用符解迭代器
```

#### auto语法

##### auto的定义
【auto】(自动识别类型)
在C++中，auto 关键字是一个类型说明符，用于自动推导变量的类型。
这意味着编译器会根据变量的初始化表达式自动确定变量的类型，从而使得代码更加简洁，
特别是当处理复杂类型时。auto 关键字是在C++11标准中引入的，之后被广泛应用于现代C++编程中。

##### auto的语法
规则1：声明为auto（不是auto& ）的变量，忽视掉初始化表达式的顶层const。即对有const的普通类型(int 、double等)忽视const，对常量指针（顶层const）变为普通指针，对指向常量（底层const）的常量指针（顶层cosnt）变为指向常量的指针（底层const）。
规则2：声明为auto& 的变量，保持初始化表达式的顶层const或volatile 属性。
规则3：若希望auto推导的是顶层const，加上const，即const auto。
[参考资料](https ://blog.csdn.net/weixin_43744293/article/details/117440727)
```c
	for(auto x : a){}
		cout << x;
```
**[更喜欢用这个]**
auto会拷贝一份容器内的veckor,在修改x时不会改变原容器当中的vector值，只会改变拷贝的vector。
x为元素可直接使用
```c
	for (auto& x : vector){}
```
当需要对原数据进行同步修改时，就需要添加& ，即vector的引用。会在改变x的同时修改vector。
```c
for (const auto& x : vector)
```
**[不常用]**
const(常类型)，不能作为左值& (引用)，不拷贝，不申请新空间，
会对原vector修改当我们不希望拷贝原vector(拷贝需要申请新的空间)，同时不愿意随意改变原vector，
那么我们可以使用for(constauto & x:vector)，这样我们可以很方便的在不拷贝的情况下读取vector，同时不会修改vector。一般用在只读操作。

##### auto在编程时真正的用途
1、代替冗长复杂的变量声明
`vector<int>::iterator it = v.begin(); `直接用auto代替 `auto it = v.begin();`
2、定义模板参数时，用于声明依赖模板参数的变量
```
template <typename _Tx, typename _Ty>
void Multiply(_Tx x, _Ty y) {
	auto v = x + y;
	std::cout << v;
}
```

#### 使用reverse反向排列算法
```c
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
	}
	reverse(v.begin(), v.end());
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	return 0;
}
```

### stack栈
#### 栈的定义
栈（Stack）是一种线性数据结构，其特点是只允许在一端进行插入和删除操作；
这一端被称为栈顶（top），相对地，把另一端称为栈底（bottom）；
这种数据结构遵循后进先出（LIFO, Last In First Out）的原则。

#### 栈的语法
| 例子 | 说明|
|-------- | -------- |
|stack<Type>s; | 定义栈，Type为数据类型，如int，foatchar等|
|s.push(item); | 把item放到栈顶|
|s.top(); | 返回栈顶的元素，但不会删除|
|s.pop(); | 删除栈顶的元素，但不会返回|
|s.size(); | 返回栈中元素的个数|
|s.empty(); |检查栈是否为空，如果为空返回true.否则返回false|

#### 爆栈问题
栈需要用空间存储，存进栈的数组太大，那么总数会超过系统为栈分配的空间，就会爆栈，即栈溢出。
解决办法有两种 : 
(1)在程序中调大系统的栈。依赖于系统和编译器。
(2)手工写栈。

#### P1427 小鱼的数字游戏
**题目描述**
小鱼最近被要求参加一个数字游戏，要求它把看到的一串数字 $a_i$（长度不一定，以 $0$ 结束），记住了然后反着念出来（表示结束的数字 $0$ 就不要念出来了）。这对小鱼的那点记忆力来说实在是太难了，你也不想想小鱼的整个脑袋才多大，其中一部分还是好吃的肉！所以请你帮小鱼编程解决这个问题。
**输入格式**
一行内输入一串整数，以 $0$ 结束，以空格间隔。
**输出格式**
一行内倒着输出这一串整数，以空格间隔。
**样例 #1**
**样例输入 #1**
```
3 65 23 5 34 1 30 0
```
**样例输出 #1**
```
30 1 34 5 23 65 3
```
**提示**
**数据规模与约定**
对于 $100\ % $ 的数据，保证 $0 \leq a_i \leq 2 ^ {31} - 1$，数字个数不超过 $100$。
```c
#include<bits/stdc++.h>
using namespace std;
int main() {
	stack<int> s; 
	int x;
	while (cin >> x&&x!=0) {
		s.push(x);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
```
*/


# Day8
/*
## queue队列
### queue的定义
队列`Queue`是一种常见的数据结构，其主要特点是`先进先出`（FIFO：First In First Out）。
在队列中，数据的插入和删除操作分别在表的不同端进行。具体来说，向队列中添加新元素的一端称为“队尾”`rear`，而从队列中移除元素的一端称为“队头”`front`.
队列和栈的区别:
栈只能知道最后插进去的元素,队列可以知道最先和最后插进去的元素;栈是`后进先出`,队列是`先进后出`

### queue的语法
| 例子 | 说明|
|-------- | -------- |
|q.front();|返回队首元素|
|q.back();|返回队尾元素|
|q.push();|在队尾插入元素|
|q.pop();|弹出队首元素|
|q.empty;|队列是否为空|
|q.size();|返回队列中的元素的数量|

例题
[P1996 约瑟夫问题](https://www.luogu.com.cn/problem/P1996)
```c
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;int tmp;
	cin>>n>>m;
	queue <int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		tmp++;
		if(tmp%m!=0){
			q.push(q.front());
			q.pop();
		}
		else{
			cout<<q.front()<<" ";
			q.pop();
		}
	}
	return 0;
}
```
## 堆/优先队列(priority_queue)

### 堆的定义
堆是一种特殊的数据结构，通常可以被看作是一棵完全二叉树的数组对象。其主要特性包括：
**完全二叉树**：除最后一层外，每一层上的节点数均达到最大值；在最后一层上只缺少右边的若干节点。
**值的性质**：对于大顶堆，每个父节点的值都大于或等于其子节点的值；对于小顶堆，每个父节点的值都小于或等于其子节点的值。
**高效性**：堆是实现优先队列的一种非常高效的方法，能够快速找到包含最大值或最小值的节点。

### 优先队列的定义
优先队列`priority_queue`是一种特殊的队列，其中元素被赋予优先级，当访问队列元素时，具有最高优先级的元素最先删除。
优先队列与普通队列最大的不同点在于它根据元素的优先级进行排序和处理。
具体来说：
**优先级**：每个元素都有一个优先级，优先级高的元素会先于优先级低的元素被访问或删除。
**操作**：支持查找最高优先级元素、删除最高优先级元素和插入指定优先级的新元素等操作。
**实现基础**：优先队列通常基于堆来实现，因此其性能也依赖于堆的性质和实现方式。

### 优先队列的语法
| 例子 | 说明|
|-------- | -------- |
|pq.push(int x);|向优先队列中插入一个整数|
|pq.pop();|删除并返回优先队列中的最大元素|
|pq.top();|返回但不移除优先队列中的最大元素|
|pq.empty();|检查优先队列是否为空。|

C++中的优先队列是标准模板库（STL）的一部分，通常使用priority_queue模板类来实现。
```c
   #include <queue>
   using namespace std;

   int main() {
	   priority_queue<int> pq;
	   // 插入元素
	   pq.push (5);
	   pq.push (3);
	   pq.push (7);
	   // 删除最高优先级的元素
	   pq.pop ();
	   // 获取最高优先级的元素
	   cout << pq.top () << endl;
	   return 0;
   }
```
在C++中，`priority_queue`默认为`最大堆`从大到小，即最大的元素会首先被移除。
可以通过第三个模板参数来指定排序方式，例如：
   `priority_queue<int, vector<int>, greater<int>> pq;`
这样可以将优先队列变为`最小堆`。
1.元素类型：`int`表示优先队列中存储的元素类型。
2.底层容器：`vector<int>`表示用于存储元素的容器类型。在优先队列中，默认使用`vector`作为底层容器。
3.比较函数对象：`greater<int>`，这是一个仿函数，用于指定元素的排序方式。由于使用了`greater<int>`，因此该优先队列会按照从小到大的顺序排列元素，即小顶堆.
默认情况下，`priority_queue`使用`std::less`作为其比较函数，这意味着它会创建一个大顶堆。
访问`priority_queue`的顶部元素`top()`的时间复杂度是`O(1)`，但插入`push()`和删除顶部元素`pop()`的时间复杂度是`O(log n)`，其中n是队列中元素的数量。
`priority_queue`不保证元素的顺序（除了顶部元素），也不提供随机访问。
**结构体类型**
```
struct Node {
	int a, b;
	// 重载小于操作符，以实现自定义排序规则
	bool operator<(const Node& other) const {               //[记住格式]
		// 假设我们希望先按a升序排序，如果a相同，则按b降序排序
		if (a != other.a) return a < other.a;
		return b > other.b; // 注意这里使用'>'来实现b的降序
	}
};

int main() {
	priority_queue<Node> pq;
	Node n1{ 1, 9 };
	Node n2{ 1, 5 };
	Node n3{ 9, 1 };

	pq.push(n1);
	pq.push(n2);
	pq.push(n3);

	while (!pq.empty()) {
		Node top = pq.top();
		pq.pop();
		cout << top.a << " " << top.b << endl;
	}

	return 0;
}
```
例题
[P1090 [NOIP2004 提高组] 合并果子](https://www.luogu.com.cn/problem/P1090)
```
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
#define ll long long int
int main() {
	int n;
	cin >> n;
	int t;
	priority_queue<int,vector<int>,greater<int> > a;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a.push(t);
	}
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int sum1 = 0;
		sum1 += a.top();
		a.pop();
		sum1 += a.top();
		a.pop();
		sum += sum1;
		a.push(sum1);
	}
	cout << sum;
	return 0;
}
```

## 双端队列
### Deque的定义
双端队列（Double-Ended Queue，简称Deque）是一种具有队列和栈性质的数据结构。
其主要特点是允许在两端进行插入和删除操作，即可以在队首（前端）和队尾（后端）同时进行入队和出队操作。
双端队列是限定插入和删除操作在表的两端进行的线性表。这两端分别称为端点1和端点2。
双端队列的元素可以从两端弹出，因此它兼具了队列和栈的特性.
### Deque的语法
在C++中，标准模板库（STL）提供了`std::deque`来实现双端队列的功能。
`std::deque`可以被视为一个固定大小的数组，但它可以动态增长和缩减，且不需要在每次插入或删除时重新分配整个数组的内存。这种特性使得`std::deque`在插入和删除操作上非常高效。

在C++中，使用双端队列需要包含相应的头文件：
	`#include <deque>`
定义一个双端队列对象的基本语法如下：
	`deque<element_type> deq;`
其中element_type可以是任意类型的数据，例如整数、字符串等。

| 例子 | 说明|
|-------- | -------- |
|deq.push_back(x);|在队列尾部插入元素x|
|deq.push_front(x);|在队列头部插入元素x|
|deq.pop_back();|删除队列尾部的元素|
|deq.pop_front();|删除队列头部的元素|
|deq.at(size_type pos);|返回位置pos处的元素，如果位置超出范围则引发异常|
|deq.find(const value_type& val);|查找指定值val的位置，并返回迭代器指向该位置，如果未找到则返回end()|

以下是定义和使用 std::deque 的基本语法：
```
#include <iostream>
#include <deque>

int main()
{
	// 定义一个 int 类型的双端队列
	std::deque<int> myDeque;

	// 向队列头部插入元素
	myDeque.push _back(10);
	myDeque.push _back(20);
	myDeque.push _back(30);

	// 向队列尾部插入元素
	myDeque.push _back(40);
	myDeque.push _back(50);

	// 删除队列头部元素
	myDeque.pop _back();

	// 删除队列尾部元素
	myDeque.pop _back();

	// 查找并打印所有元素
	for (int num : myDeque)
	{
		std::cout << num << " ";
	}
	return 0;
}
```
*/


# Day9
/*
## Set集合

### Set的定义
在C++中，`set`是标准模板库（STL）的一部分，用于存储已排序且唯一的一组元素。其主要特点包括：
**数据结构**：`set`通常使用红黑树`red-black tree`实现，这使得它具有对数时间复杂度`O(logn)`的查找、插入和删除操作。
**元素特性**：集合中的每个元素都是唯一的，并且按照`升序`排列，但也可以通过自定义比较函数来实现其他的排序方式，如`降序`加上`greater<int>`。
**不可变性**：一旦元素被插入到`set`中，其值不能被修改，但可以进行插入或删除操作。
**迭代器**：`set`提供了迭代器，用于遍历集合中的元素。
**有什么用**：去重、排序
### Set的语法
| 例子 | 说明|
|-------- | -------- |
|St.insert();|当set里没有等价函数时，将x插入到set中|
|St.erase();|从set中删除指定元素（若无则也无影响，即无操作）|
|St.clear();|清空set容器|
|st.count(x);|返回set内的x元素的数量，因为最多存在一个，返回值 1 or 0|
|St.empty();|判断set是否为空|
|St.size();|返回set内的元素个数 |
|St.find();|函数用于查找指定值的位置|

	以下是一个完整的示例程序，演示如何定义和操作一个`set`：
```
#include <iostream>
#include <set>
using namespace std;
int main(){
	// 创建并初始化set
	set<int> my_set = {1, 2, 3};//默认升序
	set<int,greater<int> > my_set2 = {1, 2, 3};//降序

	// 插入新元素
	my_set.insert(4);

	// 查找元素
	auto it = my_set.find(2);
	if (it != my_set.end())
	{
		cout << *it << endl; // 输出2
	}

	// 删除元素
	my_set.erase(my_set.find(1));

	// 遍历集合并输出所有元素
	for (const auto &val : my_set)
	{
		cout << val << " ";
	}
	return 0;
}
```

## Multiset可重集合
### Multiset的定义
在C++中，`multiset`是一个非常有用的STL（标准模板库）容器类型，用于存储和操作具有相同键值对的元素集合。
与set不同的是，`multiset`允许重复的元素存在，并且能够保持这些元素的有序性。

`St.begin();`返回set第一个元素的地址的迭代器
`St.end();`返回set最后一个元素的地址的下一个地址的迭代器
`St.erase(T x/iterator it)`
`Lower_bound` 二分查找 `upper_bound()`
**元素特性**：集合中的每个元素都是唯一的，并且按照`升序`排列，
但也可以通过自定义比较函数来实现其他的排序方式，如`降序`加上`greater<int>`

## Map

### Map的定义
在C++中，`Map`是一种关联容器，它存储的元素是键值对`key-value pairs`。
每个元素都是一个键值对，其中键（key）是唯一的，而值（value）则可以是任何数据类型。
Map内部通常实现为一个红黑树（或类似的平衡二叉搜索树），这意味着 map 中的元素总是按照键的升序排列。
因此，map 提供了快速的查找、插入和删除操作，这些操作的时间复杂度通常为对数时间`O(log n)`，其中 n 是 map 中元素的数量。
也可以理解成一个结构体数组,只是数组的下标和值都是任意的。

[注意事项]
map 中的键必须是唯一的。
map 中的元素按照键的升序排列。
访问不存在的键时，使用下标操作符会创建一个新元素。如果你只是想检查键是否存在，应该使用 find 成员函数。
map 的插入、删除和查找操作的时间复杂度通常为 O(log n)。

### Map的语法
基本的`std::map`声明语法如下：
	`map<KeyType, ValueType> mapName;`
`KeyType` 是键的类型,它必须支持 < 操作符，以便map可以对其元素进行排序
`ValueType` 是与键相关联的值的类型。
`mapName` 是你定义的map的名称。

**常用函数**
| 例子 | 说明|
|-------- | -------- |
|Mp.insert(const value_type& val)；| 插入一个键值对。如果键已存在，则更新其值|
|Mp.erase(key_type const& k);|删除与指定键相关联的元素，释放空间|
|Mp.find(key_type const& k);|查找具有指定键的元素。如果找到，返回一个指向该元素的迭代器；否则，返回一个指向map末尾的迭代器|
|Mp.size();|返回map中元素的数量|
|Mp.empty();|如果map为空，则返回true|
|Mp.operator[];|使用键作为索引访问元素。如果键不存在，则插入一个具有该键的新元素，并将其值初始化为ValueType()的默认构造值|
|Mp.count();|统计这个下标出现的次数 1 or 0|
**使用方法**
	【创建 map】
	创建一个空的 map，键类型为 int，值类型为 std::string
	```
	map<int, string> myMap; 
	//  key  value
	```
	or 使用初始化列表
	```
	map<int, string> myMap2 = {
		{1, "one"},
		{2, "two"},
		{3, "three"}
	};
	```

	【插入元素】
	1.使用下标操作符`[]`（如果键不存在，则插入新元素，并初始化其值为ValueType的默认值）：
	```
	myMap[1] = "one";  
	```
	2.使用`insert`成员函数：
	```
	auto result = myMap.insert(make_pair(2, "two")); 
	if (!result.second) {
		// 插入失败，通常是因为键已存在  
	}
	```

	【访问元素】
	```
	string value = myMap[1]; // 访问键为 1 的元素的值  
	```
	注意：如果键不存在，则使用下标操作符会创建一个新元素，其值会被初始化为值类型的默认值  
	or
	更安全的访问方式（验证键更安全）
	```
	auto it = myMap.find(1);// 验证键更安全
	if (it != myMap.end()) {
		string value = it->second; // 访问找到的元素的值  
	}	// `myMap.first`为键，`myMap.second`为值
	```
	
	【删除元素】
	```
	myMap.erase(1); // 删除键为 1 的元素  
	```
	or 使用迭代器
	```
	auto it = myMap.find(2);
	if (it != myMap.end()) {
		myMap.erase(it);
	}	// 验证键更安全
	```

	【遍历 map】
	```
	for (const auto& pair : myMap) {
		cout << pair.first << ": " << pair.second << endl;
	}
	```
	or 使用迭代器  
	```
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}	// 验证键更安全
	```

### Map的坑
1.会爆栈
如果键不存在，则使用下标操作符会创建一个新元素，其值会被初始化为值类型的默认值`0`。
2.无限循环
可以需要用`count()`去判断键是否存在，再去访问键，否则会一直新建键值对无限循环。
```
if (mp.count()>0){code}
```
or `find()`

### unordered_map
`unordered_map`是基于`哈希表`的`map`
在使用方面和`map`没有任何区别
`map`:
**优点**:有序性,效率十分稳定`Olog(n)`
`unordered_map`:
**优点**:查找速度非常的快近似`O(1)`
**缺点**:无序,插入操作的效率不如`map`
如果说你需要遍历整个`map`,且想要的是有序的`(for(autolx,c]:mp)`那么就用`map`
其他就用`unordered_map`在`codeforces`一定会TLE
能让你用`map`，那么大概率能用`unordered_map`，有概率会卡`unordered_map`
相反亦然，有的题你用`unordered_map`能过，有可能`map`会被卡

*/



# Day10
/*
// 代码模板
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);//关闭同步流

	cout默认保留小数点后4位
	cout<<fixed<<setprecision(2)<<endl;//保留小数点后2位
    return 0;
}
```
*/


# Day11
## 数组
数组最好声明在main函数的外面：
只有在放外面时，数组才可以开得很大；
放在main函数内时，数组稍大就会异常退出。
### memset的使用
`memset(数组名称，需要初始化的值，数组的每个元素的大小)`
**注意**：memset初始化的值只能是0和-1
```cpp
signed main() {
	// 【memset(数组名称，需要初始化的值，数组的每个元素的大小)】
	int a[10];             //请注意：memset() 仅能的初始化值仅能为 0 或者 -1
	memset(a, 0, sizeof(a));
	for (auto x : a) {
		cout << x << " ";
	}
	cout << endl;
	memset(a, -1, sizeof(a));
	for (auto x : a) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
```
**注意事项**
`memset`函数按字节进行操作，因此不能直接用于将整型数组（如int数组）初始化为非`0`和非`-1`之外的其他值。
如果需要对指针变量所指向的内存单元进行清零初始化，必须先确保这个指针变量已经指向了一个有效的地址。
`memset`函数只能用于字符数据类型或者无符号整型数据类型，即只能设置1字节大小的值。

**例题**
有n盏灯，编号为1~n，第1个人把所有灯打开，第2个人按下所有编号为2的倍数的开关（这些灯将被关掉），第3个人按下所有编号为3的倍数的开关（其中关掉的灯被打开，开着灯将被关闭），依此类推。一共有k个人，问最后有哪些灯开着？
输入:n和k，输出开着的灯编号。k<=n<=1000
样例输入:7 3
样例输出:1 5 6 7
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	memset(a, -1, sizeof(a));//-1表示开灯

	for (int i = 2; i <= k; i++){
		for (int j = i; j <= n;j+=i){
			a[j] *= -1;
		}
	}

	for (int i = 1; i <= n;i++){
		if(a[i]==-1){cout << i << endl;}
	}
	return 0;
}
```

### 多组样例输入
1.函数`scanf()`的返回值 就是：“所输入的数据与格式中匹配次数.”
简单来说就是，它返回已成功赋值的数据项数；出错时则返回EOF.
（注：EOF(End Of File)是一个预定义的常量，等于-1.）
```cpp
while(scanf("%d%d",&a,&b)==2){}
while(scanf("%d%d",&a,&b)!=EOF) {}
while(scanf("%d%d",&a,&b)!=-1) {}
while(~scanf("%d%d",&a,&b)) {}
```
2.cin实现的多组输入
```cpp
#include<iostream>
using namespace std;
int main(){
	int a,b,c;
    while(cin>>a>>b>>c){
        ...
    }
}
```
3.例题

[HDU-1021](https://vjudge.net/problem/HDU-1021#author=GPT_zh)

**解题代码**
```cpp
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main(){
    while (scanf("%d", &n) != EOF){
        if(n % 8 == 2 || n % 8 == 6)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl; 
    }
    
    return 0;
}
```

## string 类 字符串
### C语言字符串常用函数

> `strcpy`：拷贝字符串
>
> `strcat`：拼接两个字符串
>
> `strcmp`：字符串比较

### string 类 语法
#### 常用函数
| 例子 | 说明|
|-------- | -------- |
|length(); size(); |求长度|
|empty();          |判断是否为空串|
|substr();         |截取字符串|
|erase();          |删除若干个字符|
|insert();         |插入字符|
|replace();        |替换字符|
|find();           |寻找字符|
|count();		   |计算字符个数|
|stoi();		   |string转int|
|to_string();	   |int转string|

#### string重载了一些运算符，可以直接使用
```cpp
str1=str2;    //str1成为str2的拷贝

str1+=str2; //str2的字符数据连接到str1的尾部

str1+str2;  //将str2连接到str1的尾部，str1不改变

str1==str2;  str1!=str2; str1<str2; 
str1>str2;  str1<=str2;  str1>=str2;
//基于字典序的比较，返回布尔值，true或false
```

#### 字符串读取
`getchar()`输入一个字符
`cin`能读到空格，读不到换行符
`getline()`可以读到换行符
```cpp
#include<iostream>
using namespace std;
int main(){
	cout<<getchar();//输入一个字符

	string s;
    cin>>s;//`cin`能读到空格，读不到换行符
    cout<<s;

    string s;
    getline(cin,s);//`getline()`可以读到换行符
    cout<<s;
}
```

#### `substr();`截取字符串
string.substr(起始位，数几个)
```cpp
int main (){
	string s="hello, world!";
	string ss1 = s.substr(2);//llo, world!
	//从2开始往后取完
	string ss2 = s.substr(2,3);//llo
	//从2开始往后取3位
	cout<<ss1<<endl<<ss2<<endl;
}
```

#### `erase()`删除若干个字符
`string.erase(起始位，数几个)`有规律地指定删除
```
s1.erase(1, 2)//从1开始删2个
cout << s1 << endl;
```
#### `insert()`插入字符
```cpp
string.insert(要插入的位置，要插入的元素);
s1.insert(0, "1");
cout << s1 << endl;
```

#### `replace()`替换字符
string.replace(索引，要替换几个字符，替换上去的元素)
```cpp
s1.replace(0, 1, "HaHa");
cout << s1 << endl;
```
#### `find()`寻找字符
在 C++ 中，`string::npos`是一个特殊的常量值，用于表示在字符串中未找到子字符串或字符时的位置。
这个常量实际上是`std::string`类型所能表示的最大值，即 `std::string::size_type`的最大值。
由于字符串的索引是从`0`开始的，因此任何有效的索引值都小于 `std::string::npos`。
```cpp
if (s1.find("666") == string::npos) {
	cout << "找不到" << endl;
}
else {
	cout << "找到了" << endl;
}
```

#### `count()`计算字符个数
`count(string.begin(),string.end(),'要找的字符')`
```cpp
string s = "Hello world";
cout << count(s.begin(), s.end(), 'l') << endl;
```

#### `string`和`int`相互互换
```cpp
#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	//string 和 int 相互转换
	string s="123";
	string s2="6";
	cout<<stoi(s)+stoi(s2);
	
	int a=123,b=345;
	string s=to_string(a)+to_string(b);
	cout<<s;
} 
```

# Day12
#### `sort`和`reverse`排序
`sort(begin(),end())`默认从小到大排序
`reverse`翻转排序
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="ABCABCABC";
	cout<<count(s.begin(),s.end(),'A');
	sort(s.begin(),s.end());//排序
	reverse(s.begin(),s.end());//翻转
	cout<<s<<endl;
}
```
例题

[P1106 删数问题](https://www.luogu.com.cn/problem/P1106)
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;int k;
	cin>>n>>k;
	while(k--){
		for(int i=0;i<n.size();i++){
			if(n[i]>n[i+1]){
				n.erase(i,1);//删除前一个比后一个大的数
				break;
			}
		}
	}
	int a=stoi(n);//删除前导0
	cout<<a;
	return 0;
}
```
[P2580 于是他错误的点名开始了](https://www.luogu.com.cn/problem/P2580)
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	map<string,int>p;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		p[s]=1;
	}
	int m;cin>>m;
	while(m--){
		string s;cin>>s;
		if(p[s]==1)cout<<"OK"<<endl,p[s]=-1;
		else if(p[s]==-1)cout<<"REPEAT"<<endl;
		else cout<<"WRONG"<<endl;

	}
	return 0;
}
```
[P1628 合并序列](https://www.luogu.com.cn/problem/P1628)
```cpp
#include<bits/stdc++.h>
using namespace std;
string a[1000005],k;
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i].find(k)==0){
			cout<<a[i]<<endl;
		}
	}
	return 0;
}
```
[P1104 生日](https://www.luogu.com.cn/problem/P1104)
```cpp
#include<bits/stdc++.h>
using namespace std;
struct student{
	string s;
	int y,m,d;
	int id;
};
bool cmp(const student &a, const student &b);
int main(){
	int n;cin>>n;student a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i].s>>a[i].y>>a[i].m>>a[i].d;
		a[i].id=i;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)cout<<a[i].s<<endl;
	return 0;
}
bool cmp(const student& a, const student& b) {  
    if (a.y != b.y) return a.y < b.y; // 先比较年份  
    if (a.m != b.m) return a.m < b.m; // 年份相同则比较月份  
    if (a.d != b.d) return a.d < b.d; // 年份和月份都相同则比较日期  
    return a.id > b.id; // 所有都相同则根据id排序  
}  
```
[P8871 [传智杯 #5 初赛] C-莲子的排版设计学](https://www.luogu.com.cn/problem/P8871)



# Day13
## 贪心算法
贪心算法（Greedy Algorithm），也称贪婪算法，是一种在每一步决策中都选择当前状态下最优的选项，以期达到全局最佳结果的优化算法。其核心思想是通过一系列局部最优选择来实现整体最优解。

**定义与特性**
贪心算法的基本定义如下：
在每一步决策时，总是采取在当前状态下的最好选择，从而希望导致结果是最好或最优的。
贪心算法不考虑未来可能产生的影响，只关注当前的局部最优解。
贪心算法通常运行迅速，因为它们不涉及复杂的回溯或多次迭代。

**特性**
**局部最优选择**：在每步只选择当前看似最优的决策，不考虑长远后果。
**不回溯**：一旦做出选择，不会回溯或重新评估这些决策。
**简单直接**：由于算法逻辑简单，易于编码和快速实现。
**高效性**：运行迅速，因为不需要复杂的回溯或多次迭代。

**原理与使用方法**
贪心算法的基本原理是从问题的某个初始解出发，逐步地进行选择，直到达到最终求解的过程。每一步选择都是基于当前的局部最优，并且不能回退。因此累积到的这些局部最优的选择结果，就是全局最优解。

使用贪心算法需要满足以下两个条件：
问题具有贪心选择性质，即使用当前最优解能够得到全局最优解；
问题的子问题具有最优子结构性质，即原问题的最优解可以通过对子问题的最优解组合而得到。

**设计步骤**
设计贪心算法一般包括以下几个步骤：
确定问题的最优子结构；
基于问题的最优子结构设计一个递归算法；
证明我们做出的贪心选择，只剩下一个子问题；
证明贪心选择总是安全的；
设计一个递归算法实现贪心策略；
将贪心算法转化为迭代算法。

**贪心算法的应用示例**：
**最小生成树**：在加权无向图中，Prim算法和Kruskal算法都是基于贪心策略的算法，用于求解最小生成树。
**活动选择问题**：给定一系列活动，每个活动都有一个开始时间和一个结束时间，求可以安排的最大活动数，使得没有两个活动的时间重叠。这个问题可以通过贪心算法求解。
**背包问题（部分情况）**：虽然背包问题通常使用动态规划求解，但在某些特定条件下（如0-1背包问题的贪心版本，即“分数背包问题”），贪心算法也可以得到最优解。
**哈夫曼编码**：在数据压缩中，哈夫曼编码是一种使用贪心算法构建的用于无损数据压缩的广泛使用的可变长编码方式。
**例如**：在找零钱问题中，假设我们有面值为1元、5元、10元、50元、100元、500元的货币，现在要找零786元，贪心算法会从最大面额开始逐步减少，直到找到最优解。

**贪心算法的优缺点**：
**优点**：
算法简单，易于实现。
在某些问题中，能够产生最优解或近似最优解。
时间复杂度低，效率高。
**缺点**：
不适用于所有问题，特别是那些需要全局最优解的问题。
贪心策略的选择对结果有很大影响，如果贪心策略选择不当，可能导致无法得到最优解。

[P1478 陶陶摘苹果（升级版）](https://www.luogu.com.cn/problem/P1478)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct apple{
	int high;
	int power;
}ap[N];

int cmp(apple a,apple b){
	return a.power<b.power;
}


signed main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	
	int n,s;//苹果数，力气
	cin>>n>>s;

	int a,b;//椅子高度，手臂长
	cin>>a>>b;

	for(int i=1;i<=n;i++){
		cin>>ap[i].high>>ap[i].power;
	}

	sort(ap+1,ap+n+1,cmp);//对苹果按照力气从小到大排序

	//摘苹果
	int ans=0;
	for(int i=1;i<=n;i++){
		//判断高度是否足够
		if(ap[i].high>a+b){//超出高度
			continue;
		}
		else if(s>=ap[i].power){
			s-=ap[i].power;
			ans++;
		}
	}
    cout << ans<<endl;
    return 0;
}
```

[P2240 【深基12.例1】部分背包问题](https://www.luogu.com.cn/problem/P2240)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct gold{
	int x;
	int y;
	double pj;
}jb[N];

int cmp(gold a,gold b){
	return a.pj>b.pj;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	int n,t;
	cin>>n>>t;

	for(int i=0;i<n;i++){
		cin>>jb[i].x>>jb[i].y;
		jb[i].pj=(double)jb[i].y/(double)jb[i].x;
	}

	sort(jb,jb+n,cmp);

	double sum=0;
	for(int i=0;i<n;i++){
        if(t>=jb[i].x){
			sum+=jb[i].y;
			t-=jb[i].x;
		}
		else if(t>0){
			sum+=(t)*jb[i].pj;
            break;
        }
	}
	cout<<fixed<<setprecision(2)<<sum;
    return 0;
}
```
[P1803 凌乱的yyy / 线段覆盖](https://www.luogu.com.cn/problem/P1803)
[P1106 删数问题](https://www.luogu.com.cn/problem/P1106)


# Day15
## 双指针
双指针（Two Pointers）是一种在遍历对象过程中，使用两个指针进行访问以达到特定目的的算法思想。根据两个指针的移动方向和相对位置，可以分为以下几种类型：

**快慢指针**：两个指针从同一侧开始遍历数组或链表，一个指针移动速度快（快指针），另一个移动速度慢（慢指针）。这种模式常用于解决需要判断某个条件是否满足的问题，如寻找有序数组中的某个值、判断是否存在某对元素等。

**对撞指针**：两个指针分别从数组的两端开始向中间移动，通常一个指针向前移动，另一个向后移动。这种模式适用于需要找到一对特定条件下的元素对，例如两数之和问题。

**滑动窗口**：当两个指针指向同一数组且遍历方向相同且不相交时，称为滑动窗口。这种模式常用于区间搜索问题，如寻找最长的子串满足某种条件


### 例题
**回文数**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;

	int i=0,j=s.size()-1;

	while(i<j){
		if(s[i]!=s[j]){
			cout<<"No"<<endl;
			return 0;
		}
		i++;j--;
	}
	cout<<"Yes"<<endl;
	return 0;
}
```
**找指定和的整数对**
输入n个整数，放入数组a。找出其中的两个数，他们的和等于m。
**输入样例**：
```
9 28
21 4 5 6 13 65 32 9 23
```
**输出**
```
5 23
```
**解题代码**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	sort(a,a+n);

	int i=0,j=n-1;
	while(i<j){
		if(a[i]+a[j]>m){
			j--;
		}
		if(a[i]+a[j]<m){
            i++;
        }
		if(a[i]+a[j]==m){
			cout<<a[i]<<" "<<a[j]<<endl;
            i++;
        }
	}
	return 0;
}
```
**移动0**
给定一个数组nums，编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序
**输入**：nums = [0,1,0,3,12]
**输出**：[1,3,12,0,0]
**解题代码**
```cpp
int a[5] = { 0,1,0,3,12 };
int i = 0, j = 0;
while (j <= 4) {
	if (a[i] != 0) {
		i++, j++;
	}
	else if (a[j] != 0) {
		swap(a[i], a[j]);
		i++;
	}
	j++;
}
for (int i = 0; i < 5; i++) {
	cout << a[i] << " ";
}
return 0;
```
**寻找区间和**
给定一个长度为n的数组a和一个数s；在这个数组中寻找一个区间，使得这个区间的元素之和等于s，输出区间的起点和终点
**输入样例**：
```
15 6
6 1 2 3 4 6 4 2 8 9 10 11 12 13 14
```
**输出样例**
```
0 0
1 3
5 5
6 7
```
**解题代码**
略
**A-B 数对**
[A-B 数对](https://www.luogu.com.cn/problem/P1102)
```cpp
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e6+10;
int a[maxn];

signed main(){
    int n, c;
    cin >> n >> c;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    // i 是用来枚举b
    // j and k are used to determine the interval range of a
    // i is used to determine the left endpoint of the interval
    // k is used to determine the right endpoint of the interval
    long long ans = 0;
    for(int i = 1, j = 1, k = 1; i <= n; i++) {
        while(j <= n && a[j] - a[i] < c) j++;
        while(k <= n && a[k] - a[i] <= c) k++;
        ans += k - j;
    }

    cout << ans << "\n";
    return 0;
}
```

# Day16
### 前缀和的概念和用法

**概念**：

前缀和是指一个数组的某下标之前的所有数组元素的和（即`数列的前n项求和`）。在算法中，前缀和是一种重要的预处理手段，能够降低算法的时间复杂度，快速地求出某一段的和，对于处理区间之间的问题往往十分高效。

**用法**：

1. **预处理前缀和数组**：首先，对原始数组进行一次遍历，累加计算出前缀和数组的每一个元素。具体实现时，可以创建一个与原始数组相同长度的前缀和数组，其中第`i`个元素代表原始数组从下标`0`到下标`i-1`的元素之和（或者从下标`1`到下标`i`的元素之和，具体取决于实现方式）。
2. **查询区间和**：在预处理得到前缀和数组后，可以通过计算两个位置的前缀和之差来快速得到任意区间的和。例如，对于区间`[a, b]`，其和等于前缀和数组中第`b+1`个元素（如果下标从`0`开始）减去第a个元素（如果`a`不为`0`）。

**作用**：
1.高效计算区间和：前缀和可以用来快速计算数组中某个区间的和。例如，要计算区间`l,r`之间的和，只需用`s[r]`减去`s[l-1]`即可。
2.二维前缀和：在处理二维数组时，如矩阵的最大子矩阵和问题，前缀和同样适用。通过预处理二维前缀和，可以大大降低查询的时间复杂度。

### 差分的概念和用法

**概念**：

差分，又名差分函数或差分运算，是数学中的一种概念，差分的结果反映了离散量之间的一种变化，是研究离散数学的一种工具。差分运算可以看作是`前缀和的逆运算`，它将原函数映射到其差分表示上。差分运算在数学、物理和信息学等领域有广泛应用。

**用法**：

1. **构建差分数组**：对于一维数组，差分数组d的每个元素`d[i]`表示原数组a中第i个元素与第i-1个元素的差（即`d[i] = a[i] - a[i-1]`，注意`d[0]`通常没有定义或设为`0`）。通过差分数组，可以方便地实现对原数组某个区间的批量加减操作。
2. **区间修改**：当需要对原数组的某个区间[l, r]内的所有元素都加上一个值c时，可以通过修改差分数组来实现。具体操作为：`d[l] += c`（表示从l位置开始增加c），`d[r+1] -= c`（表示在r+1位置结束增加，防止对后续区间产生影响）。之后，通过对差分数组进行前缀和运算，即可得到修改后的原数组。
3. **降低时间复杂度**：通过差分，可以将区间修改操作的时间复杂度从`O(n)`降低到`O(1)`（对于差分数组的修改操作）和`O(n)`（对于通过前缀和还原原数组的操作），从而在处理大量区间修改和查询问题时提高效率。

**作用**：
1.快速修改区间值：差分法主要用于对数组的某一个区间每个数加上一个常数。例如，如果要将区间`l,r`的所有元素赠加一个常数`d`,则只需将差分数组`c`中的`c[i]`加上`d`,并且`c[r+1]`减去`d`。
2.逆向操作：当需要对原数组进行某些特定的修改时（如在某个区间内增加或减少某个值)，可以通过差分数组来实现。首先对差分数组进行相应的修改，然后通过前缀和恢复原数组。

综上所述，前缀和与差分是算法中常用的两种技巧，它们分别通过预处理和逆运算的方式，降低了算法的时间复杂度，提高了处理区间问题的效率。



# Day17
复习
1.贪心


**一维前缀和**：
定义：s[i]前i项的和
构造：s[i] = s[i-1] + a[i]
使用：快速求出区间和
求出3-5之间的区间和：s[5] - s[2] = (1+2+3+4+5) - (1+2)

**一维差分**（标记思想）
定义：b[i]前ix项的和等于原数组a[i]
构造：b[i] = a[i] - a[i-1]
使用：快速区间修改
在3-5之间都+1，b[3]++,b[6]--
求和的时候同时进行前缀和运算即可

**二维前缀和**
定义：s[i][j]第i行，第j列的子矩阵的和
构造：s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1]
使用：快速求出矩阵中任意子矩阵（2，2）（5，5）
sum = s[5][5] - s[1][5] - s[5][1] + s[2][2]

**二维差分**
详见解题集：地毯


# Day18
## 整数二分&&实数二分
### 原理理解
搜索法和二分法
**搜索法**
把区间`[a, b]`分成n等份，每个子区间长度是`x`，计算点`xk = a + k*x`(k=0,1,2,3,4,…,n)的函数值`f(xk)`，
若`f(xk) = 0`，则是一个实根，若相邻两点满足`f(xk) * f(xk+1) < 0`，则在`(xk, xk+1)`内至少有一个实根，可以取`(xk+ xk+1)/2`为近似根。　　

**二分法**
如果确定`f(x)`在区间`[a, b]`内连续，且`f(a) * f(b) < 0`，则至少有一个实根。
二分法的操作，就是把`[a, b]`逐次分半，检查每次分半后区间两端点函数值符号的变化，确定有根的区间。

**用二分的两个条件**：
上下界`[a, b]`确定
函数在`[a, b]`内单调。

**二分法复杂度**
n次二分后，区间缩小到`(b - a)/2n`。
给定a、b和精度要求ε，可以算出二分次数`n`，即满足`(b - a)/2n < ε`。
二分法的复杂度是`O(logn)`的。
例如，如果函数在区间`[0, 100000]`内单调变化，要求根的精度是`10-8`，那么二分次数是`44`次。

### 整数二分



猜数
```cpp
#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(random_device{}()); 

int main()
{
   int ans=rnd()%10+1;
   cout<<"猜数，数字在1-10之间，每次猜一个整数"<<endl;
    
   int x,sum=0;
   while(cin>>x){
       if(x<ans)
         cout<<"小了"<<endl;
       else if(x>ans)
         cout<<"大了"<<endl;
       else if(x==ans)
         cout<<"正确!你用了区区"<<sum<<"次就猜中了"<<endl;
       sum++;
   }
}
```


### 整数二分模板
二分模板一共有两个，分别适用于不同情况。
**算法思路**：假设目标值在闭区间`[l, r]`中， 每次将区间长度缩小一半，当`l = r`时，我们就找到了目标值。
**版本1**：
当我们将区间`[l, r]`划分成`[l, mid]`和`[mid + 1, r]`时，其更新操作是`l = mid + 1`或者`r = mid`;（计算`mid`时不需要加1）
C++ 代码模板：
```cpp
int bsearch_1(int l, int r)
{
 	while (l < r)
 	{
		int mid = l + r >> 1; //等同于mid=(l+r)/2
		if (check(mid)) r = mid;
		else l = mid + 1; //+1为避免死循环
	}
	return l;
}
```
**版本2**：
当我们将区间`[l, r]`划分成`[l, mid - 1]`和`[mid, r]`时，其更新操作是`l = mid`或者`r = mid - 1`;（此时为了防止死循环，计算`mid`时需要加1）
C++ 代码模板：
```cpp
int bsearch_2(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
```



# Day21
## 二进制
二进制（Binary）是一种基数为2的数制系统，它只使用两个数码来表示数，即0和1。二进制是计算机内部存储和处理数据的基础，因为计算机中的所有信息最终都是以二进制的形式存在和处理的。

### 二进制的特点

1. **基数为2**：二进制数系统中，每一位的权值是2的幂次方。例如，在二进制数`1010`中，从右到左的每一位分别代表$2^0$、$2^1$、$2^2$、$2^3$。

2. **仅有两个数码**：二进制数只包含0和1两个数码，这使得二进制数在电子电路中易于表示和处理，因为电路的开和关状态可以自然地映射到这两个数码上。

3. **转换方便**：二进制数与十进制数之间可以方便地进行转换，尽管这种转换在位数较多时可能变得繁琐。此外，二进制数还可以方便地转换为八进制数和十六进制数，这些数制在计算机科学中也经常使用。

### 二进制数的表示

二进制数可以用一系列的0和1来表示，例如`1011`、`0010`等。在书写时，通常不会省略前导的0（尽管在某些上下文中可能会这样做），因为前导0会影响数的值（在二进制中，`0010`和`10`虽然看起来不同，但实际上表示的是同一个数）。

### 二进制数的运算

二进制数的运算包括加法、减法、乘法和除法等，这些运算都遵循与十进制数相似的规则，但需要注意的是，由于二进制数只有0和1两个数码，因此在运算过程中可能会产生进位或借位。

### 二进制在计算机中的应用

二进制在计算机科学中起着至关重要的作用。计算机中的所有信息，包括程序、数据、指令等，都是以二进制的形式存储在计算机的内存和存储设备中的。此外，计算机内部的逻辑电路也是基于二进制数进行设计和工作的。因此，了解二进制数的表示和运算对于深入理解计算机的工作原理至关重要。

### 示例

假设我们有一个二进制数`1010`，我们可以将其转换为十进制数如下：

$$ 1010_{(2)} = 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 0 \times 2^0 = 8 + 0 + 2 + 0 = 10_{(10)} $$

同样地，我们也可以将十进制数转换为二进制数。例如，将十进制数`10`转换为二进制数，我们得到`1010`（注意这里的转换可能不是唯一的，因为前导0可以省略，但在这里我们保留了它以便与上面的示例保持一致）。


## 位运算
位运算（Bitwise Operations）是直接在整数的二进制位上进行的操作。这些操作包括与（AND）、或（OR）、异或（XOR）、非（NOT）、左移（Left Shift）和右移（Right Shift）等。位运算在处理大量数据、图形处理、加密解密等领域中非常有用，因为它们通常可以在硬件级别上直接执行，因此执行速度非常快。

下面是几种基本的位运算操作及其说明：

1. **与（AND）**：对两个位进行比较，如果两个位都为1，则结果位为1；否则，结果位为0。
   
   符号：`&`
   
   示例：`5 & 3`
   - 5的二进制为`101`
   - 3的二进制为`011`
   - 结果的二进制为`001`，即十进制的1。

2. **或（OR）**：对两个位进行比较，如果两个位中至少有一个为1，则结果位为1；否则，结果位为0。
   
   符号：`|`
   
   示例：`5 | 3`
   - 5的二进制为`101`
   - 3的二进制为`011`
   - 结果的二进制为`111`，即十进制的7。

3. **异或（XOR）**：对两个位进行比较，如果两个位不相同，则结果位为1；如果两个位相同，则结果位为0。
   
   符号：`^`
   
   示例：`5 ^ 3`
   - 5的二进制为`101`
   - 3的二进制为`011`
   - 结果的二进制为`110`，即十进制的6。

4. **非（NOT）**：是一个一元操作符，它将所有位上的0变成1，1变成0。
   
   符号：`~`
   
   示例：`~5`（假设在32位整型中）
   - 5的二进制（在32位整型中表示）为`0000 0000 0000 0000 0000 0000 0000 0101`
   - 结果的二进制为`1111 1111 1111 1111 1111 1111 1111 1010`，即十进制的-6（注意，这里涉及到二进制补码的概念）。

5. **左移（Left Shift）**：将一个数的各二进制位全部左移若干位，由左侧边缘超出的位将被丢弃，而在右侧边缘新增的位将用0填充。
   
   符号：`<<`
   
   示例：`5 << 2`
   - 5的二进制为`101`
   - 左移2位后，结果为`10100`，即十进制的20，即`5*2*2`。

6. **右移（Right Shift）**：将一个数的各二进制位全部右移若干位，由右侧边缘超出的位将被丢弃。对于无符号数，左侧边缘新增的位将用0填充；对于有符号数，则取决于系统（可能是用0填充，也可能是用符号位填充，即算术右移）。
   
   符号：`>>`
   
   示例：`5 >> 2`（假设为有符号整数）
   - 5的二进制为`101`
   - 右移2位后，结果为`001`（算术右移，保持符号位），即十进制的1，即`5/2/2`。

### 位运算符优先级（从高到低）

1. **按位取反（NOT）**：`~`。这是所有位运算符中优先级最高的，它是单目运算符，作用于单个操作数。

2. **算术运算符**：如加（+）、减（-）、乘（*）、除（/）等。虽然这些不是位运算符，但它们的优先级通常高于大部分位运算符（除了按位取反）。

3. **位移运算符**：左移（`<<`）和右移（`>>`）。这两个运算符的优先级高于关系运算符和按位与、按位或、按位异或等位运算符，但低于算术运算符。

4. **按位与（AND）**：`&`。它用于对两个数的二进制表示进行逐位与操作。

5. **按位异或（XOR）**：`^`。它用于对两个数的二进制表示进行逐位异或操作。

6. **按位或（OR）**：`|`。它用于对两个数的二进制表示进行逐位或操作。

7. **关系运算符**：如大于（>）、小于（<）、等于（==）等。这些运算符的优先级低于位移运算符和按位运算符。

### 注意事项

* 运算符的结合方向：除了按位取反运算符`~`的结合方向是自右至左外，其他位运算符的结合方向都是自左至右。
* 优先级可以通过括号`()`来改变。在复杂的表达式中，可以使用括号来明确指定运算的顺序。

### 示例

考虑以下C语言表达式：

```cpp
int a = 5, b = 3;
int result = ~a & b | b ^ a;
```

根据优先级规则，这个表达式将按照以下顺序进行计算：

1. 首先计算`~a`，因为按位取反运算符的优先级最高。
2. 然后计算`b ^ a`，因为按位异或运算符的优先级高于按位与和按位或。
3. 接着计算`~a & b`，按位与运算符的优先级高于按位或。
4. 最后计算`(~a & b) | (b ^ a)`，因为按位或运算符的优先级最低。

### 位运算的使用->奇偶性判断
任何整数的二进制表示中，最低位（即最右边的位）如果是1，则该数是奇数；如果是0，则该数是偶数。
```cpp
if(n & 1){	//判断奇偶数
	cout << "YES" << endl;
}
else{
	cout << "NO" << endl;
}
```
```cpp
if(n>>3 & 1){	//判断n的第四位的奇偶性
	cout << "YES" << endl;
}
else{
	cout << "NO" << endl;
}
```

## 快速幂
快速幂（Fast Exponentiation）算法是一种用于高效计算形如 $a^b \mod m$ 的表达式的方法，其中 $a$、$b$ 和 $m$ 是整数，且 $b$ 可能非常大。该算法通过减少乘法操作的次数来提高效率，其核心思想是利用指数的二进制表示。

以下是快速幂算法的详细步骤和C++实现：

### 算法步骤

1. **初始化结果**：将结果 `result` 初始化为 1（因为任何数的 0 次方都是 1）。

2. **处理底数**：将底数 `a` 对模数 `m` 取模，以防止 `a` 在后续计算中变得过大。

3. **循环处理指数**：对指数 `b` 进行二进制分解，从最低位到最高位逐位处理。
   - 如果当前位是 1（即 `b` 为奇数或当前考察的这一位是 1），则将当前的 `a`（或其幂次）乘到 `result` 上，并对 `m` 取模。
   - 将 `a` 平方（即计算 $a \times a$），并对 `m` 取模，为处理下一位做准备。
   - 将指数 `b` 右移一位（即 `b = b >> 1`），相当于 `b` 除以 2 取整。

4. **返回结果**：当指数 `b` 变为 0 时，循环结束，返回 `result`。

### C++ 实现
```cpp
#include<bies/stdc++.h>
using namespace std;

// 快速幂函数，计算 a^b % m
int fastPower(int a, int b, int mod/* 取模 */) {
    int result = 1; // 初始化结果为1
    a = a % mod; // 将a对m取模
    while (b > 0) {
        // 如果b的当前位是1，则将当前的a乘到result上
        if (b & 1) { // 等价于 if (b % 2 == 1)
            result *= a;
			result %= mod;
        }
        // 将a平方，准备处理下一位
        a *= a;
		a %= mod;
        // b右移一位
        b >>= 1; // 等价于 b = b / 2;
    }
    return result;
}

signed main() {
    int a, b, m;
    cout << "请输入a, b, m（用于计算a^b % m）:" << endl;
    cin >> a >> b >> m;
    cout << "结果是: " << fastPower(a, b, m) << endl;
    return 0;
}
```
在这个实现中，我们使用了位运算 `&` 来检查 `b` 的当前最低位是否为 1（即 `b % 2 == 1` 的位运算等价形式），并使用了右移运算符 `>>` 来将 `b` 右移一位（即 `b /= 2` 的位运算等价形式）。这些位运算通常比相应的算术运算更快，因此在处理大数时更有效率。



# Day22
## 全排列
`next_permutation`是C++标准模板库（STL）中的一个函数，它用于重新排列给定序列的元素，以生成该序列的下一个字典序排列。
如果序列已经是字典序最大的排列，则该函数将序列重新排列为字典序最小的排列，并返回`false`表示没有下一个排列；否则，返回`true`表示成功生成了下一个排列。

### 基本用法

`next_permutation`函数的基本用法如下：

```cpp
#include <algorithm> // 引入next_permutation

// 对于数组
bool next_permutation(It first, It last);
bool next_permutation(It first, It last, Compare comp); // 使用自定义比较函数

// 对于容器（如vector, string等）
bool next_permutation(Container& c);
bool next_permutation(Container& c, Compare comp); // 使用自定义比较函数
```

其中，`It`是迭代器类型，`Container`是容器类型（如`std::vector`、`std::string`等），`Compare`是一个可选的比较函数类型。

### 使用示例

#### 示例1：数组

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int a[] = {1, 2, 3};
    do {
        for (int i = 0; i < 3; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(a, a + 3));
    return 0;
}
```

输出将是`1 2 3`的所有排列。
```cpp
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
```

#### 示例2：vector

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3};
    do {
        for (int i = 0; i < v.size(); ++i) {
            std::cout << v[i] << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(v.begin(), v.end()));
    return 0;
}
```

输出同样是`1 2 3`的所有排列。

### 应用场景

`next_permutation`在多种场景中都非常有用，包括但不限于：

* **排列组合**：用于生成某个集合的所有排列。
* **字典序排序**：可以按照字典序对集合进行排序。
* **算法优化**：在搜索算法中，可以用来遍历状态空间，从而优化算法性能。
* **算法竞赛**：在编程竞赛中，常用于解决与排列相关的问题。
* **数学问题**：可以用来解决寻找全排列中满足特定条件的排列等数学问题。

总之，`next_permutation`是C++中处理排列问题的一个强大工具，能够显著提高编码效率和代码的可读性。

## 分治算法
分治算法（Divide and Conquer Algorithm）是一种非常重要的算法设计策略，它将一个复杂的大问题分解成若干个规模较小的子问题，递归地解决这些子问题，并将子问题的解合并起来，从而得到原问题的解。这种策略在处理大规模数据时特别有效，因为它能够并行地处理多个子问题，从而提高算法的效率。

### 分治算法的基本步骤

分治算法通常包含三个主要步骤：

1. **Divide（分）**：将原问题分解为若干个规模较小、相互独立、与原问题形式相同的子问题。
2. **Conquer（治）**：递归地解决这些子问题。如果子问题的规模足够小，则直接解决。
3. **Merge（合并）**：将子问题的解合并成原问题的解。

### 分治算法的特点

1. **递归性**：分治算法通常通过递归的方式实现，将大问题分解为小问题，再解决小问题。
2. **并行性**：分治算法可以并行地处理多个子问题，这允许多个CPU或多台计算机同时处理它们，从而提高算法的效率。
3. **独立性**：子问题之间通常是相互独立的，没有重叠和依赖，这有助于并行处理。

### 分治算法的应用

分治算法在计算机科学和算法设计中有着广泛的应用，可以解决许多实际问题。以下是一些典型的应用：

1. **排序算法**：
   - **归并排序**：递归地将原数组划分为两个子数组，分别进行排序，然后合并两个有序的子数组。
   - **快速排序**：选择一个基准值，将数组分为两个子数组，分别小于和大于基准值，然后递归地对这两个子数组进行排序。

2. **搜索算法**：
   - **二分搜索**：在有序数组中，将搜索区间分成两个子区间，然后递归地在其中一个子区间中进行搜索，直到找到目标元素或者子区间为空。

3. **求解最大子数组问题**：将数组分成两个子数组，分别求解左右子数组的最大子数组，然后再考虑跨越中点的最大子数组，最后将这三种情况的最大值作为整个数组的最大子数组。

4. **矩阵乘法**：将两个矩阵分成四个子矩阵，然后递归地进行矩阵乘法，最后将四个子矩阵的结果合并成一个矩阵。


### 分治算法的优点

1. **降低问题复杂度**：通过将大问题分解成多个小问题，每个小问题都更容易解决，从而降低了整体的算法复杂度。这通常是通过递归实现的，每一步都将问题规模减半（或其他比例），使得问题更易于处理。

2. **并行化潜力**：由于分治策略将问题分解为多个独立的子问题，这些子问题可以并行处理。在多核处理器或分布式计算环境中，这种并行性可以显著提高算法的执行效率。

3. **结构清晰**：分治算法的结构通常非常清晰，遵循“分而治之”的原则，使得算法的设计和实现都更加直观和易于理解。

4. **适用性广**：分治策略适用于许多类型的问题，包括排序、搜索、图论、字符串处理等多个领域。

### 分治算法的缺点

1. **递归深度**：对于某些问题，分治算法可能会产生较深的递归调用栈，这可能会消耗大量的内存资源，甚至导致栈溢出错误。在某些情况下，可能需要通过迭代或其他优化技术来避免这个问题。

2. **额外开销**：在分解问题和合并解的过程中，可能会产生一些额外的开销。例如，在归并排序中，需要额外的空间来存储临时数组，以便在合并过程中进行元素比较和移动。这些额外开销可能会降低算法的整体效率。

3. **子问题依赖性**：虽然分治策略通常假设子问题是相互独立的，但在某些情况下，子问题之间可能存在依赖关系。如果忽略这些依赖关系，可能会导致错误的解。因此，在设计分治算法时，需要仔细考虑子问题之间的依赖关系。

4. **并行化挑战**：虽然分治算法具有潜在的并行性，但在实际实现并行化时可能会遇到一些挑战。例如，如何有效地分配子任务到不同的处理器上、如何处理子任务之间的通信和同步等问题都需要仔细考虑。

5. **适用性限制**：虽然分治策略适用于许多类型的问题，但并不是所有问题都适合采用分治策略。在某些情况下，可能需要采用其他算法设计策略来解决问题。

### 总结

分治算法是一种强大而有效的算法设计策略，它通过递归地将大问题分解为小问题，并合并子问题的解来得到原问题的解。这种策略在处理大规模数据时特别有用，因为它可以并行地处理多个子问题，从而提高算法的效率。在计算机科学和算法设计中，分治算法有着广泛的应用，包括排序、搜索、求解最大子数组问题等。

```cpp
//对数组a，下标范围在[ns,ne)的元素进行归并排序
void MergeSort(int*a,int ns,int ne)
{
	//1.递归终止条件
	//半开区间中只有1个元素，这时一定有序 
	if(ne-ns==1)
		return; 
	//2.二分法，取中间位置 
	//对2个子数组进行分开排序 
	int m=ns+(ne-ns)/2;	//取中间位置 
	MergeSort(a,ns,m);	//左半区间归并排序 [ns,m)
	MergeSort(a,m,ne);	//右半区间归并排序 [m,ne)
	//3.合并
	//1)依次取出子数组的元素，进行合并 
	int *ta=new int[ne-ns];//定义一个临时数组 
	int nl=ns,nr=m;	//左半边的子数组和右边的子数组下标 
	int nt=0;		//临时数组的下标
	for(;;){
		//左半区间[ns,m),右半区间[m,ne) 
		if(nl>=m || nr>=ne)
			break;
		if(a[nl]<=a[nr]){	//左边的小 
			ta[nt]=a[nl];	//取左边元素 
			nl++;			//左半部下标右移 
			nt++;			//临时数组的下标右移 
		}
		else{				//右边的小          
			ta[nt]=a[nr];	//取右边元素        	
			nr++;			//右半部下标右移    
			nt++;			//临时数组的下标右移
		}		
	}
	
	//2)如果左半区间没取完，就放到临时数组
	while(nl<m)
		ta[nt++]=a[nl++];
	//3)如果右半区间没取完，就放到临时数组
	while(nr<ne)
		ta[nt++]=a[nr++];
	//4)临时数组赋值给数组a
	for(int i=0;i<ne-ns;i++)
		a[ns+i]=ta[i]; 
	//5)释放临时空间 
	delete[] ta; 
}
#include <iostream>
using namespace std; 
//对数组a，下标范围在[ns,ne)的元素进行归并排序
void MergeSort(int*a,int ns,int ne); 
void print(int*a,int n);
int main()
{
	int a[]={4,1,10,15,37,79,24,11,91,
			 2,18,9,45,21,52,83,98,90};
	int n=sizeof(a)/sizeof(*a);
	MergeSort(a,0,n); 
	print(a,n);
	return 0;
}
void print(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
```




vector补充
```cpp
vector<int> g;
g.push_back(3);
g.push_back(2);
g.push_back(1);

int a = 3;b = 4;
swap(a,b);//交换地址，而不是数字

0x 16进制前缀
o  8进制前缀

{   3, 		2,		 1}
    |       			|
s.begin()				s.end()
sort(s.begin(),s.end());
```
string补充
```
string s;//string是特殊的stl
s.push_back('d');
s.pop_back();
s.substr(i,k);//截取字符串
reverse//翻转
```



# Day23
## 深度优先搜索
深度优先搜索(Depth-First Search,DFS)和广度优先搜索(Breadth-First Search,BFS,或称为宽度优先搜索)是基本的暴力技术，常用于解决图、树的遍历问题。
DFS通过沿着树的深度尽可能深地搜索树的分支，当节点的所有边都被探寻过之后，回溯到发现该节点的那条边的起始节点。

### 实现步骤

1. **初始化**：
   - 创建一个标记数组来表示每个节点的访问状态，并进行初始化。通常使用布尔数组或整型数组来记录每个节点是否被访问过。
   
2. **选择数据结构**：
   - 可以选择递归或栈作为搜索的数据结构。递归是实现DFS的一种简单方式，而栈则适用于需要显式管理路径的情况。

3. **搜索过程**：
   - 从起始节点开始，如果该节点未被访问过，则标记为已访问，并继续对它的第一个未访问的邻接节点进行递归调用或入栈操作。
   - 当当前节点没有更多的未访问邻接节点时，回溯到上一个节点，继续对其邻接节点进行相同的操作，直到所有可达节点都被访问过为止。

### 示例代码（递归实现）

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 定义图的邻接表
vector<vector<int>> graph;

// 标记数组，用于记录节点是否被访问过
vector<bool> visited;

void DFS(int vertex) {
visited[vertex] = true;
cout << vertex << " ";
    
for (int neighbor : graph[vertex]) {
if (!visited[neighbor]) {
DFS(neighbor);
}
}
}

int main() {
int vertices = 6; // 假设图中有6个顶点
graph.resize (vertices);
visited.resize (vertices, false);

// 添加一些边以构建示例图
graph[0].push_back(1);
graph[0].push_back(2);
graph[1].push_back(3);
graph[2].push_back(4);
graph[2].push_back(5);
graph[4].push_back(5);

cout << "DFS Traversal: ";
DFS(0); // 从顶点0开始遍历

return 0;
}
```

### 示例代码（栈实现）

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义图的邻接表和栈
vector<vector<int>> graph;
stack<int> s;

void DFS(int vertex) {
visited[vertex] = true;
cout << vertex << " ";
    
for (int neighbor : graph[vertex]) {
if (!visited[neighbor]) {
s.push (neighbor);
}
}
}

int main() {
int vertices = 6; // 假设图中有6个顶点
graph.resize (vertices);
visited.resize (vertices, false);

// 添加一些边以构建示例图
graph[0].push_back(1);
graph[0].push_back(2);
graph[1].push_back(3);
graph[2].push_back(4);
graph[2].push_back(5);
graph[4].push_back(5);

cout << "DFS Traversal (Stack): ";
while (!s.empty ()) {
int currentVertex = s.top ();
s.pop ();
if (!visited[currentVertex]) {
cout << currentVertex << " ";
visited[currentVertex] = true;
for (int neighbor : graph[currentVertex]) {
if (!visited[neighbor]) {
s.push (neighbor);
}
}
}
}

return 0;
}
```

### 应用场景
在C++中，深度优先搜索（DFS）和广度优先搜索（BFS）是两种常用的图遍历算法，它们各有优缺点和适用场景。

#### 深度优先搜索（DFS）
**特点：**
1. **内存使用较少**：由于DFS是通过递归调用栈来实现的，因此它占用的内存相对较少。
2. **速度较慢**：由于DFS需要不断回溯，导致其运行速度较慢。
3. **适合解决需要找到路径的问题**：例如在迷宫游戏中寻找出口路径时，DFS可以有效地找到一条可行路径。

**适用场景：**
- **图的连通性检测**：用于判断一个图是否连通。
- **寻找所有可能的解决方案**：例如在解决八数码问题时，DFS可以用来找到所有可能的解决方案。
- **路径查找**：如在迷宫游戏中寻找从起点到终点的路径。

#### 广度优先搜索（BFS）
**特点：**
1. **速度快**：由于BFS使用队列来保存未被访问的节点，并按层次顺序进行访问，因此其运行速度较快。
2. **内存使用较多**：由于BFS需要存储更多的节点信息，因此它占用的内存较多。
3. **适合解决最短路径问题**：在图中寻找从起点到终点的最短路径时，BFS是一个很好的选择。

**适用场景：**
- **最短路径问题**：例如在社交网络中寻找两个用户之间的最短关系链。
- **图的层次遍历**：如在树形结构中按层次遍历节点。
- **无回溯操作的需求**：在某些情况下，不需要回溯操作，可以直接按层次顺序处理问题。

#### 总结
- **DFS**适合于内存有限且需要找到路径的情况，但速度较慢。
- **BFS**适合于需要快速找到最短路径或按层次遍历的情况，但内存使用较多。

### 深度优先搜索（DFS）在C++中的性能优化技巧有哪些？

在C++中，深度优先搜索（DFS）的性能优化技巧主要包括以下几个方面：

   剪枝技术是深度优先搜索中的重要优化手段。通过剪除那些冗余且无效的搜索路径，可以显著减少计算量和时间消耗。例如，在探索过程中，如果发现某个分支不可能导致目标状态，则可以提前终止该分支的进一步探索。

   在一些特定的搜索问题中，搜索树的各个层次、各个分支之间的顺序不是固定的。不同的搜索顺序会产生不同的搜索树形态，其规模大小也相差甚远。因此，合理安排搜索顺序可以有效减少搜索空间，提高搜索效率。

   迭代加深是一种逐步增加搜索深度的方法。每次选取一个分支进行深入搜索，并不断调整搜索深度以确保找到最优解。这种方法可以在保证找到全局最优解的同时，避免过度深入无效区域。

   记忆化搜索通过记录每个状态的搜索结果，在重复遍历一个状态时直接检索并返回结果，从而避免了重复计算。这类似于对图进行深度优先遍历时，标记一个节点是否已经被访问过。记忆化的加强版可以理解为动态规划的一部分。

### 如何在C++中实现深度优先搜索时处理循环边和自环？

在C++中实现深度优先搜索（DFS）时处理循环边和自环，可以通过记录每个节点的父节点来检测环路。具体步骤如下：

1. **初始化**：为每个节点设置一个父节点指针，初始时所有节点的父节点都指向`-1`或`NULL`。
2. **遍历节点**：从根节点开始，递归地访问其子节点。在访问每个子节点时，将当前节点作为其父节点。
3. **检测环路**：如果在访问某个节点时发现该节点已经存在一个父节点，并且这个父节点不是当前正在访问的节点，则说明存在环路。

以下是一个简单的C++代码示例，展示了如何使用上述方法检测环路：

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 检测环路的函数
bool detectCycle(vector<vector<int>>& graph, int node, int parent, vector<int>& visited) {
visited[node] = 1; // 标记当前节点已访问

for (int child : graph[node]) {
if (visited[child] == 0) { // 如果子节点未被访问过
if (detectCycle(graph, child, node, visited)) {
return true;
}
} else if (child != parent) { // 如果子节点已被访问且不是父节点，则存在环
return true;
}
}

visited[node] = 2; // 标记当前节点已完全处理
return false;
}

// 主函数
int main() {
int n;
cin >> n;
vector<vector<int>> graph(n);

// 构建图
for (int i = 0; i < n - 1; ++i) {
int u, v;
cin >> u >> v;
graph[u].push_back(v);
graph[v].push_back(u); // 对于无向图
}

vector<int> visited(n, 0); // 初始化访问数组

// 调用检测环路的函数
bool hasCycle = detectCycle(graph, 0, -1, visited);

if (hasCycle) {
cout << "存在环" << endl;
} else {
cout << "不存在环" << endl;
}

return 0;
}
```

在这个例子中，我们首先读取图的节点数和边，然后构建图的邻接表表示。接着，我们调用`detectCycle`函数来检测是否存在环。如果存在环，则返回`true`；否则，返回`false`。

### 在C++中实现深度优先搜索时，如何有效地管理和存储访问状态数组以避免内存泄漏？

在C++中实现深度优先搜索（DFS）时，有效地管理和存储访问状态数组以避免内存泄漏的关键在于合理使用数据结构和控制访问状态的范围。根据，我们可以通过一个布尔数组`visited[VeNum]`来标记每个顶点的访问状态，其中`VeNum`是图中顶点的数量。当一个顶点被访问时，将其状态设为`true`，未访问过的顶点则保持`false`。

为了有效管理内存并避免泄漏，可以采取以下策略：

1. **限制搜索深度**：正如所述，通过设置一个最大深度限制，当达到该深度时停止搜索，可以减少不必要的内存使用。这不仅有助于控制内存使用，还能提高算法的效率。

2. **重用对象**：在某些情况下，可以考虑重用已经创建的对象，而不是每次都需要创建新的对象。这可以减少内存分配和释放的次数，从而降低内存泄漏的风险。

3. **使用对象池**：对象池是一种常见的技术，用于减少频繁创建和销毁对象的开销。通过预先分配一定数量的对象，并在需要时从池中获取，可以有效管理内存使用。

4. **避免临时对象**：尽量减少临时对象的创建，因为这些对象可能不会被立即销毁，从而导致内存泄漏。可以通过优化代码逻辑，减少不必要的临时变量创建。

5. **并行化**：对于大规模数据集，可以考虑将搜索任务并行化，以减少单个线程的内存压力。这需要确保数据的一致性和同步机制的正确实现。

6. **减少不必要的拷贝**：在处理数据结构时，尽量避免不必要的数据拷贝操作。例如，在复制图的邻接表时，可以直接复制指针而不是整个节点。

7. **优化数据结构**：选择合适的数据结构对于提高内存使用效率至关重要。例如，使用邻接表而不是邻接矩阵来表示图，可以显著减少空间占用。

8. **应用剪枝技术**：在搜索过程中，通过剪枝技术减少无效路径的探索，可以减少内存使用和计算时间。

9. **启发式搜索**：在某些问题中，可以使用启发式函数来指导搜索方向，减少无效搜索的次数，从而节省内存和时间。

#### 深度优先搜索在解决实际问题（如网络爬虫、社交网络分析等）中的应用案例有哪些？

深度优先搜索（DFS）在解决实际问题中有着广泛的应用，特别是在网络爬虫和社交网络分析等领域。以下是具体的案例分析：

1. **社交网络分析**：
   - **节点遍历与搜索**：在社交网络中，DFS可以用于遍历用户节点，找到特定用户的路径或关系链。
   - **关键节点识别与影响力分析**：通过DFS算法，可以识别出在网络中具有重要影响力的节点，这对于理解网络结构和进行精准营销等有重要意义。
   - **子图发现**：DFS还可以用于发现网络中的子图结构，帮助识别紧密连接的群体或社区。

2. **网络爬虫**：
   - **深度优先搜索策略**：在实现网络爬虫时，DFS算法可以帮助快速到达目标深度的页面，从而提高爬取效率。
   - **递归与非递归实现**：DFS可以通过递归和非递归两种形式实现，适应不同的编程需求和场景。

### 搜索与回溯
```cpp
void dfs(int x){
	if(x == 0) return;
	cout << x << endl;
	//向下搜

	dfs(x-1)；

	//回溯
	cout << x << endl;
	return;
}
```
### 全排列
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int vis[10010],n;
void dfs(vector<int> g,int cnt){
	if(cnt == n){
		for(int i = 0 ;i < n; i++){
			cout << g[i] << " ";
		}
		cout  <<  endl;
		return;
	}
	for(int i = 1 ; i <= n; i++){
		if(vis[i]) continue;//已经标记就跳过
		g.push_back(i);
		vis[i] = 1;//标记
		dfs(g, cnt + 1);
		g.pop_back();
		vis[i] = 0;//取消标记
	}
}
signed main(){
	cin >> n;
	dfs({},0);
	return 0;
}
```


两个坐标是否为对角线
(x1,y1),(x2,y2)

1. x1 - y1 == x2 - y2 ?
2. x1 + y1 == x2 + y2 ? 

# Day24

## BFS广度优先搜索
广度优先搜索（Breadth-First Search, BFS）是一种用于遍历或搜索树或图的算法。
这个算法从一个节点开始，探索该节点的所有直接邻居，然后再对每一个邻居节点进行同样的操作，直到找到目标节点或遍历完所有可达的节点。
BFS通常使用队列（Queue）来实现。

### bfs和dfs的区别：
`dfs`往一个方向深搜后返回再搜
`bfs`往多个方向广搜

### 基本步骤

1. **初始化**：选择一个起始节点，将其放入队列中。
2. **循环**：当队列非空时，执行以下步骤：
   - 从队列中移除一个节点（通常是队首节点）。
   - 访问该节点（例如，打印节点值或进行其他处理）。
   - 将该节点的所有未访问过的直接邻居节点加入队列中。
3. **结束**：当队列为空时，算法结束。

### 基本作用

- BFS在搜索最短路径时非常有用，因为它总是先访问起始节点附近的节点。
- BFS在无权图中特别有效，但在有权图中，如果边的权重不同，则可能需要使用其他算法（如Dijkstra算法）来找到最短路径。
- BFS的时间复杂度依赖于图的表示和图的结构。在最坏的情况下（图是完全连接的），时间复杂度为O(V + E)，其中V是顶点数，E是边数。在最好的情况下（图是线性的），时间复杂度为O(V)。
- BFS的空间复杂度主要由队列决定，最坏情况下为O(V)，因为所有节点都可能被加入队列中。

## 样例：波浪形扩散原理
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, vis[1001][1001], dist[1001][1001];
struct point{
	int x, y;
};

int dx[] = {1, -1,  0,  0};  
int dy[] = {0,  0,  1, -1};//上下左右

signed main(){
	cin >> n >> m;
	
	queue<point> q;
	
	q.push({1, 1});  //起点 
	vis[1][1] = 1;
	dist[1][1] = 0;
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point s;
			s.x = t.x + dx[i];
			s.y = t.y + dy[i];
			if(s.x <= 0 || s.y <= 0 || s.x > n || s.y > m) continue;
			if(vis[s.x][s.y] == 1) continue;
			vis[s.x][s.y] = 1;
			dist[s.x][s.y] = dist[t.x][t.y] + 1;
			q.push(s);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << dist[i][j] << " \n"[j==m];
		}
	}
	return 0;
}
```

### 样例：走迷宫
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int maxn = 1e6 + 100;
const double eps = 1e-5;

//上下左右
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int mapp[100][100], vis[100][100];
int ok = 0;

struct point {
	int x, y;
	int step;
};
queue<point> s;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m; cin >> n >> m;
	//输入地图
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mapp[i][j];
		}
	}

	int startx, starty, endx, endy; 
	cin >> startx >> starty >> endx >> endy;
	
	//初始化起点并入队
	point start; //结构体
	start.x = startx, start.y = starty, start.step = 1;
	s.push(start); 
	vis[startx][starty] = 1;//vis 打标记，记录已经走过的点
	//go
	while (!s.empty()) {
		int x = s.front().x, y = s.front().y;
		s.pop();
		if (x == endx && y == endy) {
			ok = 1;
			cout << s.front().step << endl;
			break;
		}
		for (int choose = 0; choose <= 3; choose++) {
			int tx = x + dx[choose]; 
			int ty = y + dy[choose];//方向
			if (mapp[tx][ty] == 0 && vis[tx][ty] == 0) {
				point tmp; 
				tmp.x = tx; 
				tmp.y = ty; 
				tmp.step = s.front().step + 1;
				s.push(tmp); 
				vis[tx][ty] = 1;
			}
		}
	}
	if (ok == 0) {
		cout << "no ans" << endl;
	}
	return 0;
}
[输入样例]
3 3
0 0 0
1 0 0
0 0 1
1 1 3 1
[输出]
5
```

# Day27
## 动态规划
动态规划（Dynamic Programming, DP）是一种在数学、计算机科学和经济学中使用的，通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。在C++中实现动态规划通常涉及定义一个或多个数组（或向量）来存储子问题的解，以避免重复计算。

### 定义

动态规划通过把原问题分解为相对简单的子问题的方式求解复杂问题。它通常涉及以下几个关键步骤：

1. **定义状态**：将问题分解为一系列子问题，并定义状态来表示这些子问题的解。
2. **状态转移方程**：找出状态之间的关系，即如何从已知状态推导出新的状态（或解）。
3. **初始化**：确定初始状态的值。
4. **计算顺序**：确定计算状态的顺序，通常是自底向上（从简单到复杂）的顺序。
5. **存储结果**：使用数组、向量或其他数据结构来存储中间结果，以便后续使用。

### 语法

由于动态规划是一种算法设计思想，而不是具体的语法结构，因此它没有特定的语法。但是，在C++中实现动态规划时，通常会使用到以下语法元素：

- **数组**（或`std::vector`）：用于存储状态（即子问题的解）。
- **循环**（如`for`、`while`）：用于遍历状态空间，计算状态转移方程。
- **条件语句**（如`if`、`else`）：用于处理特殊情况或边界条件。
- **函数**：将动态规划的逻辑封装在函数中，以便复用或测试。

### 用途

动态规划广泛应用于各种领域，特别是在计算机科学中，用于解决优化和计数问题。以下是一些常见的应用场景：

- **优化问题**：如最短路径问题、最长公共子序列（LCS）、背包问题等。
- **计数问题**：如不同路径的数量、排列组合问题等。
- **决策过程**：如编辑距离、字符串匹配问题等。

### 示例

下面是一个使用C++实现的动态规划经典问题——斐波那契数列（Fibonacci Sequence）的示例。斐波那契数列是这样一个数列：0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...，其中每个数是前两个数的和。

**斐波那契数列的C++实现（动态规划）**

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 动态规划求解斐波那契数列
int fibonacciDP(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    // 创建一个数组来存储斐波那契数列的值
    vector<int> dp(n + 1, 0);
    dp[1] = 1; // 初始化第一个值

    // 从第二个数开始计算
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // 动态规划的核心递推公式
    }

    return dp[n];
}

int main() {
    int n;
    cout << "请输入n的值（斐波那契数列的第n项）: ";
    cin >> n;

    cout << "斐波那契数列的第" << n << "项是: " << fibonacciDP(n) << endl;

    return 0;
}
```

在这个例子中，我们使用了`vector<int>`来存储斐波那契数列的值，以避免重复计算。通过从第二项开始迭代计算，直到第n项，我们得到了整个数列的解。这种方法的时间复杂度是O(n)，空间复杂度也是O(n)，因为我们使用了一个大小为n+1的数组来存储中间结果。

动态规划的应用非常广泛，包括但不限于背包问题、最长公共子序列（LCS）、最短路径问题等。每种问题都有其特定的状态定义和转移方程，但基本思想都是类似的：将大问题分解为小问题，并存储已解决的小问题的答案，以避免重复计算。


# Day28
## 01背包&&完全背包

① 01背包:每件物品最多使用一次(只能使用0次或1次)
(一)状态表示 f(i j)
1. 集合:只考虑前i个物品，且总体积不大于i的所有选法。
2. 属性:Max、Min、数量

(二)状态计算-→集合划分-→f[i,j]= Max( f[i-1,j],f[i-1,j-V[i]]+ W[i])

② 完全背包:每件物品有无限个
(一)状态表示 f(i,j)
1. 集合:只考虑前i个物品，且总体积不大于i的所有选法
2. 属性:Max、Min、数量

(二)状态计算--→集合划分--→f[i,j]= Max( f[i-1,j],f[i, j-V[i]]+ W[i])

### 01背包问题
有$N$件物品和一个容量是$V$的背包，每件物品只能使用一次。
第$i$件物品的体积是$Vi$，价值是$Wi$。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
n  m//n=4,m=5
4  5
1  2
2  4
3  4
4  5

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1010;

int n, m;
int v[N], w[N];
int f[N];

int main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> v[i] >> w[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--){  //从大到小循环
			f[j] = max(f[j], f[j-v[i]] + w[i]);
		}
	}
	
	cout << f[m] << endl;
				
	return 0;
}
```

# Day 30
## 并查集
### 朴素并查集
- 路径压缩
- 按秩合并
  
例题[P1551](https://www.luogu.com.cn/problem/P1551)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

vector<int> p(5010);//我的父亲是谁
//初始化
void init(int n){
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;//自己是自己的监护人
    }
    
}
//找自己最上面的祖宗 近乎O(1)
int find(int x){
	/* 
    if(x != p[x]){
        return find(p[x]);//上面还有人
    }
    else{
        return x;//自己就是自己的监护人，即祖宗
    }
	*/
	if(x != p[x]){
        p[x] = find(p[x]);//路径压缩[better!]
    }
    return p[x];
}
//合并
void merge(int u,int v){
    int pu = find(u);
    int pv = find(v);
    if(pu != pv){
        p[pu] = pv;//新爹，合并完成
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    init(n);
    while (m--){
        int u, v;
        cin >> u >> v;
        merge(u, v);//有亲戚关系的人合并
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
```
### 带权并查集(size并查集)

- size并查集：查询数组的大小权值

例题[P1551](https://www.luogu.com.cn/problem/P1551)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

vector<int> p(N);//我的父亲是谁
vector<int> siz(N);//集合大小
//初始化
void init(int n){
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;//自己是自己的监护人
        siz[i] = 1;
    }
    
}
//找自己最上面的祖宗 近乎O(1)
int find(int x){
	if(x != p[x]){
        p[x] = find(p[x]);//路径压缩[better!]
    }
    return p[x];
}
//合并
void merge(int u,int v){
    int pu = find(u);
    int pv = find(v);
    if(pu!=pv){
        siz[pv] += siz[pu];
        p[pu] = pv;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    init(n);
    while (m--){
        int u, v;
        cin >> u >> v;
        merge(u, v);//有亲戚关系的人合并
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
```
# Day31
## 素数判定
- 大素数判定：随机一些数去试除n
- 费马小定理：如果n是素数，那么$a^{n-1} mod\ n = 1$  
- 逆命题：如果$a^{n-1} mod\ n = 1$，那么n就是素数（不一定成立）
- 如果$a^{n-1} mod\ n != 1$，那么n肯定不是素数（成立）
- 随机多个a，计算$a^{n-1} mod\ n$，都等于1，$n$ 大概率是素数
（可惜的是有很小很小很小的一部分合数，无论a取什么值他都能通过测试，怎么排除这部分合数？）
- 二次探测定理
推论：方程$x^2 mod\ n = 1$，如果$x$有$x=1$和$x=n-1$以外的解，$n$肯定不是素数。
### Miller-Rabin算法模板
```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull; // 自然溢出
typedef pair<int,int> PII;
const int S = 50; // 测试数
// 快速乘,防止乘法溢出longlong
ll mult_mod(ll u,ll v,ll p){
    return (u * v - ll((long double)u * v / p) * p + p) % p;
}
// 快速幂
ll fast_pow(ll x,ll y,ll mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1) res = mult_mod(res,x,mod);
        x = mult_mod(x,x,mod);
        y >>= 1;
    }
    return res;
}

bool witness(ll a,ll n){
    ll u = n - 1;
    int t = 0;
    // 计算t,u,对n-1一直除2,直到是奇数,剩下的奇数是u,除2次数是t
    while(u & 1 == 0){u = u >> 1,t++;} 
    ll x1,x2;
    x1 = fast_pow(a,u,n); // 计算a^u
    // 做t次平方
    for(int i = 1;i <= t;i++){
        x2 = fast_pow(x1,2,n); // 平方后的结果
        // 二次探测定理
        if(x2 == 1 && x1 != 1 && x1 != n - 1) return true; // 必然是合数
        x1 = x2;
    }
    // 最后x1=a^n-1,费马小定理
    if(x1 != 1) return true; // 必然是合数
    return false;
}

int miller_rabin(ll n){
    if(n < 2) return 0; // 小于2是合数
    if(n == 2) return 1; // 2是质数
    if(n % 2 == 0) return 0; // 偶数是合数
    // 剩下做测试
    for(int i = 0;i < S;i++){
        ll a = rand() % (n - 1) + 1; // 随机一个a
        if(witness(a,n)) return 0; // 测试
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);
    ll n;
    cin >> n;
    if(miller_rabin(n)){
        cout << "P" << endl;
    }
    else{
        cout << "not P" << endl;
    }
    return 0;
}
```


## 逆元
通俗的讲，逆元可以看做一个数的倒数的整数形式，但是一个数的逆元在不同的($mod$)意义下是不一样的。
- $a\times x\equiv1\quad\mathrm{mod~}n$ → $a\times\frac1a\equiv1\quad\mathrm{mod~}n$
  
这个方程便是逆元的真正定义，$x$的解即代表$a$在$~mod~n~$意义下的逆元，通俗的讲：此时的$x$就相当于$a$的倒数，这样$a×x$便会等于1，在$~mod~n~$意义下余数必定为一。当然这个式子要建立在$a$与$n$互质
的基础上！

可是逆元有什么用呢？直接用倒数不行吗？这是因为我们发现一个分数$~mod~$一个整数时是不能直接模运算的，但是可以进行乘法运算，我们就要用到逆元（一个数倒数的整数形式）

就像:$\quad\frac ab\quad\mathrm{mod~}(n)\neq\frac{a\mathrm{~mod~}n}{b\mathrm{~mod~}n}\quad\mathrm{mod~}(n)$
但是:$\quad\frac ab\quad\mathrm{mod~}(n)=a\times b^{-1}\quad\mathrm{mod~}(n)$

所以当除运算碰上我们的模运算时，我们就需要$~mod~模数$意义下的逆元了！

[详细解释](https://www.cnblogs.com/812-xiao-wen/p/10500580.html)

用逆计算组合数取模
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

#define endl '\n'

const ll mod = 998244353;

ll fpow(ll x,ll y,ll mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1) res = (res * x) % mod;
        x = (x * x) %mod;
        y >>= 1;
    }
    return res;
}

ll inv(ll x){
	ll res = fpow(x,mod - 2,mod);
	return res;
}

ll fac[100005]; // 阶乘 fac[i] = i!
ll invfac[100005]; // 阶乘的逆 

void init(){
	fac[0] = 1;
	invfac[0] = 1;
	for(int i = 1;i <= 100000;i++){
		fac[i] = (fac[i - 1] * i) % mod;
		invfac[i] = (invfac[i - 1] * fpow(i,mod - 2,mod)) % mod;
	}
} 

ll C(ll a,ll b){
	if(a < b){
		return 0;
	}
	ll res = (((fac[a] * invfac[b] ) % mod)* invfac[a - b]) % mod;
	return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ll a,b;
    cin >> a >> b;
    ll res = C(a,b);
    cout << res << endl;
    return 0;
}
```

# Day32 
## 素数筛法
**引入**
如果我们想要知道小于等于 n 有多少个素数呢？
一个自然的想法是对于小于等于 n 的每个数进行一次质数检验。这种暴力的做法显然不能达到最优复杂度。

### 埃氏筛 (省空间)
**过程**
考虑这样一件事情：对于任意一个大于 1 的正整数 n，那么它的 x 倍就是合数（x > 1）。利用这个结论，我们可以避免很多次不必要的检测。
如果我们从小到大考虑每个数，然后同时把当前这个数的所有（比自己大的）倍数记为合数，那么运行结束的时候没有被标记的数就是素数了。
**实现**
```cpp
vector<int> prime;
bool is_prime[N];

void Eratosthenes(int n) {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) is_prime[i] = true;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime.push_back(i);
      if ((long long)i * i > n) continue;
      for (int j = i * i; j <= n; j += i)
        // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
        // 的倍数开始，提高了运行速度
        is_prime[j] = false;  // 是 i 的倍数的均不是素数
    }
  }
}
```
以上为 Eratosthenes 筛法（埃拉托斯特尼筛法，简称埃氏筛法），时间复杂度是 $O(n\log\log n)$。

**样例**
[【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)
```cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e8;
int prime[N + 5]; // 存放所有素数，下标从0开始
bool vit[N + 5];   // 是否被筛掉
int k = 0;        // 统计素数个数

// 埃氏筛 
void E_sieve(int n){
    // 初始化
    k = 0;
    for (int i = 0; i <= n; i++){
        vit[i] = 0;
    }
    //试除法
    for (int i = 2; i * i <= n; i++){
        if (vit[i] == 0){
            for (int j = i * i; j <= n; j += i){
                vit[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (vit[i] == 0){
            prime[k++] = i;
        }
    }
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
	cin>>n>>q; 
	E_sieve(n);
	while(q--){
		int x;
		cin>>x;
        cout << prime[x - 1] << endl;
    }
}
```

## 欧拉筛(速度快)
筛法求欧拉函数 
注意到在线性筛中，每一个合数都是被最小的质因子筛掉。比如设 $p_{1} $ 是 $n$ 的最小质因子，$ n^{\prime}=\frac{n}{p_{1}} $ ，那么线性筛的过程中 $n$ 通过 $n^{\prime} \times p_{1} $筛掉。
观察线性筛的过程，我们还需要处理两个部分，下面对 $n^{\prime} \bmod p_{1}$ 分情况讨论。
如果 $n^{\prime} \bmod p_{1}=0 $ ，那么 $ n^{\prime} $ 包含了 $ n $ 的所有质因子。
$\begin{aligned}\varphi(n) & =n \times \prod_{i=1}^{s} \frac{p_{i}-1}{p_{i}} \\& =p_{1} \times n^{\prime} \times \prod_{i=1}^{s} \frac{p_{i}-1}{p_{i}} \\& =p_{1} \times \varphi\left(n^{\prime}\right)\end{aligned}$
那如果 $ n^{\prime} \bmod p_{1} \neq 0 $ 呢，这时 $ n^{\prime}  和 $ p_{1} $ 是互质的，根据欧拉函数性质，我们有:
$$ \begin{aligned}\varphi(n) & =\varphi\left(p_{1}\right) \times \varphi\left(n^{\prime}\right) \\& =\left(p_{1}-1\right) \times \varphi\left(n^{\prime}\right)\end{aligned}$$
**实现**
```cpp
vector<int> pri;
bool not_prime[N];
int phi[N];

void pre(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!not_prime[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i & pri_j == 0) {
        phi[i * pri_j] = phi[i] * pri_j;
        break;
      }
      phi[i * pri_j] = phi[i] * phi[pri_j];
    }
  }
}
```
**样例**
[【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)
```cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e8;
int prime[N + 5]; // 存放所有素数，下标从0开始
bool vit[N + 5];   // 是否被筛掉
int k = 0;        // 统计素数个数

// 欧拉筛 O(n)
// 让每一个数只被自己最小的质因子筛掉
void E_sieve(int n){
    // 初始化
    k = 0;
    for (int i = 0; i <= n; i++){
        vit[i] = 0;
    }
    // 做筛子的数 每一个数
    for (int i = 2; i <= n; i++){
        // 是素数直接存入
        if (vit[i] == 0){
            prime[k++] = i;
        }
        // 枚举的倍数乘已经有的素数，这个素数要作为最小质因子
        for (int j = 0; j < k; j++){
            // 超过n退出
            if (i * prime[j] > n){
                break;
            }
            vit[i * prime[j]] = 1; // 合数筛掉
            // 倍数里有小的质因子，后面更大的质因子就不用看了
            if (i & prime[j] == 0) {
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    E_sieve(n);
    while (q--)
    {
        int x;
        cin >> x;
        cout << prime[x - 1] << endl;
    }
}
```

# Day33
## 图论
### dfs
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> g[4];
int vis[1000];
int u, v;
bool dfs(int x){
	if(x==v)
		return true;
	vis[x] = 1;
	bool ok = 0;
	for (int i = 0; i < g[x].size();i++){
		if(vis[g[x][i]])
			continue;
		if (dfs(g[x][i]) == true){
			ok = true;
		}
	}
	return ok;
}

int main(){
	g[1].push_back(2);
	g[1].push_back(3);
	g[2].push_back(3);

	cin >> u >> v;
	cout << (dfs(u) ? "YES" : "NO");
}
```
### bfs(更好)
[图的遍历（简单版）](https://www.luogu.com.cn/problem/B3862)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

vector<int> g[1001];
int n, m,vis[1001];

int bfs(int u){
    for (int i = 1; i <= n;i++){
        vis[i] = 0;
    }//清空标记
    queue<int> q;
    q.push(u);//推入初始点
    vis[u] = 1;
    int mx = u;
    while(q.size()){
        int t = q.front();//拿出一个点
        q.pop();
        for(auto i:g[t]){//遍历所有边
            if(vis[i]==1)//如果已经推进去了就跳过
                continue;
            vis[i] = 1;//标记
            mx = max(mx, i);
            q.push(i);//并推入
        }
    }
    return mx;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); // 有向图存数
        // g[y].push_back(x); // 无向图存数
    }
    for (int i = 1; i <= n;i++){
        cout << bfs(i) << " \n"[i == n];
    }
        return 0;
}
```

### 反向图
[P3916 图的遍历](https://www.luogu.com.cn/problem/P3916)
#### dfs
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

vector<int> g[100010];
int n, m,vis[100010];

void dfs(int x,int d){
    if(vis[x]) return;//如果已经被探过了就返回
    vis[x] = d;
    for (int i = 0; i < g[x].size();i++){
        dfs(g[x][i], d);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        g[y].push_back(x); // 反向图
    }
    for (int i = n; i >=1;i--){//反向探
        dfs(i,i);
    }
    for (int i = 1; i <= n;i++){
        cout << vis[i] << " \n"[i == n];
    }
        return 0;
}
```
#### bfs
```cpp
#include<bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int v[100001],n,m;
void bfs(int u){
	queue<int>q;
	q.push(u);//推入起始点 
	if(v[u]==0)
	v[u]=u;
	while(q.size()){
		int t=q.front();
		q.pop();
		for(auto i : a[t]){//遍历所以边 
			if(v[i]!=0) continue;
			v[i]=u;
			q.push(i);
		}
	}
}
int main()
{
	for(int i=1;i<=n;i++){
		v[i]=0;
	}
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[y].push_back(x);
	}
	for(int i=n;i>=1;i--){
		bfs(i);
	}
	for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
}
```


## 博弈论
若`a == b`,则对面怎么拿我就怎么拿，即必胜
可以推导出 `a^b == 0` 为必输态
必胜态在一定条件下可以转换成必输态
将必输态留给对面则必胜
```cpp
若 a^b^c^d == z 且 z>0
一定存在一个x
使得 (a-x)^b^c^d == 0	//必输态
```

## 离散化
```cpp
vector<int> g;
for (int i = 1; i <= n; i++){
	g.push_back(a[i]);
}
sort(g.begin(), g.end());
g.erase(unique(g.begin(), g.end()), g.end());//去重
[ 1, 3, 4 ] 
for (int i = 1; i <= n; i++){
	a[i] = lower bound(g, begin(), g.end(), a[i]) - g.begin() + 1;
	cout << a[i] << " \n"[i == n];
}
```


## 去重

$g.erase(unique(g.begin(),g.end()),g.end());$//去重

在STL中unique函数是一个去重函数， unique的功能是去除相邻的重复元素(只保留一个),其实它并不真正把重复的元素删除，是把重复的元素移到后面去了，然后依然保存到了原数组中，然后 返回去重后最后一个元素的地址，因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序。

sort，unique和erase的联合使用,可以将一个有重复元素的数组的重复元素去除，从而转化成一个无重复元素的数组
```cpp
end_unique=unique(result.begin(),result.end());
result.erase(end_unique,result.end());
```
由于 end_unique返回去重后最后一个元素的位置，而重复的元素都被移动到后面去了，所以要将从去重后最后一个元素的地址 到 原数组最后一个地址 这些地址中的元素去掉，从而得到无重复元素的数组

`lower_bound && upper_bound`
内置函数二分$O(logn)$
```cpp
lower_bound(l,r,x)	// 在l~r中找到第一个大于等于x的下标
// [1 2 3 4 5 6] 需要升序
upper_bound(l,r,x)	// 在l~r中找到第一个大于x的下标
```

# Day33
## 树

