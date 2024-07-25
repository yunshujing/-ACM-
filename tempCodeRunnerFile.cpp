#include<bits/stdc++.h>  
using namespace std;  
  
#define int long long  
#define endl "\n"  
  
int f(int a, int b, int n) {  
    if (n == 1 || n == 2)  
        return 1;  
  
    int f1 = 1, f2 = 1;  
    for (int i = 3; i <= n; ++i) {  
        int fn = (a * f2 + b * f1) % 7;  
        f1 = f2;  
        f2 = fn;  
    }  
    return f2;  
}  
  
signed main() {  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
    cout.tie(nullptr);  
  
    int a, b, n;  
    while (cin >> a >> b >> n && !(a == 0 && b == 0 && n == 0)) {  
        cout << f(a, b, n) << endl;  
    }  
    return 0;  
}