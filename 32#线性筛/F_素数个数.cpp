#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e8 + 5;
const double eps =1e-4;

bool vit[N + 5];   // 是否被筛掉
int k = 0;        // 统计素数个数

void E_sieve(int n){
    // 初始化
    k = 0;
    for (int i = 0; i <= n; i++){
        vit[i] = 0;
    }
    //
    for (int i = 2; i * i <= n; i++){
        if (vit[i] == 0){
            for (int j = i * i; j <= n; j += i){
                vit[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (vit[i] == 0){
            k++;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);
    
    int n ;
    while (cin >> n){   
        E_sieve(n);
        cout << k << endl;
    }
    
    return 0;
}