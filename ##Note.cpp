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

//Day5
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


//Day8
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
