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
////*注意： 不要用double类型 ，因为double 再算距离的时候会造成精度不准确，算不出相等，所以在算距离的时候 不用开根号，直接进行比较*
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
//        }//读入
//
//        for (int i = 0; i < t; i++) {//监管者
//            int max = -1; int m = -1;
//            for (int j = 0; j < n; j++) {//密码机
//                int tmp = 0;
//                tmp = jl(c[i].x, c[i].y, a[j].x, a[j].y);
//                if (tmp > max ) {
//                    max = tmp;
//                    m = j;//距离最大坐标
//                }
//            }
//            for (int i = 0; i < k; i++) {//求生者出生机
//                if (b[i].x == a[m].x && b[i].y == a[m].y) {
//                    cnt++;
//                    break;
//                }
//            }//注意这里不能单独提出来计算，否则重复只会计算一次，要放进每个监管者都遍历一遍
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
//    int n;//学号
//    int s[N];//每首歌的快乐度
//    int sum;
//};
//typedef Sudent student;
//student k[N],l[N];
//
//void kuaile(student,student,int,int);
//
////第一行共四个整数 n, m, a, b，分别代表待选的歌的数量，需要选出的歌的数量，班上的人数，她的学号。
//int main() {
//    int n,m,a,b;
//    while (cin >> n >> m >> a >> b) {
//        //导入数据
//        for (int i = 0; i < a; i++) {
//            k[i].n = i + 1;
//            for (int j = 0; j < n; j++) {
//                cin >> k[i].s[j];
//            }
//        }
//        //计算每首歌的快乐度
//        void kuaile(k[a],l[a],a,n);
//        //快乐度从大到小排好序
//        sort()
//        //寻找最喜欢的歌
//
//        //提出前m首歌
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
//监管者 可以 ban(禁用) 掉 求生者阵营 5 名角色，
// 求生者 可以 ban(禁用) 掉 监管者阵营2 名角色
#include<bits/stdc++.h>
using namespace std;
struct Student {
    int x;
    string name;
    char zy;
    int sld;
};

typedef Student student;
student w[1000],h[1000],s[1000];//h监管者//s求生者
bool cmp(student e1, student e2);

int main() {
    int n, m; int j=0,k=0;
    cin >> n >> m;
        for (int i = 0; i < n+m; i++) {
            cin >> w[i].name >> w[i].zy >> w[i].sld ;
        }//全部导入s
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
        //分阵营
        sort(h, h + j, cmp);
        sort(s, s + j, cmp);
        //排序
        //ban
        for (size_t i = 2; i < j; i++)
        {
            cout << h[i].name << endl;
        }
        for (size_t i = 5; i < k; i++)
         {
            cout << s[i].name << endl;
         }
        //输出监管者阵营选择角色的角色名
        //求生者阵营选择角色的角色名，按照熟练度从高到低排列。
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