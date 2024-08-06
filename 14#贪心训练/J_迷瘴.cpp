#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int n, v, w;
        cin >> n >> v >> w;
        int a[N];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        double nd = (double) a[0], tj =(double) v;
        for (int i = 0; i < n; i++)
        {
            double tmp = (nd + a[i])/ (tj+v);
            if(tmp*100.00<=w){
                nd = tmp*100.00;
                tj += v;
            }
        }
        nd = nd / 100.00;
        cout << tj <<" "<< fixed << setprecision(2) << nd << endl;
    }
    

    return 0;
}