#define _CRT_SECURE_NO_WARNINGS


//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N = 1e6 + 10;
// 
//for (int i = 0; i < n; i++){}
//scanf("%d", &n);
//printf("%d", n);
// �ṹ��
//struct Student {
//    int x;
//    string name;
//    char zy;
//    int sld;
//};

//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//int main() {
//	int n;
//	cin >> n;
//	if (n >= 1 && n <= 99) {
//		cout << 100 - n;
//	}
//	if (n >= 100 && n <= 199) {
//		cout << 200 - n;
//	}
//	if (n >= 200 && n <= 299) {
//		cout << 300 - n;
//	}
//	if (n >= 300 && n <= 299) {
//		cout << 400 - n;
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//int main() {
//	int n, t, p,cnt=0;
//	int a[10000];
//	cin >> n >> t >> p;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		if (a[i] >= t)cnt++;
//	}
//	if (cnt >= p) {
//		cout << '0';
//	}
//	else {
//		for (int i = 0; i < n; i++) {
//			for (int j = i; j < n; j++) {
//				if (a[i] > a[j]) {
//					int temp = a[i];
//					a[i] = a[j];
//					a[j] = temp;
//				}
//			}
//		}
//		cout << t - a[n - p];
//	}
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
#define int long long
//bool huiwen(int);
static long find(int index);
signed main() {
	int n; int cnt = 0;
	cin >> n;
    if (n == 1)cout << '0';
    else if (n == 2)cout << '1';
    long res = find(n-2);
    cout << res;
	return 0;
}
static long find(int index) {
    int count = 0;
    int number = 9;                        //��¼��λ�ϵĻ����������λ������Ϊ9
    int w = 0;                            //��¼��λ

    long half;                            //��������������ߵĽ��
    long h = 1;                            //�����������ߵ���ʼ����
    long res;                            //���

    while (true) {
        if (w > 0 && w % 2 == 0) {            //ÿ��������λ������������10
            number *= 10;
        }
        w++;                            //��λ��һ
        if (count + number > index)        //���������ڲ��ҵĻ���,����
            break;

        count += number;                //���������ϵ�ǰ��λ�ϵĻ�����
    }

    index -= count;                        //�ڵ�ǰ��λ�ϵ�λ�á���w=5,index=50,����λ�ϵĵ�50������������������

    for (int i = 0; i < (w - 1) / 2; i++) {    //������������ߵĻ����������������λ�ϣ���Ϊ100
        h *= 10;
    }

    half = h + index;                        //�����������ߣ���100 + 50 = 150

    res = half;

    if (w % 2 != 0)                            //���Ϊ���������м��Ǹ������������Ұ���ˣ�
        half /= 10;

    while (half != 0) {                        //ƴ�ӻ�����
        res = res * 10 + half % 10;
        half /= 10;
    }

    return res;
}
