#define _CRT_SECURE_NO_WARNINGS

//A
//#include<bits/stdc++.h>
//using namespace std;
//struct Student {
//    char name[9];
//    int yuwen;
//    int shuxue;
//    int yinyu;
//    int sum;
//};
//
//typedef Student student;
//student a[1000];
//bool cmp(student e1, student e2);
//
//int main() {
//    int n;
//    while (cin >> n ) {
//        for (int i = 0; i < n; i++) {
//            cin >> a[i].name >> a[i].yuwen >> a[i].shuxue >> a[i].yinyu;
//            a[i].sum = a[i].yuwen + a[i].shuxue + a[i].yinyu;
//        }
//        for (int i = 0; i < n; i++) {
//            for (int j = i+1; j < n; j++)
//            {
//                if (cmp(a[i], a[j])) {
//                    if (a[i].name[0] > a[j].name[0]) printf("%s %s\n", a[j].name, a[i].name);
//                    else printf("%s %s\n", a[i].name, a[j].name);
//                }
//            }
//        }
//    }
//        return 0;
//}
//
//bool cmp(student e1, student e2) {
//    if ((abs(e1.yuwen - e2.yuwen) <= 5)
//        &&(abs(e1.shuxue - e2.shuxue) <= 5) 
//         &&(abs(e1.yinyu - e2.yinyu) <= 5)
//          &&(abs(e1.sum - e2.sum) <= 10))
//                return true;
//    else return false;
//}


//B
//#include<bits/stdc++.h>
//using namespace std;
//struct Student {
//    int x;
//    string name;
//    int old;
//    int noip;
//    int sum;
//};
//
//typedef Student student;
//student a[1000];
//bool cmp(student e1, student e2);
//
//int main() {
//    int n;
//    while (cin >> n) {
//        for (int i = 0; i < n; i++) {
//            cin >> a[i].name >> a[i].old >> a[i].noip ;
//            a[i].x = i + 1;
////            a[i].sum = a[i].yuwen + a[i].shuxue + a[i].yinyu;
//        }
//        for (int i = 0; i < n; i++) {
//            a[i].old++;
//            if (a[i].noip * 1.2 <= 600) {
//                a[i].noip *= 1.2;
//            }
//            else a[i].noip = 600;
//             cout << a[i].name <<" "<< a[i].old <<" "<< a[i].noip << endl;
//        }
//    }
//    return 0;
//}


//C
//#include<bits/stdc++.h>
//#include<cmath>
//using namespace std;
//struct ZB {
//    int x;
//    int y;
//};
//
//typedef ZB zb;
//zb a[1000], b[1000], c[1000], fj[1000];
//int jl(int, int, int, int);
////*ע�⣺ ��Ҫ��double���� ����Ϊdouble ��������ʱ�����ɾ��Ȳ�׼ȷ���㲻����ȣ�������������ʱ�� ���ÿ����ţ�ֱ�ӽ��бȽ�*
//int cnt = 0;
//
//int main() {
//    int n, t, k;
//    cin >> n >> k >> t;
//        for (int i = 0; i < n; i++) {//mmj
//            cin >> a[i].x >> a[i].y;
//        }
//        for (int i = 0; i < k; i++) {//qsz
//            cin >> b[i].x >> b[i].y;
//        }
//        for (int i = 0; i < t; i++) {//jgz
//            cin >> c[i].x >> c[i].y;
//        }//����
//
//        for (int i = 0; i < t; i++) {//�����
//            int max = -1; int m = -1;
//            for (int j = 0; j < n; j++) {//�����
//                int tmp = 0;
//                tmp = jl(c[i].x, c[i].y, a[j].x, a[j].y);
//                if (tmp > max ) {
//                    max = tmp;
//                    m = j;//�����������
//                }
//            }
//            for (int i = 0; i < k; i++) {//�����߳�����
//                if (b[i].x == a[m].x && b[i].y == a[m].y) {
//                    cnt++;
//                    break;
//                }
//            }//ע�����ﲻ�ܵ�����������㣬�����ظ�ֻ�����һ�Σ�Ҫ�Ž�ÿ������߶�����һ��
//        }     
//        cout << cnt << endl;   
//    return 0;
//}
//
//int jl(int x1, int y1, int x2, int y2) {
//    return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
//}


//D
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 10;
//struct Sudent {
//    int n;//ѧ��
//    int s[N];//ÿ�׸�Ŀ��ֶ�
//    int sum;
//};
//typedef Sudent student;
//student k[N],l[N];
//
//void kuaile(student,student,int,int);
//
////��һ�й��ĸ����� n, m, a, b���ֱ�����ѡ�ĸ����������Ҫѡ���ĸ�����������ϵ�����������ѧ�š�
//int main() {
//    int n,m,a,b;
//    while (cin >> n >> m >> a >> b) {
//        //��������
//        for (int i = 0; i < a; i++) {
//            k[i].n = i + 1;
//            for (int j = 0; j < n; j++) {
//                cin >> k[i].s[j];
//            }
//        }
//        //����ÿ�׸�Ŀ��ֶ�
//        void kuaile(k[a],l[a],a,n);
//        //���ֶȴӴ�С�ź���
//        sort()
//        //Ѱ����ϲ���ĸ�
//
//        //���ǰm�׸�
//    }
//    return 0;
//}
//
//void kuaile(student k[], student l[], int a,int n) {
//    for (size_t i = 0; i < a; i++)
//    {
//
//    }
//}


//E
//����� ���� ban(����) �� ��������Ӫ 5 ����ɫ��
// ������ ���� ban(����) �� �������Ӫ2 ����ɫ
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
struct Student {
    int x;
    string name;
    char zy;
    int sld;
};

typedef Student student;
student w[N],h[N],s[N];//h�����//s������
bool cmp(student e1, student e2);

int main() {
    int n, m; int j=0,k=0;
    cin >> n >> m;
        for (int i = 0; i < n+m; i++) {
            cin >> w[i].name >> w[i].zy >> w[i].sld ;
        }//ȫ������s
        for (int i = 0; i < n + m; i++) {
            if (w[i].zy == 'H') {
                h[j] = w[i];
                j++;
            }
            if (w[i].zy == 'S') {
                s[k] = w[i];
                k++;
            }
        }
        //����Ӫ
        sort(h, h + j, cmp);
        sort(s, s + k, cmp);
        //����
        //ban
        for (int i = 2; i < j; i++)
        {
            cout << h[i].name << endl;
        }
        for (int i = 5; i < k; i++)
         {
            cout << s[i].name << endl;
         }
        //����������Ӫѡ���ɫ�Ľ�ɫ��
        //��������Ӫѡ���ɫ�Ľ�ɫ�������������ȴӸߵ������С�
    return 0;
}

bool cmp(student e1, student e2) {
    return e1.sld > e2.sld;
}



//F
//#include<bits/stdc++.h>
//using namespace std;
//struct Student {
//    int X;
//    double Num;
//};
//
//typedef Student student;
//student a[100];
//bool cmp(student e1, student e2);
//
//int main() {
//    int n, k;
//    while (cin >> n >> k) {
//        for (int i = 0; i < n; i++) {
//            int sum = 0;
//            for (int j = 0; j < k; j++) {
//                int tmp;
//                cin >> tmp;
//                sum += tmp;
//            }
//            a[i].X = i + 1;
//            a[i].Num = sum / k;
//        }
//        sort(a, a + n, cmp);
//        cout << a[0].X << endl << a[1].X << endl;
//
//    }
//
//}
//
//bool cmp(student e1, student e2) {
//    if (e1.Num != e2.Num)
//        return e1.Num > e2.Num;
//    else return e1.X < e2.X;
//}