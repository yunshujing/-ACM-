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


//Day9
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



//Day10
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


//Day11
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

Day12
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



// Day13
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


//Day15
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

Day16
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



Day17
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


//Day18
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



Day21
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
