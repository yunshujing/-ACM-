#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    double s;
    cin >> s;

    double sum = 0.00;
    int cnt = 0;
    double x = 2.0;
    while(sum<s){
        sum += x;
        cnt++;
        x *= 0.98;
    }

    cout << cnt << endl;

    return 0;
}