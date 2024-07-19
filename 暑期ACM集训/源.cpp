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

//Day5
/*
## STL
STL��C���Ա�׼�е���Ҫ��ɲ���
��ģ����ͺ�������ʽ�ṩ���ݽṹ���㷨�Ż�
STL���·�Ϊ3�࣬�������㷨��������

STL����Ҫ��ɲ���
���������ڴ洢���ݼ��ϵ�ͨ����ģ�壬����������������vector��list��deque����������������set��multiset��map��multimap������������������stack��queue��priority_queue����
�㷨�����ڶ������е�Ԫ�ؽ��и��ֲ�����ͨ�ú���ģ�壬�����������������Ƶȡ�
��������ʵ��STL�㷨���������������ͨ��ָ��


### vector��̬����
�� C++ �У�vector ��һ��ģ���࣬���ڴ洢һ����̬����, ����ʱ������Ҫ�ı������С
	`vector <��������> ��������`
e.g.vector <int> a;       Ĭ�ϳ�ʼ����aΪ��
e.g.vector <int> b(a);	  ��a����b
e.g.vector <int> a(100);  a��100��ֵΪ0��Ԫ��
���ٿռ�����ֱ�ӷ���a[0]...a[99]��û���ã����������޷����ʣ������

#### ��ά����
�����ά���飬���綨��һ����ά���� : `vector<int> a[MAXN];`
���ĵ�һά��С�ǹ̶���MAXN���ڶ�ά�Ƕ�̬�ġ�
�������ʽ������ʵ��ͼ���ڽӱ�洢��

#### vector�﷨
| ���� | ���� | ˵��|
|-------- | --------- | -------- |
|��ֵ | a.push back(100); | ��β�����Ԫ��|
|Ԫ�ظ��� | int size = a.size(); | Ԫ�ظ���|
|�Ƿ�Ϊ�� | bool isEmpty = a.empty(); | �Ƿ�Ϊ��|
|��ӡ | cout << a[0] << endl; | ��ӡ��һ��Ԫ��|
|�м���� | a.insert(a.begin() + i, k); | �ڵ�i��Ԫ��ǰ�����k|
|β������ | a.push_back(8); | β������Ϊ8��Ԫ��|
|β������ | a.insert(a.end(), 10, 5); | β������10��ֵΪ5��Ԫ��|
|ɾ��β�� | a.pop_back(); | ɾ��β��Ԫ��|
|ɾ������ | a.erase(a.begin() + i, a.begin() + j); | ɾ������[i, j - 1]��Ԫ��|
|ɾ��Ԫ�� | a.erase(a.begin() + 2); | ɾ����3��Ԫ��|
|������С | a.resize(n); | �����С��Ϊn|
|��� | a.clear(); |
|��ת | reverse(a.begin(), a.end()); | �ú���reverse��ת���� |
|���� | sort(a.begin(), a.end()); | �ú���sort���򣬴�С����|

#### ��������
```c
#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> a;
	vector <int> a(100);  //a����100��ֵΪ0��Ԫ��
	//���ٿռ�����ֱ�ӷ���a[0]...a[99]��û���ã����������޷����� �����
	a.push_back(8);
	a.push_back(7);
	cout << a.size();//Ԫ�ظ���
	cout << *a.begin();//a[0],a.begin()������������ָ�룬Ҫ�ý����÷�
	cout << *(a.end()-1);//a.end()ָ�����Ԫ�صĺ�һλ
	return 0;
}
```

#### ������&&ѭ������
��������Iterator����һ�����ģʽ���ڱ�����������ڷ���������Ԫ�أ�������Ҫ��¶���ϵ��ڲ����ַ�ʽ��
�������ṩ��һ��ͳһ�ķ�ʽ��������ͬ���͵ļ��ϣ�ʹ�ô���������Ϳɸ��á�
ʹ��* ���������Խ�ѹ��չ����������ɵ�������Iterable������������������ȡ������
```c
	vector<int>::iterator it;
	for(it=a.begin(); it != a.end();it++){}
		cout << *it;	//�����÷��������
	for (auto it = a.begin(); it != a.end(); it++){}
		cout << *it;	//�����÷��������
```

#### auto�﷨

##### auto�Ķ���
��auto��(�Զ�ʶ������)
��C++�У�auto �ؼ�����һ������˵�����������Զ��Ƶ����������͡�
����ζ�ű���������ݱ����ĳ�ʼ�����ʽ�Զ�ȷ�����������ͣ��Ӷ�ʹ�ô�����Ӽ�࣬
�ر��ǵ�����������ʱ��auto �ؼ�������C++11��׼������ģ�֮�󱻹㷺Ӧ�����ִ�C++����С�

##### auto���﷨
����1������Ϊauto������auto& ���ı��������ӵ���ʼ�����ʽ�Ķ���const��������const����ͨ����(int ��double��)����const���Գ���ָ�루����const����Ϊ��ָͨ�룬��ָ�������ײ�const���ĳ���ָ�루����cosnt����Ϊָ������ָ�루�ײ�const����
����2������Ϊauto& �ı��������ֳ�ʼ�����ʽ�Ķ���const��volatile ���ԡ�
����3����ϣ��auto�Ƶ����Ƕ���const������const����const auto��
[�ο�����](https ://blog.csdn.net/weixin_43744293/article/details/117440727)
```c
	for(auto x : a){}
		cout << x;
```
**[��ϲ�������]**
auto�´��һ�������ڵ�veckor,���޸�xʱ����ı�ԭ�������е�vectorֵ��ֻ��ı俽����vector��
xΪԪ�ؿ�ֱ��ʹ��
```c
	for (auto& x : vector){}
```
����Ҫ��ԭ���ݽ���ͬ���޸�ʱ������Ҫ���& ����vector�����á����ڸı�x��ͬʱ�޸�vector��
```c
for (const auto& x : vector)
```
**[������]**
const(������)��������Ϊ��ֵ& (����)�����������������¿ռ䣬
���ԭvector�޸ĵ����ǲ�ϣ������ԭvector(������Ҫ�����µĿռ�)��ͬʱ��Ը������ı�ԭvector��
��ô���ǿ���ʹ��for(constauto & x:vector)���������ǿ��Ժܷ�����ڲ�����������¶�ȡvector��ͬʱ�����޸�vector��һ������ֻ��������

##### auto�ڱ��ʱ��������;
1�������߳����ӵı�������
`vector<int>::iterator it = v.begin(); `ֱ����auto���� `auto it = v.begin();`
2������ģ�����ʱ��������������ģ������ı���
```
template <typename _Tx, typename _Ty>
void Multiply(_Tx x, _Ty y) {
	auto v = x + y;
	std::cout << v;
}
```

#### ʹ��reverse���������㷨
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

### stackջ
#### ջ�Ķ���
ջ��Stack����һ���������ݽṹ�����ص���ֻ������һ�˽��в����ɾ��������
��һ�˱���Ϊջ����top������Եأ�����һ�˳�Ϊջ�ף�bottom����
�������ݽṹ��ѭ����ȳ���LIFO, Last In First Out����ԭ��

#### ջ���﷨
| ���� | ˵��|
|-------- | -------- |
|stack<Type>s; | ����ջ��TypeΪ�������ͣ���int��foatchar��|
|s.push(item); | ��item�ŵ�ջ��|
|s.top(); | ����ջ����Ԫ�أ�������ɾ��|
|s.pop(); | ɾ��ջ����Ԫ�أ������᷵��|
|s.size(); | ����ջ��Ԫ�صĸ���|
|s.empty(); |���ջ�Ƿ�Ϊ�գ����Ϊ�շ���true.���򷵻�false|

#### ��ջ����
ջ��Ҫ�ÿռ�洢�����ջ������̫����ô�����ᳬ��ϵͳΪջ����Ŀռ䣬�ͻᱬջ����ջ�����
����취������ : 
(1)�ڳ����е���ϵͳ��ջ��������ϵͳ�ͱ�������
(2)�ֹ�дջ��

#### P1427 С���������Ϸ
**��Ŀ����**
С�������Ҫ��μ�һ��������Ϸ��Ҫ�����ѿ�����һ������ $a_i$�����Ȳ�һ������ $0$ ����������ס��Ȼ�������������ʾ���������� $0$ �Ͳ�Ҫ������ˣ������С����ǵ��������˵ʵ����̫���ˣ���Ҳ������С��������Դ��Ŷ������һ���ֻ��ǺóԵ��⣡���������С���̽��������⡣
**�����ʽ**
һ��������һ���������� $0$ �������Կո�����
**�����ʽ**
һ���ڵ��������һ���������Կո�����
**���� #1**
**�������� #1**
```
3 65 23 5 34 1 30 0
```
**������� #1**
```
30 1 34 5 23 65 3
```
**��ʾ**
**���ݹ�ģ��Լ��**
���� $100\ % $ �����ݣ���֤ $0 \leq a_i \leq 2 ^ {31} - 1$�����ָ��������� $100$��
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
