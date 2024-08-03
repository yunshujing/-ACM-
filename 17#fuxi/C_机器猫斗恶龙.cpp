#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sum=0, max=0;
    int xt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        xt += x;
        if(xt<0 && -1*xt>max){
            max = xt * -1;
        }
    }
    cout << max + 1 << endl;

    return 0;
}