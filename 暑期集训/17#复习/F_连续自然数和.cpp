#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int p1 = 0, p2 = 1;
    int sum = p1+p2;
    while(p1<p2&&p2<=n){
        if(sum==n){
            cout << p1 << " " << p2 << endl;
            sum -= p1;
            p1++;
        }
        if (sum > n){
            sum -= p1;
            p1++;
        }
        if(sum<n){
            p2++;
            sum += p2;
        }
    }

    return 0;
}