#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct paidui{
    int id;
    double time;
} pd[N];

int cmp(paidui a,paidui b){
    return a.time < b.time;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pd[i].time;
        pd[i].id = i+1;
    }

    sort(pd, pd + n,cmp);
    
    for (int i = 0; i < n;i++){
        cout << pd[i].id << " ";
    }
double sum = 0.00,x=0.00;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            x += pd[j].time;
        }
        sum += x;
        x = 0;
    }
    // sum -= pd[n - 1].time;
    sum = sum / (double)n;
    cout <<endl << fixed << setprecision(2) << sum << endl;
    return 0;
}