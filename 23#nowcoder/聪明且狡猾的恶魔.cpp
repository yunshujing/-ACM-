#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int x, n;
        cin >> x >> n;

        int num1 = (n-1) / 2;
        x -= num1;
        cout << x << endl;
    }
    
    return 0;
}