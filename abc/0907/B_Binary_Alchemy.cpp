#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int n;
int s[110][110];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i;j++){
            cin >> s[i][j];
        }
    }

    int a = 1, b = 1;
    while(a <= n && b <= n){
        int t=0;
        if(a<b){
            t = s[b][a];
        }
        else{
            t = s[a][b];
        }
        a = t;
        b++;
    }
    cout << a << endl;
    return 0;
}