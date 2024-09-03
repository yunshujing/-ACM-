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

bool isPrime(int x) {
    if (x < 2)
    {
        return false;
    }
    //ÊÔ³ý·¨
    for (int i = 2; i <= x/i; i++)
    {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);
    int n,x;
    while(cin >> n){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            cin >> x;
            if(isPrime(x)){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}