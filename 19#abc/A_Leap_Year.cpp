#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int y;
    cin >> y;
    int day=0;
    if(y%4!=0||y%100==0&&y%400!=0)
        day = 365;
    if(y%4==0&&y%100!=0||y%400==0)
        day = 366;

    cout << day << endl;

    return 0;
}