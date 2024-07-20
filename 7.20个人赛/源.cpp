#define _CRT_SECURE_NO_WARNINGS

//解析:
//http://4iz.cn/0nbu

//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N = 1e6 + 10;
// 
//for (int i = 0; i < n; i++){}
//scanf("%d", &n);
//printf("%d", n);
// 结构体
//struct Student {
//    int x;
//    string name;
//    char zy;
//    int sld;
//};


//A
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//int main() {
//	int n;
//	string m;
//	scanf("%d", &n); getchar();
//	for (int i = 0; i < n; i++)
//	{
//		cin>>m;
//		int x = m.length();
//		if (m[x - 3] == 'm' && m[x - 2] == 'a' && m[x - 1] == '?') {
//			printf("En!");
//		}
//		else
//		{
//			cout<<m;
//		}
//		printf("\n");
//	}
//	return 0;
//}


//B
//#include<bits/stdc++.h>
//using namespace std;
//struct Student {
//    int x;
//    char name[12];
//    int cj;
//    int zb;
//};
//typedef Student student;
//vector<student> a;
////student a[1000];
//bool cmp(student e1, student e2);
//int main() {
//    int n; 
//    scanf("%d", &n);
//        for (int i = 0; i < n; i++) {
//            student a;
//            scanf("%s %d %d", &a.name, &a.cj, &a.zb);
//            // a[i].sum = a[i].yuwen + a[i].shuxue + a[i].yinyu;
//        }
//        double sum = 0;int  cnt = 0;
//        for (int i = 0; i < n; i++) {
//            if (a[i].zb == 0) {
//                sum += a[i].cj;
//                a.push_back(a[i]);
//                cnt++;
//            }
//        }
//        double pj = sum / cnt;
//        printf("%.1f\n", pj);
//        sort(a.begin(), a.end(), cmp);
//        for (int i = 0; i < n; i++) {
//            if (a[i].zb == 0) {
//                cout<< a[i].name<<endl;
//            }
//            
//        }
//    return 0;
//}
//bool cmp(student e1, student e2) {
//    return  e1.cj > e2.cj;
//}
//#define _CRT_SECURE_NO_WARNINGS 
//#include<bits/stdc++.h>
//using namespace std;
//struct student {
//    char name[11];
//    int cj;
//    int zb;
//};
//vector<student> a;
//bool cmp(student e1, student e2);
//bool cmp(student e1, student e2) {
//    return  e1.cj > e2.cj;
//}
//int main() {
//    int N; scanf("%d", &N); int sum = 0;//未总成绩
//    for (int i = 0; i < N; i++) {
//        student x;
//        scanf("%s %d %d", &x.name, &x.cj, &x.zb);
//        if (x.zb == 0) {
//            a.push_back(x); sum += x.cj;
//        }
//    }
//    int num = a.size();
//    printf("%.1lf\n", sum * 1.0 / num);
//    sort(a.begin(), a.end(), cmp);
//    for (auto x : a) {
//        printf("%s\n", x.name);
//    }
//    return 0;
//}


//D
//#include<bits/stdc++.h>
//#include <algorithm>
//using namespace std;
////#define ll long long
////vector<long long> a;
//int main() {
//	#define int long long
//	int n, k,num;
//	cin >> n >> k;
//	int a[200001];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lld", &num);
//		a[i] = num;
//	}
//	sort(a, a+n);
//	/*for (int i = 0; i < k ; i++)
//	{
//		int cnt = a.size();
//		if (a[0] - a[cnt - 2] > a[1] - a[cnt - 1]) {
//			a.erase(a.begin());
//		}
//		else{
//			a.pop_back();
//		}
//	}
//	int ct = a.size();*/
//	int b[200001],cnt=0;
//	for (int i = k; i >= 0; i--) {
//		b[cnt] = a[n - 1 - cnt] - a[i];
//		cnt++;
//	}
//	sort(b, b + cnt);
//	int sum = b[0];
//	cout << sum << endl;
//	return 0;
//}
//
//
//#include<iostream> 
//#include <algorithm>
//#define int long long
//using namespace std;
//int n, k, a[200001],x[200000];
//signed main() {
//	cin >> n >> k;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//	}
//	sort(a, a + n);
//	for (int i = k; i >= 0; i--) {
//		x[cnt] = a[n - 1 - cnt] - a[i];
//		cnt++;
//	}
//	sort(x, x + cnt);
//	printf("%d", x[0]);
//}







//E
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#include<math.h>
////struct ZB {
////    int x;
////    int y;
////    int z;
////};
////
////typedef ZB zb;
////zb a[100], b[100];
//
//int main() {
//	ll a, b, c, x, y, z;
//	double len,sum;
//	scanf("%lld %lld %lld", &a, &b, &c); getchar();
//	scanf("%lld %lld %lld", &x, &y, &z);
//	len = sqrt((a - x) * (a - x) + (b - y) * (b - y));
//	sum = len - (c + z);
//		if (sum>0.00) {
//			printf("%.2lf",sum);
//		}
//		else
//		{
//			cout<<"0.00";
//		}
//		printf("\n");
//	
//	return 0;
//}


//F
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#include<math.h>
//bool isPrime(ll x);
//vector<int> s;
//int main() {
//	ll n;
//	scanf("%lld", &n);
//	int cnt = 4;
//	while (1) {
//		ll b = cnt-n;
//		if (b>3 && !isPrime(b)&& !isPrime(cnt))
//		{
//			printf("%lld %lld",cnt,b); break;
//		}
//		cnt++;
//	}
//	return 0;
//}
////函数定义，素数判断
//bool isPrime(ll x) {
//	if (x < 2)
//	{
//		return false;
//	}
//	//试除法
//	for (int i = 2; i <= x / i; i++)
//	{
//		if (x % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}


//G
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#include<math.h>
////bool isPrime(ll x);
////vector<int> s;
//int w(int a, int b, int c);
//int main() {
//	int a, b, c;
//	while (~scanf("%d %d %d", &a,&b,&c)&&a!=-1&&b!=-1&&c!=-1)
//	{
//		int sum=w(a, b, c);
//		scanf("w(%d,%d,%d) = %d", a, b, c, sum);
//	}
//	return 0;
//}
//int w(int a, int b, int c) {
//	if (a <= 0 || b <= 0 || c <= 0) {
//		return 1;
//	}
//	else if (a > 20 || b > 20 || c > 20) {
//		return w(20, 20, 20);
//	}
//	else if (a < b && b < c) {
//		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//	}
//	else return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
//
//}
