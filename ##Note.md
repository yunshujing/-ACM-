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



//Day10
/*
// ����ģ��
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);//�ر�ͬ����

	coutĬ�ϱ���С�����4λ
	cout<<fixed<<setprecision(2)<<endl;//����С�����2λ
    return 0;
}
```
*/


//Day11
## ����
�������������main���������棺
ֻ���ڷ�����ʱ������ſ��Կ��úܴ�
����main������ʱ�������Դ�ͻ��쳣�˳���
### memset��ʹ��
`memset(�������ƣ���Ҫ��ʼ����ֵ�������ÿ��Ԫ�صĴ�С)`
**ע��**��memset��ʼ����ֵֻ����0��-1
```cpp
signed main() {
	// ��memset(�������ƣ���Ҫ��ʼ����ֵ�������ÿ��Ԫ�صĴ�С)��
	int a[10];             //��ע�⣺memset() ���ܵĳ�ʼ��ֵ����Ϊ 0 ���� -1
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
**ע������**
`memset`�������ֽڽ��в�������˲���ֱ�����ڽ��������飨��int���飩��ʼ��Ϊ��`0`�ͷ�`-1`֮�������ֵ��
�����Ҫ��ָ�������ָ����ڴ浥Ԫ���������ʼ����������ȷ�����ָ������Ѿ�ָ����һ����Ч�ĵ�ַ��
`memset`����ֻ�������ַ��������ͻ����޷��������������ͣ���ֻ������1�ֽڴ�С��ֵ��

**����**
��nյ�ƣ����Ϊ1~n����1���˰����еƴ򿪣���2���˰������б��Ϊ2�ı����Ŀ��أ���Щ�ƽ����ص�������3���˰������б��Ϊ3�ı����Ŀ��أ����йص��ĵƱ��򿪣����ŵƽ����رգ����������ơ�һ����k���ˣ����������Щ�ƿ��ţ�
����:n��k��������ŵĵƱ�š�k<=n<=1000
��������:7 3
�������:1 5 6 7
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
	memset(a, -1, sizeof(a));//-1��ʾ����

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

### ������������
1.����`scanf()`�ķ���ֵ ���ǣ�����������������ʽ��ƥ�����.��
����˵���ǣ��������ѳɹ���ֵ����������������ʱ�򷵻�EOF.
��ע��EOF(End Of File)��һ��Ԥ����ĳ���������-1.��
```cpp
while(scanf("%d%d",&a,&b)==2){}
while(scanf("%d%d",&a,&b)!=EOF) {}
while(scanf("%d%d",&a,&b)!=-1) {}
while(~scanf("%d%d",&a,&b)) {}
```
2.cinʵ�ֵĶ�������
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
3.����

[HDU-1021](https://vjudge.net/problem/HDU-1021#author=GPT_zh)

**�������**
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

## string �� �ַ���
### C�����ַ������ú���

> `strcpy`�������ַ���
>
> `strcat`��ƴ�������ַ���
>
> `strcmp`���ַ����Ƚ�

### string �� �﷨
#### ���ú���
| ���� | ˵��|
|-------- | -------- |
|length(); size(); |�󳤶�|
|empty();          |�ж��Ƿ�Ϊ�մ�|
|substr();         |��ȡ�ַ���|
|erase();          |ɾ�����ɸ��ַ�|
|insert();         |�����ַ�|
|replace();        |�滻�ַ�|
|find();           |Ѱ���ַ�|
|count();		   |�����ַ�����|
|stoi();		   |stringתint|
|to_string();	   |intתstring|

#### string������һЩ�����������ֱ��ʹ��
```cpp
str1=str2;    //str1��Ϊstr2�Ŀ���

str1+=str2; //str2���ַ��������ӵ�str1��β��

str1+str2;  //��str2���ӵ�str1��β����str1���ı�

str1==str2;  str1!=str2; str1<str2; 
str1>str2;  str1<=str2;  str1>=str2;
//�����ֵ���ıȽϣ����ز���ֵ��true��false
```

#### �ַ�����ȡ
`getchar()`����һ���ַ�
`cin`�ܶ����ո񣬶��������з�
`getline()`���Զ������з�
```cpp
#include<iostream>
using namespace std;
int main(){
	cout<<getchar();//����һ���ַ�

	string s;
    cin>>s;//`cin`�ܶ����ո񣬶��������з�
    cout<<s;

    string s;
    getline(cin,s);//`getline()`���Զ������з�
    cout<<s;
}
```

#### `substr();`��ȡ�ַ���
string.substr(��ʼλ��������)
```cpp
int main (){
	string s="hello, world!";
	string ss1 = s.substr(2);//llo, world!
	//��2��ʼ����ȡ��
	string ss2 = s.substr(2,3);//llo
	//��2��ʼ����ȡ3λ
	cout<<ss1<<endl<<ss2<<endl;
}
```

#### `erase()`ɾ�����ɸ��ַ�
`string.erase(��ʼλ��������)`�й��ɵ�ָ��ɾ��
```
s1.erase(1, 2)//��1��ʼɾ2��
cout << s1 << endl;
```
#### `insert()`�����ַ�
```cpp
string.insert(Ҫ�����λ�ã�Ҫ�����Ԫ��);
s1.insert(0, "1");
cout << s1 << endl;
```

#### `replace()`�滻�ַ�
string.replace(������Ҫ�滻�����ַ����滻��ȥ��Ԫ��)
```cpp
s1.replace(0, 1, "HaHa");
cout << s1 << endl;
```
#### `find()`Ѱ���ַ�
�� C++ �У�`string::npos`��һ������ĳ���ֵ�����ڱ�ʾ���ַ�����δ�ҵ����ַ������ַ�ʱ��λ�á�
�������ʵ������`std::string`�������ܱ�ʾ�����ֵ���� `std::string::size_type`�����ֵ��
�����ַ����������Ǵ�`0`��ʼ�ģ�����κ���Ч������ֵ��С�� `std::string::npos`��
```cpp
if (s1.find("666") == string::npos) {
	cout << "�Ҳ���" << endl;
}
else {
	cout << "�ҵ���" << endl;
}
```

#### `count()`�����ַ�����
`count(string.begin(),string.end(),'Ҫ�ҵ��ַ�')`
```cpp
string s = "Hello world";
cout << count(s.begin(), s.end(), 'l') << endl;
```

#### `string`��`int`�໥����
```cpp
#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	//string �� int �໥ת��
	string s="123";
	string s2="6";
	cout<<stoi(s)+stoi(s2);
	
	int a=123,b=345;
	string s=to_string(a)+to_string(b);
	cout<<s;
} 
```

Day12
#### `sort`��`reverse`����
`sort(begin(),end())`Ĭ�ϴ�С��������
`reverse`��ת����
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="ABCABCABC";
	cout<<count(s.begin(),s.end(),'A');
	sort(s.begin(),s.end());//����
	reverse(s.begin(),s.end());//��ת
	cout<<s<<endl;
}
```
����

[P1106 ɾ������](https://www.luogu.com.cn/problem/P1106)
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;int k;
	cin>>n>>k;
	while(k--){
		for(int i=0;i<n.size();i++){
			if(n[i]>n[i+1]){
				n.erase(i,1);//ɾ��ǰһ���Ⱥ�һ�������
				break;
			}
		}
	}
	int a=stoi(n);//ɾ��ǰ��0
	cout<<a;
	return 0;
}
```
[P2580 ����������ĵ�����ʼ��](https://www.luogu.com.cn/problem/P2580)
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
[P1628 �ϲ�����](https://www.luogu.com.cn/problem/P1628)
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
[P1104 ����](https://www.luogu.com.cn/problem/P1104)
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
    if (a.y != b.y) return a.y < b.y; // �ȱȽ����  
    if (a.m != b.m) return a.m < b.m; // �����ͬ��Ƚ��·�  
    if (a.d != b.d) return a.d < b.d; // ��ݺ��·ݶ���ͬ��Ƚ�����  
    return a.id > b.id; // ���ж���ͬ�����id����  
}  
```
[P8871 [���Ǳ� #5 ����] C-���ӵ��Ű����ѧ](https://www.luogu.com.cn/problem/P8871)



// Day13
## ̰���㷨
̰���㷨��Greedy Algorithm����Ҳ��̰���㷨����һ����ÿһ�������ж�ѡ��ǰ״̬�����ŵ�ѡ����ڴﵽȫ����ѽ�����Ż��㷨�������˼����ͨ��һϵ�оֲ�����ѡ����ʵ���������Ž⡣

**����������**
̰���㷨�Ļ����������£�
��ÿһ������ʱ�����ǲ�ȡ�ڵ�ǰ״̬�µ����ѡ�񣬴Ӷ�ϣ�����½������û����ŵġ�
̰���㷨������δ�����ܲ�����Ӱ�죬ֻ��ע��ǰ�ľֲ����Ž⡣
̰���㷨ͨ������Ѹ�٣���Ϊ���ǲ��漰���ӵĻ��ݻ��ε�����

**����**
**�ֲ�����ѡ��**����ÿ��ֻѡ��ǰ�������ŵľ��ߣ������ǳ�Զ�����
**������**��һ������ѡ�񣬲�����ݻ�����������Щ���ߡ�
**��ֱ��**�������㷨�߼��򵥣����ڱ���Ϳ���ʵ�֡�
**��Ч��**������Ѹ�٣���Ϊ����Ҫ���ӵĻ��ݻ��ε�����

**ԭ����ʹ�÷���**
̰���㷨�Ļ���ԭ���Ǵ������ĳ����ʼ��������𲽵ؽ���ѡ��ֱ���ﵽ�������Ĺ��̡�ÿһ��ѡ���ǻ��ڵ�ǰ�ľֲ����ţ����Ҳ��ܻ��ˡ�����ۻ�������Щ�ֲ����ŵ�ѡ����������ȫ�����Ž⡣

ʹ��̰���㷨��Ҫ������������������
�������̰��ѡ�����ʣ���ʹ�õ�ǰ���Ž��ܹ��õ�ȫ�����Ž⣻
�������������������ӽṹ���ʣ���ԭ��������Ž����ͨ��������������Ž���϶��õ���

**��Ʋ���**
���̰���㷨һ��������¼������裺
ȷ������������ӽṹ��
��������������ӽṹ���һ���ݹ��㷨��
֤������������̰��ѡ��ֻʣ��һ�������⣻
֤��̰��ѡ�����ǰ�ȫ�ģ�
���һ���ݹ��㷨ʵ��̰�Ĳ��ԣ�
��̰���㷨ת��Ϊ�����㷨��

**̰���㷨��Ӧ��ʾ��**��
**��С������**���ڼ�Ȩ����ͼ�У�Prim�㷨��Kruskal�㷨���ǻ���̰�Ĳ��Ե��㷨�����������С��������
**�ѡ������**������һϵ�л��ÿ�������һ����ʼʱ���һ������ʱ�䣬����԰��ŵ��������ʹ��û���������ʱ���ص�������������ͨ��̰���㷨��⡣
**�������⣨���������**����Ȼ��������ͨ��ʹ�ö�̬�滮��⣬����ĳЩ�ض������£���0-1���������̰�İ汾�����������������⡱����̰���㷨Ҳ���Եõ����Ž⡣
**����������**��������ѹ���У�������������һ��ʹ��̰���㷨������������������ѹ���Ĺ㷺ʹ�õĿɱ䳤���뷽ʽ��
**����**��������Ǯ�����У�������������ֵΪ1Ԫ��5Ԫ��10Ԫ��50Ԫ��100Ԫ��500Ԫ�Ļ��ң�����Ҫ����786Ԫ��̰���㷨��������ʼ�𲽼��٣�ֱ���ҵ����Ž⡣

**̰���㷨����ȱ��**��
**�ŵ�**��
�㷨�򵥣�����ʵ�֡�
��ĳЩ�����У��ܹ��������Ž��������Ž⡣
ʱ�临�Ӷȵͣ�Ч�ʸߡ�
**ȱ��**��
���������������⣬�ر�����Щ��Ҫȫ�����Ž�����⡣
̰�Ĳ��Ե�ѡ��Խ���кܴ�Ӱ�죬���̰�Ĳ���ѡ�񲻵������ܵ����޷��õ����Ž⡣

[P1478 ����ժƻ���������棩](https://www.luogu.com.cn/problem/P1478)
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

	
	int n,s;//ƻ����������
	cin>>n>>s;

	int a,b;//���Ӹ߶ȣ��ֱ۳�
	cin>>a>>b;

	for(int i=1;i<=n;i++){
		cin>>ap[i].high>>ap[i].power;
	}

	sort(ap+1,ap+n+1,cmp);//��ƻ������������С��������

	//ժƻ��
	int ans=0;
	for(int i=1;i<=n;i++){
		//�жϸ߶��Ƿ��㹻
		if(ap[i].high>a+b){//�����߶�
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

[P2240 �����12.��1�����ֱ�������](https://www.luogu.com.cn/problem/P2240)
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
[P1803 ���ҵ�yyy / �߶θ���](https://www.luogu.com.cn/problem/P1803)
[P1106 ɾ������](https://www.luogu.com.cn/problem/P1106)


//Day15
## ˫ָ��
˫ָ�루Two Pointers����һ���ڱ�����������У�ʹ������ָ����з����Դﵽ�ض�Ŀ�ĵ��㷨˼�롣��������ָ����ƶ���������λ�ã����Է�Ϊ���¼������ͣ�

**����ָ��**������ָ���ͬһ�࿪ʼ�������������һ��ָ���ƶ��ٶȿ죨��ָ�룩����һ���ƶ��ٶ�������ָ�룩������ģʽ�����ڽ����Ҫ�ж�ĳ�������Ƿ���������⣬��Ѱ�����������е�ĳ��ֵ���ж��Ƿ����ĳ��Ԫ�صȡ�

**��ײָ��**������ָ��ֱ����������˿�ʼ���м��ƶ���ͨ��һ��ָ����ǰ�ƶ�����һ������ƶ�������ģʽ��������Ҫ�ҵ�һ���ض������µ�Ԫ�ضԣ���������֮�����⡣

**��������**��������ָ��ָ��ͬһ�����ұ���������ͬ�Ҳ��ཻʱ����Ϊ�������ڡ�����ģʽ�����������������⣬��Ѱ������Ӵ�����ĳ������


### ����
**������**
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
**��ָ���͵�������**
����n����������������a���ҳ����е������������ǵĺ͵���m��
**��������**��
```
9 28
21 4 5 6 13 65 32 9 23
```
**���**
```
5 23
```
**�������**
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
**�ƶ�0**
����һ������nums����дһ������������0�ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
**����**��nums = [0,1,0,3,12]
**���**��[1,3,12,0,0]
**�������**
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
**Ѱ�������**
����һ������Ϊn������a��һ����s�������������Ѱ��һ�����䣬ʹ����������Ԫ��֮�͵���s���������������յ�
**��������**��
```
15 6
6 1 2 3 4 6 4 2 8 9 10 11 12 13 14
```
**�������**
```
0 0
1 3
5 5
6 7
```
**�������**
��
**A-B ����**
[A-B ����](https://www.luogu.com.cn/problem/P1102)
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

    // i ������ö��b
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
### ǰ׺�͵ĸ�����÷�

**����**��

ǰ׺����ָһ�������ĳ�±�֮ǰ����������Ԫ�صĺͣ���`���е�ǰn�����`�������㷨�У�ǰ׺����һ����Ҫ��Ԥ�����ֶΣ��ܹ������㷨��ʱ�临�Ӷȣ����ٵ����ĳһ�εĺͣ����ڴ�������֮�����������ʮ�ָ�Ч��

**�÷�**��

1. **Ԥ����ǰ׺������**�����ȣ���ԭʼ�������һ�α������ۼӼ����ǰ׺�������ÿһ��Ԫ�ء�����ʵ��ʱ�����Դ���һ����ԭʼ������ͬ���ȵ�ǰ׺�����飬���е�`i`��Ԫ�ش���ԭʼ������±�`0`���±�`i-1`��Ԫ��֮�ͣ����ߴ��±�`1`���±�`i`��Ԫ��֮�ͣ�����ȡ����ʵ�ַ�ʽ����
2. **��ѯ�����**����Ԥ����õ�ǰ׺������󣬿���ͨ����������λ�õ�ǰ׺��֮�������ٵõ���������ĺ͡����磬��������`[a, b]`����͵���ǰ׺�������е�`b+1`��Ԫ�أ�����±��`0`��ʼ����ȥ��a��Ԫ�أ����`a`��Ϊ`0`����

**����**��
1.��Ч��������ͣ�ǰ׺�Ϳ����������ټ���������ĳ������ĺ͡����磬Ҫ��������`l,r`֮��ĺͣ�ֻ����`s[r]`��ȥ`s[l-1]`���ɡ�
2.��άǰ׺�ͣ��ڴ����ά����ʱ������������Ӿ�������⣬ǰ׺��ͬ�����á�ͨ��Ԥ�����άǰ׺�ͣ����Դ�󽵵Ͳ�ѯ��ʱ�临�Ӷȡ�

### ��ֵĸ�����÷�

**����**��

��֣�������ֺ����������㣬����ѧ�е�һ�ָ����ֵĽ����ӳ����ɢ��֮���һ�ֱ仯�����о���ɢ��ѧ��һ�ֹ��ߡ����������Կ�����`ǰ׺�͵�������`������ԭ����ӳ�䵽���ֱ�ʾ�ϡ������������ѧ���������Ϣѧ�������й㷺Ӧ�á�

**�÷�**��

1. **�����������**������һά���飬�������d��ÿ��Ԫ��`d[i]`��ʾԭ����a�е�i��Ԫ�����i-1��Ԫ�صĲ��`d[i] = a[i] - a[i-1]`��ע��`d[0]`ͨ��û�ж������Ϊ`0`����ͨ��������飬���Է����ʵ�ֶ�ԭ����ĳ������������Ӽ�������
2. **�����޸�**������Ҫ��ԭ�����ĳ������[l, r]�ڵ�����Ԫ�ض�����һ��ֵcʱ������ͨ���޸Ĳ��������ʵ�֡��������Ϊ��`d[l] += c`����ʾ��lλ�ÿ�ʼ����c����`d[r+1] -= c`����ʾ��r+1λ�ý������ӣ���ֹ�Ժ����������Ӱ�죩��֮��ͨ���Բ���������ǰ׺�����㣬���ɵõ��޸ĺ��ԭ���顣
3. **����ʱ�临�Ӷ�**��ͨ����֣����Խ������޸Ĳ�����ʱ�临�Ӷȴ�`O(n)`���͵�`O(1)`�����ڲ��������޸Ĳ�������`O(n)`������ͨ��ǰ׺�ͻ�ԭԭ����Ĳ��������Ӷ��ڴ�����������޸ĺͲ�ѯ����ʱ���Ч�ʡ�

**����**��
1.�����޸�����ֵ����ַ���Ҫ���ڶ������ĳһ������ÿ��������һ�����������磬���Ҫ������`l,r`������Ԫ������һ������`d`,��ֻ�轫�������`c`�е�`c[i]`����`d`,����`c[r+1]`��ȥ`d`��
2.�������������Ҫ��ԭ�������ĳЩ�ض����޸�ʱ������ĳ�����������ӻ����ĳ��ֵ)������ͨ�����������ʵ�֡����ȶԲ�����������Ӧ���޸ģ�Ȼ��ͨ��ǰ׺�ͻָ�ԭ���顣

����������ǰ׺���������㷨�г��õ����ּ��ɣ����Ƿֱ�ͨ��Ԥ�����������ķ�ʽ���������㷨��ʱ�临�Ӷȣ�����˴������������Ч�ʡ�



Day17
��ϰ
1.̰��


**һάǰ׺��**��
���壺s[i]ǰi��ĺ�
���죺s[i] = s[i-1] + a[i]
ʹ�ã�������������
���3-5֮�������ͣ�s[5] - s[2] = (1+2+3+4+5) - (1+2)

**һά���**�����˼�룩
���壺b[i]ǰix��ĺ͵���ԭ����a[i]
���죺b[i] = a[i] - a[i-1]
ʹ�ã����������޸�
��3-5֮�䶼+1��b[3]++,b[6]--
��͵�ʱ��ͬʱ����ǰ׺�����㼴��

**��άǰ׺��**
���壺s[i][j]��i�У���j�е��Ӿ���ĺ�
���죺s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1]
ʹ�ã�������������������Ӿ���2��2����5��5��
sum = s[5][5] - s[1][5] - s[5][1] + s[2][2]

**��ά���**
������⼯����̺


//Day18
## ��������&&ʵ������
### ԭ�����
�������Ͷ��ַ�
**������**
������`[a, b]`�ֳ�n�ȷݣ�ÿ�������䳤����`x`�������`xk = a + k*x`(k=0,1,2,3,4,��,n)�ĺ���ֵ`f(xk)`��
��`f(xk) = 0`������һ��ʵ������������������`f(xk) * f(xk+1) < 0`������`(xk, xk+1)`��������һ��ʵ��������ȡ`(xk+ xk+1)/2`Ϊ���Ƹ�������

**���ַ�**
���ȷ��`f(x)`������`[a, b]`����������`f(a) * f(b) < 0`����������һ��ʵ����
���ַ��Ĳ��������ǰ�`[a, b]`��ηְ룬���ÿ�ηְ���������˵㺯��ֵ���ŵı仯��ȷ���и������䡣

**�ö��ֵ���������**��
���½�`[a, b]`ȷ��
������`[a, b]`�ڵ�����

**���ַ����Ӷ�**
n�ζ��ֺ�������С��`(b - a)/2n`��
����a��b�;���Ҫ��ţ�����������ִ���`n`��������`(b - a)/2n < ��`��
���ַ��ĸ��Ӷ���`O(logn)`�ġ�
���磬�������������`[0, 100000]`�ڵ����仯��Ҫ����ľ�����`10-8`����ô���ִ�����`44`�Ρ�

### ��������



����
```cpp
#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(random_device{}()); 

int main()
{
   int ans=rnd()%10+1;
   cout<<"������������1-10֮�䣬ÿ�β�һ������"<<endl;
    
   int x,sum=0;
   while(cin>>x){
       if(x<ans)
         cout<<"С��"<<endl;
       else if(x>ans)
         cout<<"����"<<endl;
       else if(x==ans)
         cout<<"��ȷ!����������"<<sum<<"�ξͲ�����"<<endl;
       sum++;
   }
}
```


### ��������ģ��
����ģ��һ�����������ֱ������ڲ�ͬ�����
**�㷨˼·**������Ŀ��ֵ�ڱ�����`[l, r]`�У� ÿ�ν����䳤����Сһ�룬��`l = r`ʱ�����Ǿ��ҵ���Ŀ��ֵ��
**�汾1**��
�����ǽ�����`[l, r]`���ֳ�`[l, mid]`��`[mid + 1, r]`ʱ������²�����`l = mid + 1`����`r = mid`;������`mid`ʱ����Ҫ��1��
C++ ����ģ�壺
```cpp
int bsearch_1(int l, int r)
{
 	while (l < r)
 	{
		int mid = l + r >> 1; //��ͬ��mid=(l+r)/2
		if (check(mid)) r = mid;
		else l = mid + 1; //+1Ϊ������ѭ��
	}
	return l;
}
```
**�汾2**��
�����ǽ�����`[l, r]`���ֳ�`[l, mid - 1]`��`[mid, r]`ʱ������²�����`l = mid`����`r = mid - 1`;����ʱΪ�˷�ֹ��ѭ��������`mid`ʱ��Ҫ��1��
C++ ����ģ�壺
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
## ������
�����ƣ�Binary����һ�ֻ���Ϊ2������ϵͳ����ֻʹ��������������ʾ������0��1���������Ǽ�����ڲ��洢�ʹ������ݵĻ�������Ϊ������е�������Ϣ���ն����Զ����Ƶ���ʽ���ںʹ���ġ�

### �����Ƶ��ص�

1. **����Ϊ2**����������ϵͳ�У�ÿһλ��Ȩֵ��2���ݴη������磬�ڶ�������`1010`�У����ҵ����ÿһλ�ֱ����$2^0$��$2^1$��$2^2$��$2^3$��

2. **������������**����������ֻ����0��1�������룬��ʹ�ö��������ڵ��ӵ�·�����ڱ�ʾ�ʹ�����Ϊ��·�Ŀ��͹�״̬������Ȼ��ӳ�䵽�����������ϡ�

3. **ת������**������������ʮ������֮����Է���ؽ���ת������������ת����λ���϶�ʱ���ܱ�÷��������⣬�������������Է����ת��Ϊ�˽�������ʮ������������Щ�����ڼ������ѧ��Ҳ����ʹ�á�

### ���������ı�ʾ

��������������һϵ�е�0��1����ʾ������`1011`��`0010`�ȡ�����дʱ��ͨ������ʡ��ǰ����0��������ĳЩ�������п��ܻ�������������Ϊǰ��0��Ӱ������ֵ���ڶ������У�`0010`��`10`��Ȼ��������ͬ����ʵ���ϱ�ʾ����ͬһ��������

### ��������������

������������������ӷ����������˷��ͳ����ȣ���Щ���㶼��ѭ��ʮ���������ƵĹ��򣬵���Ҫע����ǣ����ڶ�������ֻ��0��1�������룬�������������п��ܻ������λ���λ��

### �������ڼ�����е�Ӧ��

�������ڼ������ѧ������������Ҫ�����á�������е�������Ϣ�������������ݡ�ָ��ȣ������Զ����Ƶ���ʽ�洢�ڼ�������ڴ�ʹ洢�豸�еġ����⣬������ڲ����߼���·Ҳ�ǻ��ڶ�������������ƺ͹����ġ���ˣ��˽���������ı�ʾ���������������������Ĺ���ԭ��������Ҫ��

### ʾ��

����������һ����������`1010`�����ǿ��Խ���ת��Ϊʮ���������£�

$$ 1010_{(2)} = 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 0 \times 2^0 = 8 + 0 + 2 + 0 = 10_{(10)} $$

ͬ���أ�����Ҳ���Խ�ʮ������ת��Ϊ�������������磬��ʮ������`10`ת��Ϊ�������������ǵõ�`1010`��ע�������ת�����ܲ���Ψһ�ģ���Ϊǰ��0����ʡ�ԣ������������Ǳ��������Ա��������ʾ������һ�£���


## λ����
λ���㣨Bitwise Operations����ֱ���������Ķ�����λ�Ͻ��еĲ�������Щ���������루AND������OR�������XOR�����ǣ�NOT�������ƣ�Left Shift�������ƣ�Right Shift���ȡ�λ�����ڴ���������ݡ�ͼ�δ������ܽ��ܵ������зǳ����ã���Ϊ����ͨ��������Ӳ��������ֱ��ִ�У����ִ���ٶȷǳ��졣

�����Ǽ��ֻ�����λ�����������˵����

1. **�루AND��**��������λ���бȽϣ��������λ��Ϊ1������λΪ1�����򣬽��λΪ0��
   
   ���ţ�`&`
   
   ʾ����`5 & 3`
   - 5�Ķ�����Ϊ`101`
   - 3�Ķ�����Ϊ`011`
   - ����Ķ�����Ϊ`001`����ʮ���Ƶ�1��

2. **��OR��**��������λ���бȽϣ��������λ��������һ��Ϊ1������λΪ1�����򣬽��λΪ0��
   
   ���ţ�`|`
   
   ʾ����`5 | 3`
   - 5�Ķ�����Ϊ`101`
   - 3�Ķ�����Ϊ`011`
   - ����Ķ�����Ϊ`111`����ʮ���Ƶ�7��

3. **���XOR��**��������λ���бȽϣ��������λ����ͬ������λΪ1���������λ��ͬ������λΪ0��
   
   ���ţ�`^`
   
   ʾ����`5 ^ 3`
   - 5�Ķ�����Ϊ`101`
   - 3�Ķ�����Ϊ`011`
   - ����Ķ�����Ϊ`110`����ʮ���Ƶ�6��

4. **�ǣ�NOT��**����һ��һԪ����������������λ�ϵ�0���1��1���0��
   
   ���ţ�`~`
   
   ʾ����`~5`��������32λ�����У�
   - 5�Ķ����ƣ���32λ�����б�ʾ��Ϊ`0000 0000 0000 0000 0000 0000 0000 0101`
   - ����Ķ�����Ϊ`1111 1111 1111 1111 1111 1111 1111 1010`����ʮ���Ƶ�-6��ע�⣬�����漰�������Ʋ���ĸ����

5. **���ƣ�Left Shift��**����һ�����ĸ�������λȫ����������λ��������Ե������λ���������������Ҳ��Ե������λ����0��䡣
   
   ���ţ�`<<`
   
   ʾ����`5 << 2`
   - 5�Ķ�����Ϊ`101`
   - ����2λ�󣬽��Ϊ`10100`����ʮ���Ƶ�20����`5*2*2`��

6. **���ƣ�Right Shift��**����һ�����ĸ�������λȫ����������λ�����Ҳ��Ե������λ���������������޷�����������Ե������λ����0��䣻�����з���������ȡ����ϵͳ����������0��䣬Ҳ�������÷���λ��䣬���������ƣ���
   
   ���ţ�`>>`
   
   ʾ����`5 >> 2`������Ϊ�з���������
   - 5�Ķ�����Ϊ`101`
   - ����2λ�󣬽��Ϊ`001`���������ƣ����ַ���λ������ʮ���Ƶ�1����`5/2/2`��

### λ��������ȼ����Ӹߵ��ͣ�

1. **��λȡ����NOT��**��`~`����������λ����������ȼ���ߵģ����ǵ�Ŀ������������ڵ�����������

2. **���������**����ӣ�+��������-�����ˣ�*��������/���ȡ���Ȼ��Щ����λ������������ǵ����ȼ�ͨ�����ڴ󲿷�λ����������˰�λȡ������

3. **λ�������**�����ƣ�`<<`�������ƣ�`>>`��������������������ȼ����ڹ�ϵ������Ͱ�λ�롢��λ�򡢰�λ����λ������������������������

4. **��λ�루AND��**��`&`�������ڶ��������Ķ����Ʊ�ʾ������λ�������

5. **��λ���XOR��**��`^`�������ڶ��������Ķ����Ʊ�ʾ������λ��������

6. **��λ��OR��**��`|`�������ڶ��������Ķ����Ʊ�ʾ������λ�������

7. **��ϵ�����**������ڣ�>����С�ڣ�<�������ڣ�==���ȡ���Щ����������ȼ�����λ��������Ͱ�λ�������

### ע������

* ������Ľ�Ϸ��򣺳��˰�λȡ�������`~`�Ľ�Ϸ��������������⣬����λ������Ľ�Ϸ������������ҡ�
* ���ȼ�����ͨ������`()`���ı䡣�ڸ��ӵı��ʽ�У�����ʹ����������ȷָ�������˳��

### ʾ��

��������C���Ա��ʽ��

```cpp
int a = 5, b = 3;
int result = ~a & b | b ^ a;
```

�������ȼ�����������ʽ����������˳����м��㣺

1. ���ȼ���`~a`����Ϊ��λȡ������������ȼ���ߡ�
2. Ȼ�����`b ^ a`����Ϊ��λ�������������ȼ����ڰ�λ��Ͱ�λ��
3. ���ż���`~a & b`����λ������������ȼ����ڰ�λ��
4. ������`(~a & b) | (b ^ a)`����Ϊ��λ������������ȼ���͡�

### λ�����ʹ��->��ż���ж�
�κ������Ķ����Ʊ�ʾ�У����λ�������ұߵ�λ�������1��������������������0���������ż����
```cpp
if(n & 1){	//�ж���ż��
	cout << "YES" << endl;
}
else{
	cout << "NO" << endl;
}
```
```cpp
if(n>>3 & 1){	//�ж�n�ĵ���λ����ż��
	cout << "YES" << endl;
}
else{
	cout << "NO" << endl;
}
```

## ������
�����ݣ�Fast Exponentiation���㷨��һ�����ڸ�Ч�������� $a^b \mod m$ �ı��ʽ�ķ��������� $a$��$b$ �� $m$ ���������� $b$ ���ܷǳ��󡣸��㷨ͨ�����ٳ˷������Ĵ��������Ч�ʣ������˼��������ָ���Ķ����Ʊ�ʾ��

�����ǿ������㷨����ϸ�����C++ʵ�֣�

### �㷨����

1. **��ʼ�����**������� `result` ��ʼ��Ϊ 1����Ϊ�κ����� 0 �η����� 1����

2. **�������**�������� `a` ��ģ�� `m` ȡģ���Է�ֹ `a` �ں��������б�ù���

3. **ѭ������ָ��**����ָ�� `b` ���ж����Ʒֽ⣬�����λ�����λ��λ����
   - �����ǰλ�� 1���� `b` Ϊ������ǰ�������һλ�� 1�����򽫵�ǰ�� `a`�������ݴΣ��˵� `result` �ϣ����� `m` ȡģ��
   - �� `a` ƽ���������� $a \times a$�������� `m` ȡģ��Ϊ������һλ��׼����
   - ��ָ�� `b` ����һλ���� `b = b >> 1`�����൱�� `b` ���� 2 ȡ����

4. **���ؽ��**����ָ�� `b` ��Ϊ 0 ʱ��ѭ������������ `result`��

### C++ ʵ��
```cpp
#include<bies/stdc++.h>
using namespace std;

// �����ݺ��������� a^b % m
int fastPower(int a, int b, int mod/* ȡģ */) {
    int result = 1; // ��ʼ�����Ϊ1
    a = a % mod; // ��a��mȡģ
    while (b > 0) {
        // ���b�ĵ�ǰλ��1���򽫵�ǰ��a�˵�result��
        if (b & 1) { // �ȼ��� if (b % 2 == 1)
            result *= a;
			result %= mod;
        }
        // ��aƽ����׼��������һλ
        a *= a;
		a %= mod;
        // b����һλ
        b >>= 1; // �ȼ��� b = b / 2;
    }
    return result;
}

signed main() {
    int a, b, m;
    cout << "������a, b, m�����ڼ���a^b % m��:" << endl;
    cin >> a >> b >> m;
    cout << "�����: " << fastPower(a, b, m) << endl;
    return 0;
}
```
�����ʵ���У�����ʹ����λ���� `&` ����� `b` �ĵ�ǰ���λ�Ƿ�Ϊ 1���� `b % 2 == 1` ��λ����ȼ���ʽ������ʹ������������� `>>` ���� `b` ����һλ���� `b /= 2` ��λ����ȼ���ʽ������Щλ����ͨ������Ӧ������������죬����ڴ������ʱ����Ч�ʡ�



Day22
## ȫ����
`next_permutation`��C++��׼ģ��⣨STL���е�һ���������������������и������е�Ԫ�أ������ɸ����е���һ���ֵ������С�
��������Ѿ����ֵ����������У���ú�����������������Ϊ�ֵ�����С�����У�������`false`��ʾû����һ�����У����򣬷���`true`��ʾ�ɹ���������һ�����С�

### �����÷�

`next_permutation`�����Ļ����÷����£�

```cpp
#include <algorithm> // ����next_permutation

// ��������
bool next_permutation(It first, It last);
bool next_permutation(It first, It last, Compare comp); // ʹ���Զ���ȽϺ���

// ������������vector, string�ȣ�
bool next_permutation(Container& c);
bool next_permutation(Container& c, Compare comp); // ʹ���Զ���ȽϺ���
```

���У�`It`�ǵ��������ͣ�`Container`���������ͣ���`std::vector`��`std::string`�ȣ���`Compare`��һ����ѡ�ıȽϺ������͡�

### ʹ��ʾ��

#### ʾ��1������

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

�������`1 2 3`���������С�
```cpp
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
```

#### ʾ��2��vector

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

���ͬ����`1 2 3`���������С�

### Ӧ�ó���

`next_permutation`�ڶ��ֳ����ж��ǳ����ã������������ڣ�

* **�������**����������ĳ�����ϵ��������С�
* **�ֵ�������**�����԰����ֵ���Լ��Ͻ�������
* **�㷨�Ż�**���������㷨�У�������������״̬�ռ䣬�Ӷ��Ż��㷨���ܡ�
* **�㷨����**���ڱ�̾����У������ڽ����������ص����⡣
* **��ѧ����**�������������Ѱ��ȫ�����������ض����������е���ѧ���⡣

��֮��`next_permutation`��C++�д������������һ��ǿ�󹤾ߣ��ܹ�������߱���Ч�ʺʹ���Ŀɶ��ԡ�

## �����㷨
�����㷨��Divide and Conquer Algorithm����һ�ַǳ���Ҫ���㷨��Ʋ��ԣ�����һ�����ӵĴ�����ֽ�����ɸ���ģ��С�������⣬�ݹ�ؽ����Щ�����⣬����������Ľ�ϲ��������Ӷ��õ�ԭ����Ľ⡣���ֲ����ڴ�����ģ����ʱ�ر���Ч����Ϊ���ܹ����еش����������⣬�Ӷ�����㷨��Ч�ʡ�

### �����㷨�Ļ�������

�����㷨ͨ������������Ҫ���裺

1. **Divide���֣�**����ԭ����ֽ�Ϊ���ɸ���ģ��С���໥��������ԭ������ʽ��ͬ�������⡣
2. **Conquer���Σ�**���ݹ�ؽ����Щ�����⡣���������Ĺ�ģ�㹻С����ֱ�ӽ����
3. **Merge���ϲ���**����������Ľ�ϲ���ԭ����Ľ⡣

### �����㷨���ص�

1. **�ݹ���**�������㷨ͨ��ͨ���ݹ�ķ�ʽʵ�֣���������ֽ�ΪС���⣬�ٽ��С���⡣
2. **������**�������㷨���Բ��еش����������⣬��������CPU���̨�����ͬʱ�������ǣ��Ӷ�����㷨��Ч�ʡ�
3. **������**��������֮��ͨ�����໥�����ģ�û���ص����������������ڲ��д���

### �����㷨��Ӧ��

�����㷨�ڼ������ѧ���㷨��������Ź㷺��Ӧ�ã����Խ�����ʵ�����⡣������һЩ���͵�Ӧ�ã�

1. **�����㷨**��
   - **�鲢����**���ݹ�ؽ�ԭ���黮��Ϊ���������飬�ֱ��������Ȼ��ϲ���������������顣
   - **��������**��ѡ��һ����׼ֵ���������Ϊ���������飬�ֱ�С�ںʹ��ڻ�׼ֵ��Ȼ��ݹ�ض��������������������

2. **�����㷨**��
   - **��������**�������������У�����������ֳ����������䣬Ȼ��ݹ��������һ���������н���������ֱ���ҵ�Ŀ��Ԫ�ػ���������Ϊ�ա�

3. **����������������**��������ֳ����������飬�ֱ�����������������������飬Ȼ���ٿ��ǿ�Խ�е����������飬�����������������ֵ��Ϊ�����������������顣

4. **����˷�**������������ֳ��ĸ��Ӿ���Ȼ��ݹ�ؽ��о���˷�������ĸ��Ӿ���Ľ���ϲ���һ������


### �����㷨���ŵ�

1. **�������⸴�Ӷ�**��ͨ����������ֽ�ɶ��С���⣬ÿ��С���ⶼ�����׽�����Ӷ�������������㷨���Ӷȡ���ͨ����ͨ���ݹ�ʵ�ֵģ�ÿһ�����������ģ���루��������������ʹ����������ڴ���

2. **���л�Ǳ��**�����ڷ��β��Խ�����ֽ�Ϊ��������������⣬��Щ��������Բ��д����ڶ�˴�������ֲ�ʽ���㻷���У����ֲ����Կ�����������㷨��ִ��Ч�ʡ�

3. **�ṹ����**�������㷨�Ľṹͨ���ǳ���������ѭ���ֶ���֮����ԭ��ʹ���㷨����ƺ�ʵ�ֶ�����ֱ�ۺ�������⡣

4. **�����Թ�**�����β���������������͵����⣬��������������ͼ�ۡ��ַ�������ȶ������

### �����㷨��ȱ��

1. **�ݹ����**������ĳЩ���⣬�����㷨���ܻ��������ĵݹ����ջ������ܻ����Ĵ������ڴ���Դ����������ջ���������ĳЩ����£�������Ҫͨ�������������Ż�����������������⡣

2. **���⿪��**���ڷֽ�����ͺϲ���Ĺ����У����ܻ����һЩ����Ŀ��������磬�ڹ鲢�����У���Ҫ����Ŀռ����洢��ʱ���飬�Ա��ںϲ������н���Ԫ�رȽϺ��ƶ�����Щ���⿪�����ܻή���㷨������Ч�ʡ�

3. **������������**����Ȼ���β���ͨ���������������໥�����ģ�����ĳЩ����£�������֮����ܴ���������ϵ�����������Щ������ϵ�����ܻᵼ�´���Ľ⡣��ˣ�����Ʒ����㷨ʱ����Ҫ��ϸ����������֮���������ϵ��

4. **���л���ս**����Ȼ�����㷨����Ǳ�ڵĲ����ԣ�����ʵ��ʵ�ֲ��л�ʱ���ܻ�����һЩ��ս�����磬�����Ч�ط��������񵽲�ͬ�Ĵ������ϡ���δ���������֮���ͨ�ź�ͬ�������ⶼ��Ҫ��ϸ���ǡ�

5. **����������**����Ȼ���β���������������͵����⣬���������������ⶼ�ʺϲ��÷��β��ԡ���ĳЩ����£�������Ҫ���������㷨��Ʋ�����������⡣

### �ܽ�

�����㷨��һ��ǿ�����Ч���㷨��Ʋ��ԣ���ͨ���ݹ�ؽ�������ֽ�ΪС���⣬���ϲ�������Ľ����õ�ԭ����Ľ⡣���ֲ����ڴ�����ģ����ʱ�ر����ã���Ϊ�����Բ��еش����������⣬�Ӷ�����㷨��Ч�ʡ��ڼ������ѧ���㷨����У������㷨���Ź㷺��Ӧ�ã�������������������������������ȡ�

```cpp
//������a���±귶Χ��[ns,ne)��Ԫ�ؽ��й鲢����
void MergeSort(int*a,int ns,int ne)
{
	//1.�ݹ���ֹ����
	//�뿪������ֻ��1��Ԫ�أ���ʱһ������ 
	if(ne-ns==1)
		return; 
	//2.���ַ���ȡ�м�λ�� 
	//��2����������зֿ����� 
	int m=ns+(ne-ns)/2;	//ȡ�м�λ�� 
	MergeSort(a,ns,m);	//�������鲢���� [ns,m)
	MergeSort(a,m,ne);	//�Ұ�����鲢���� [m,ne)
	//3.�ϲ�
	//1)����ȡ���������Ԫ�أ����кϲ� 
	int *ta=new int[ne-ns];//����һ����ʱ���� 
	int nl=ns,nr=m;	//���ߵ���������ұߵ��������±� 
	int nt=0;		//��ʱ������±�
	for(;;){
		//�������[ns,m),�Ұ�����[m,ne) 
		if(nl>=m || nr>=ne)
			break;
		if(a[nl]<=a[nr]){	//��ߵ�С 
			ta[nt]=a[nl];	//ȡ���Ԫ�� 
			nl++;			//��벿�±����� 
			nt++;			//��ʱ������±����� 
		}
		else{				//�ұߵ�С          
			ta[nt]=a[nr];	//ȡ�ұ�Ԫ��        	
			nr++;			//�Ұ벿�±�����    
			nt++;			//��ʱ������±�����
		}		
	}
	
	//2)����������ûȡ�꣬�ͷŵ���ʱ����
	while(nl<m)
		ta[nt++]=a[nl++];
	//3)����Ұ�����ûȡ�꣬�ͷŵ���ʱ����
	while(nr<ne)
		ta[nt++]=a[nr++];
	//4)��ʱ���鸳ֵ������a
	for(int i=0;i<ne-ns;i++)
		a[ns+i]=ta[i]; 
	//5)�ͷ���ʱ�ռ� 
	delete[] ta; 
}
#include <iostream>
using namespace std; 
//������a���±귶Χ��[ns,ne)��Ԫ�ؽ��й鲢����
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




vector����
```cpp
vector<int> g;
g.push_back(3);
g.push_back(2);
g.push_back(1);

int a = 3;b = 4;
swap(a,b);//������ַ������������

0x 16����ǰ׺
o  8����ǰ׺

{   3, 		2,		 1}
    |       			|
s.begin()				s.end()
sort(s.begin(),s.end());
```
string����
```
string s;//string�������stl
s.push_back('d');
s.pop_back();
s.substr(i,k);//��ȡ�ַ���
reverse//��ת
```



Day23