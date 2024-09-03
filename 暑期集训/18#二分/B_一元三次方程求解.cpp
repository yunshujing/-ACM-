#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

double f(int x, int a, int b, int c, int d);
double f(int x,int a,int b,int c,int d){
    return a * x * x * x + b * x * x + c * x + d;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double x1, x2,y1,y2,mid;
    for (int i = -100; i < 100;i++){
        x1 = i;
        x2 = i + 1;
        y1 = f(x1, a, b, c, d);
        y2 = f(x2, a, b, c, d);
        if(!y1){//如果符合条件，则直接输出
            cout <<fixed<<setprecision(2)<< x1 << " ";
        }
        if(y1*y2<0){
            while (x2 - x1 >= 0.001){ // for(int i = 0; i<100; i++){
                mid = (x2 + x1) / 2;
                if (f(mid,a,b,c,d)*f(x2,a,b,c,d)<=0)
                    x1 = mid; // 判定，然后继续二分
                else
                    x2 = mid;
            }
            cout <<fixed<<setprecision(2)<< x2 << " ";
        }
    }
    return 0;
}





// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     double a, b, c, d;
//     scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
//     double l, r, m, x1, x2;
//     int s = 0;
//     for (int i = -100; i < 100; i++)
//     {
//         l = i;
//         r = i + 1;
//         x1 = a * l * l * l + b * l * l + c * l + d;
//         x2 = a * r * r * r + b * r * r + c * r + d;
//         if (!x1)
//         {
//             printf("%.2lf ", l);
//             s++;
//         }
//         if (x1 * x2 < 0)
//         {
//             while (r - l >= 0.001)
//             {
//                 m = (l + r) / 2;
//                 if ((a * m * m * m + b * m * m + c * m + d) * (a * r * r * r + b * r * r + c * r + d) <= 0)
//                     l = m;
//                 else
//                     r = m;
//             }
//             printf("%.2lf ", r);
//             s++;
//         }
//     }
// }