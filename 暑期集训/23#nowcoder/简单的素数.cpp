#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;
//函数定义，素数判断
bool isPrime(int x) {
    if (x < 2)
    {
        return false;
    }
    //试除法
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
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if (isPrime(x))
        {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }

    return 0;
}

