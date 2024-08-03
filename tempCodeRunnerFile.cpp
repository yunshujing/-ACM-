#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s, s1, s2, v1, v2, t1, t2, p;
    double a, b;
    cin >> s >> v1 >> v2;
    s1 = 0;
    s2 = s;
    do
    {
        p = (s1 + s2) / 2.0;//预选点
        a = p / v2;//前段时间
        b = (p - a * v1) / (v1 + v2);//车回来与甲相遇时�?
        t1 = a + (s - p) / v1;//�?
        t2 = a + b + (s - (a + b) * v1) / v2;//�?
        if (t1 < t2)
            s2 = p;
        else
            s1 = p;
    } while (fabs(t1 - t2) > 1e-8);
    cout << fixed << setprecision(6) << t1 << endl;
    return 0;
}