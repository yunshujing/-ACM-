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


//Day8
/*
## queue����
### queue�Ķ���
����`Queue`��һ�ֳ��������ݽṹ������Ҫ�ص���`�Ƚ��ȳ�`��FIFO��First In First Out����
�ڶ����У����ݵĲ����ɾ�������ֱ��ڱ�Ĳ�ͬ�˽��С�������˵��������������Ԫ�ص�һ�˳�Ϊ����β��`rear`�����Ӷ������Ƴ�Ԫ�ص�һ�˳�Ϊ����ͷ��`front`.
���к�ջ������:
ջֻ��֪�������ȥ��Ԫ��,���п���֪�����Ⱥ������ȥ��Ԫ��;ջ��`����ȳ�`,������`�Ƚ����`

### queue���﷨
| ���� | ˵��|
|-------- | -------- |
|q.front();|���ض���Ԫ��|
|q.back();|���ض�βԪ��|
|q.push();|�ڶ�β����Ԫ��|
|q.pop();|��������Ԫ��|
|q.empty;|�����Ƿ�Ϊ��|
|q.size();|���ض����е�Ԫ�ص�����|

����
[P1996 Լɪ������](https://www.luogu.com.cn/problem/P1996)
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
## ��/���ȶ���(priority_queue)

### �ѵĶ���
����һ����������ݽṹ��ͨ�����Ա�������һ����ȫ�������������������Ҫ���԰�����
**��ȫ������**�������һ���⣬ÿһ���ϵĽڵ������ﵽ���ֵ�������һ����ֻȱ���ұߵ����ɽڵ㡣
**ֵ������**�����ڴ󶥶ѣ�ÿ�����ڵ��ֵ�����ڻ�������ӽڵ��ֵ������С���ѣ�ÿ�����ڵ��ֵ��С�ڻ�������ӽڵ��ֵ��
**��Ч��**������ʵ�����ȶ��е�һ�ַǳ���Ч�ķ������ܹ������ҵ��������ֵ����Сֵ�Ľڵ㡣

### ���ȶ��еĶ���
���ȶ���`priority_queue`��һ������Ķ��У�����Ԫ�ر��������ȼ��������ʶ���Ԫ��ʱ������������ȼ���Ԫ������ɾ����
���ȶ�������ͨ�������Ĳ�ͬ������������Ԫ�ص����ȼ���������ʹ���
������˵��
**���ȼ�**��ÿ��Ԫ�ض���һ�����ȼ������ȼ��ߵ�Ԫ�ػ��������ȼ��͵�Ԫ�ر����ʻ�ɾ����
**����**��֧�ֲ���������ȼ�Ԫ�ء�ɾ��������ȼ�Ԫ�غͲ���ָ�����ȼ�����Ԫ�صȲ�����
**ʵ�ֻ���**�����ȶ���ͨ�����ڶ���ʵ�֣����������Ҳ�����ڶѵ����ʺ�ʵ�ַ�ʽ��

### ���ȶ��е��﷨
| ���� | ˵��|
|-------- | -------- |
|pq.push(int x);|�����ȶ����в���һ������|
|pq.pop();|ɾ�����������ȶ����е����Ԫ��|
|pq.top();|���ص����Ƴ����ȶ����е����Ԫ��|
|pq.empty();|������ȶ����Ƿ�Ϊ�ա�|

C++�е����ȶ����Ǳ�׼ģ��⣨STL����һ���֣�ͨ��ʹ��priority_queueģ������ʵ�֡�
```c
   #include <queue>
   using namespace std;

   int main() {
	   priority_queue<int> pq;
	   // ����Ԫ��
	   pq.push (5);
	   pq.push (3);
	   pq.push (7);
	   // ɾ��������ȼ���Ԫ��
	   pq.pop ();
	   // ��ȡ������ȼ���Ԫ��
	   cout << pq.top () << endl;
	   return 0;
   }
```
��C++�У�`priority_queue`Ĭ��Ϊ`����`�Ӵ�С��������Ԫ�ػ����ȱ��Ƴ���
����ͨ��������ģ�������ָ������ʽ�����磺
   `priority_queue<int, vector<int>, greater<int>> pq;`
�������Խ����ȶ��б�Ϊ`��С��`��
1.Ԫ�����ͣ�`int`��ʾ���ȶ����д洢��Ԫ�����͡�
2.�ײ�������`vector<int>`��ʾ���ڴ洢Ԫ�ص��������͡������ȶ����У�Ĭ��ʹ��`vector`��Ϊ�ײ�������
3.�ȽϺ�������`greater<int>`������һ���º���������ָ��Ԫ�ص�����ʽ������ʹ����`greater<int>`����˸����ȶ��лᰴ�մ�С�����˳������Ԫ�أ���С����.
Ĭ������£�`priority_queue`ʹ��`std::less`��Ϊ��ȽϺ���������ζ�����ᴴ��һ���󶥶ѡ�
����`priority_queue`�Ķ���Ԫ��`top()`��ʱ�临�Ӷ���`O(1)`��������`push()`��ɾ������Ԫ��`pop()`��ʱ�临�Ӷ���`O(log n)`������n�Ƕ�����Ԫ�ص�������
`priority_queue`����֤Ԫ�ص�˳�򣨳��˶���Ԫ�أ���Ҳ���ṩ������ʡ�
**�ṹ������**
```
struct Node {
	int a, b;
	// ����С�ڲ���������ʵ���Զ����������
	bool operator<(const Node& other) const {               //[��ס��ʽ]
		// ��������ϣ���Ȱ�a�����������a��ͬ����b��������
		if (a != other.a) return a < other.a;
		return b > other.b; // ע������ʹ��'>'��ʵ��b�Ľ���
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
����
[P1090 [NOIP2004 �����] �ϲ�����](https://www.luogu.com.cn/problem/P1090)
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

## ˫�˶���
### Deque�Ķ���
˫�˶��У�Double-Ended Queue�����Deque����һ�־��ж��к�ջ���ʵ����ݽṹ��
����Ҫ�ص������������˽��в����ɾ���������������ڶ��ף�ǰ�ˣ��Ͷ�β����ˣ�ͬʱ������Ӻͳ��Ӳ�����
˫�˶������޶������ɾ�������ڱ�����˽��е����Ա������˷ֱ��Ϊ�˵�1�Ͷ˵�2��
˫�˶��е�Ԫ�ؿ��Դ����˵��������������˶��к�ջ������.
### Deque���﷨
��C++�У���׼ģ��⣨STL���ṩ��`std::deque`��ʵ��˫�˶��еĹ��ܡ�
`std::deque`���Ա���Ϊһ���̶���С�����飬�������Զ�̬�������������Ҳ���Ҫ��ÿ�β����ɾ��ʱ���·�������������ڴ档��������ʹ��`std::deque`�ڲ����ɾ�������Ϸǳ���Ч��

��C++�У�ʹ��˫�˶�����Ҫ������Ӧ��ͷ�ļ���
	`#include <deque>`
����һ��˫�˶��ж���Ļ����﷨���£�
	`deque<element_type> deq;`
����element_type�������������͵����ݣ������������ַ����ȡ�

| ���� | ˵��|
|-------- | -------- |
|deq.push_back(x);|�ڶ���β������Ԫ��x|
|deq.push_front(x);|�ڶ���ͷ������Ԫ��x|
|deq.pop_back();|ɾ������β����Ԫ��|
|deq.pop_front();|ɾ������ͷ����Ԫ��|
|deq.at(size_type pos);|����λ��pos����Ԫ�أ����λ�ó�����Χ�������쳣|
|deq.find(const value_type& val);|����ָ��ֵval��λ�ã������ص�����ָ���λ�ã����δ�ҵ��򷵻�end()|

�����Ƕ����ʹ�� std::deque �Ļ����﷨��
```
#include <iostream>
#include <deque>

int main()
{
	// ����һ�� int ���͵�˫�˶���
	std::deque<int> myDeque;

	// �����ͷ������Ԫ��
	myDeque.push _back(10);
	myDeque.push _back(20);
	myDeque.push _back(30);

	// �����β������Ԫ��
	myDeque.push _back(40);
	myDeque.push _back(50);

	// ɾ������ͷ��Ԫ��
	myDeque.pop _back();

	// ɾ������β��Ԫ��
	myDeque.pop _back();

	// ���Ҳ���ӡ����Ԫ��
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
## Set����

### Set�Ķ���
��C++�У�`set`�Ǳ�׼ģ��⣨STL����һ���֣����ڴ洢��������Ψһ��һ��Ԫ�ء�����Ҫ�ص������
**���ݽṹ**��`set`ͨ��ʹ�ú����`red-black tree`ʵ�֣���ʹ�������ж���ʱ�临�Ӷ�`O(logn)`�Ĳ��ҡ������ɾ��������
**Ԫ������**�������е�ÿ��Ԫ�ض���Ψһ�ģ����Ұ���`����`���У���Ҳ����ͨ���Զ���ȽϺ�����ʵ������������ʽ����`����`����`greater<int>`��
**���ɱ���**��һ��Ԫ�ر����뵽`set`�У���ֵ���ܱ��޸ģ������Խ��в����ɾ��������
**������**��`set`�ṩ�˵����������ڱ��������е�Ԫ�ء�
**��ʲô��**��ȥ�ء�����
### Set���﷨
| ���� | ˵��|
|-------- | -------- |
|St.insert();|��set��û�еȼۺ���ʱ����x���뵽set��|
|St.erase();|��set��ɾ��ָ��Ԫ�أ�������Ҳ��Ӱ�죬���޲�����|
|St.clear();|���set����|
|st.count(x);|����set�ڵ�xԪ�ص���������Ϊ������һ��������ֵ 1 or 0|
|St.empty();|�ж�set�Ƿ�Ϊ��|
|St.size();|����set�ڵ�Ԫ�ظ��� |
|St.find();|�������ڲ���ָ��ֵ��λ��|

	������һ��������ʾ��������ʾ��ζ���Ͳ���һ��`set`��
```
#include <iostream>
#include <set>
using namespace std;
int main(){
	// ��������ʼ��set
	set<int> my_set = {1, 2, 3};//Ĭ������
	set<int,greater<int> > my_set2 = {1, 2, 3};//����

	// ������Ԫ��
	my_set.insert(4);

	// ����Ԫ��
	auto it = my_set.find(2);
	if (it != my_set.end())
	{
		cout << *it << endl; // ���2
	}

	// ɾ��Ԫ��
	my_set.erase(my_set.find(1));

	// �������ϲ��������Ԫ��
	for (const auto &val : my_set)
	{
		cout << val << " ";
	}
	return 0;
}
```

## Multiset���ؼ���
### Multiset�Ķ���
��C++�У�`multiset`��һ���ǳ����õ�STL����׼ģ��⣩�������ͣ����ڴ洢�Ͳ���������ͬ��ֵ�Ե�Ԫ�ؼ��ϡ�
��set��ͬ���ǣ�`multiset`�����ظ���Ԫ�ش��ڣ������ܹ�������ЩԪ�ص������ԡ�

`St.begin();`����set��һ��Ԫ�صĵ�ַ�ĵ�����
`St.end();`����set���һ��Ԫ�صĵ�ַ����һ����ַ�ĵ�����
`St.erase(T x/iterator it)`
`Lower_bound` ���ֲ��� `upper_bound()`
**Ԫ������**�������е�ÿ��Ԫ�ض���Ψһ�ģ����Ұ���`����`���У�
��Ҳ����ͨ���Զ���ȽϺ�����ʵ������������ʽ����`����`����`greater<int>`

## Map

### Map�Ķ���
��C++�У�`Map`��һ�ֹ������������洢��Ԫ���Ǽ�ֵ��`key-value pairs`��
ÿ��Ԫ�ض���һ����ֵ�ԣ����м���key����Ψһ�ģ���ֵ��value����������κ��������͡�
Map�ڲ�ͨ��ʵ��Ϊһ��������������Ƶ�ƽ�������������������ζ�� map �е�Ԫ�����ǰ��ռ����������С�
��ˣ�map �ṩ�˿��ٵĲ��ҡ������ɾ����������Щ������ʱ�临�Ӷ�ͨ��Ϊ����ʱ��`O(log n)`������ n �� map ��Ԫ�ص�������
Ҳ��������һ���ṹ������,ֻ��������±��ֵ��������ġ�

[ע������]
map �еļ�������Ψһ�ġ�
map �е�Ԫ�ذ��ռ����������С�
���ʲ����ڵļ�ʱ��ʹ���±�������ᴴ��һ����Ԫ�ء������ֻ��������Ƿ���ڣ�Ӧ��ʹ�� find ��Ա������
map �Ĳ��롢ɾ���Ͳ��Ҳ�����ʱ�临�Ӷ�ͨ��Ϊ O(log n)��

### Map���﷨
������`std::map`�����﷨���£�
	`map<KeyType, ValueType> mapName;`
`KeyType` �Ǽ�������,������֧�� < ���������Ա�map���Զ���Ԫ�ؽ�������
`ValueType` ������������ֵ�����͡�
`mapName` ���㶨���map�����ơ�

**���ú���**
| ���� | ˵��|
|-------- | -------- |
|Mp.insert(const value_type& val)��| ����һ����ֵ�ԡ�������Ѵ��ڣ��������ֵ|
|Mp.erase(key_type const& k);|ɾ����ָ�����������Ԫ�أ��ͷſռ�|
|Mp.find(key_type const& k);|���Ҿ���ָ������Ԫ�ء�����ҵ�������һ��ָ���Ԫ�صĵ����������򣬷���һ��ָ��mapĩβ�ĵ�����|
|Mp.size();|����map��Ԫ�ص�����|
|Mp.empty();|���mapΪ�գ��򷵻�true|
|Mp.operator[];|ʹ�ü���Ϊ��������Ԫ�ء�����������ڣ������һ�����иü�����Ԫ�أ�������ֵ��ʼ��ΪValueType()��Ĭ�Ϲ���ֵ|
|Mp.count();|ͳ������±���ֵĴ��� 1 or 0|
**ʹ�÷���**
	������ map��
	����һ���յ� map��������Ϊ int��ֵ����Ϊ std::string
	```
	map<int, string> myMap; 
	//  key  value
	```
	or ʹ�ó�ʼ���б�
	```
	map<int, string> myMap2 = {
		{1, "one"},
		{2, "two"},
		{3, "three"}
	};
	```

	������Ԫ�ء�
	1.ʹ���±������`[]`������������ڣ��������Ԫ�أ�����ʼ����ֵΪValueType��Ĭ��ֵ����
	```
	myMap[1] = "one";  
	```
	2.ʹ��`insert`��Ա������
	```
	auto result = myMap.insert(make_pair(2, "two")); 
	if (!result.second) {
		// ����ʧ�ܣ�ͨ������Ϊ���Ѵ���  
	}
	```

	������Ԫ�ء�
	```
	string value = myMap[1]; // ���ʼ�Ϊ 1 ��Ԫ�ص�ֵ  
	```
	ע�⣺����������ڣ���ʹ���±�������ᴴ��һ����Ԫ�أ���ֵ�ᱻ��ʼ��Ϊֵ���͵�Ĭ��ֵ  
	or
	����ȫ�ķ��ʷ�ʽ����֤������ȫ��
	```
	auto it = myMap.find(1);// ��֤������ȫ
	if (it != myMap.end()) {
		string value = it->second; // �����ҵ���Ԫ�ص�ֵ  
	}	// `myMap.first`Ϊ����`myMap.second`Ϊֵ
	```
	
	��ɾ��Ԫ�ء�
	```
	myMap.erase(1); // ɾ����Ϊ 1 ��Ԫ��  
	```
	or ʹ�õ�����
	```
	auto it = myMap.find(2);
	if (it != myMap.end()) {
		myMap.erase(it);
	}	// ��֤������ȫ
	```

	������ map��
	```
	for (const auto& pair : myMap) {
		cout << pair.first << ": " << pair.second << endl;
	}
	```
	or ʹ�õ�����  
	```
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}	// ��֤������ȫ
	```

### Map�Ŀ�
1.�ᱬջ
����������ڣ���ʹ���±�������ᴴ��һ����Ԫ�أ���ֵ�ᱻ��ʼ��Ϊֵ���͵�Ĭ��ֵ`0`��
2.����ѭ��
������Ҫ��`count()`ȥ�жϼ��Ƿ���ڣ���ȥ���ʼ��������һֱ�½���ֵ������ѭ����
```
if (mp.count()>0){code}
```
or `find()`

### unordered_map
`unordered_map`�ǻ���`��ϣ��`��`map`
��ʹ�÷����`map`û���κ�����
`map`:
**�ŵ�**:������,Ч��ʮ���ȶ�`Olog(n)`
`unordered_map`:
**�ŵ�**:�����ٶȷǳ��Ŀ����`O(1)`
**ȱ��**:����,���������Ч�ʲ���`map`
���˵����Ҫ��������`map`,����Ҫ���������`(for(autolx,c]:mp)`��ô����`map`
��������`unordered_map`��`codeforces`һ����TLE
��������`map`����ô���������`unordered_map`���и��ʻῨ`unordered_map`
�෴��Ȼ���е�������`unordered_map`�ܹ����п���`map`�ᱻ��

*/