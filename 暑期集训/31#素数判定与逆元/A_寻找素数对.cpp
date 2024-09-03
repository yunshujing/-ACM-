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

bool miller_rabin(int x) {
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
    int n;
    while(cin >> n){
    int x1=0, x2=0, cnt=0x3f3f3f3f;
    for (int i = 1; i < n;i++){
        if(miller_rabin(i)&&miller_rabin(n-i)){
                if(abs(n-2*i)<cnt){
                    x1 = min(i, n - i);
                    x2 = max(i, n - i);
                    cnt=abs(n - 2 * i);
                }
            
        }
    }
    cout << x1 << " " << x2 << endl;
    }
    return 0;
}
