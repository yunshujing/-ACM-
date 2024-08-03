#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 3e5 + 10;

bool cmp(int a, int b){
    return a > b;
}
int a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n, cmp);

    double sum=0.00,pj=0.00,max=0.00;
    for (int j = 0; j < n;j++){
        sum += a[j];
        pj = (double)(sum * sum) / (double)(j+1);
        if(pj>max){
            max = pj;
        }
    }
    cout << fixed << setprecision(8) << max << endl;

    return 0;
}