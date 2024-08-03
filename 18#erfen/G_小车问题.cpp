#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    double s, a, b;
    cin >> s >> a >> b;

    double l,r, t1, t2, tj, ty, m;
    l = 0;
    r = s;
    do
    {
        m = (l+r) / 2.0;
        t1 = m / b;
        t2 = (m - t1 * a) / (a + b);
        tj = t1 + (s - m) / a;
        ty = t1 + t2 + (s - (t1 + t2) * a) / b;
        if (tj < ty)
            r = m;
        else
            l = m;
    }while (fabs(tj - ty) > 1e-8);
    cout << fixed << setprecision(6) << tj << endl;
    return 0;
}