#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;
vector<int> t(24, 1);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    int x = b;
    while(x%24!=c){
        t[x%24] = 0;
        x++;
    }
    if(t[a]==1)
        cout << "Yes" << endl;
    else{
        cout << "No" << endl;
    }

    return 0;
}