#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        map <char,int> mp;
        for (int i = 0; i < 4 * n; i++)
        {
            char x;
            cin >> x;
            mp[x]++;
        }
        int cnt = 0;
        if (mp['A'] >= n)
        {
            cnt+=n;
        }
        else
            cnt += mp['A'];
        if (mp['B'] >= n)
        {
            cnt+=n;
        }
        else
            cnt += mp['B'];
        if (mp['C'] >= n)
        {
            cnt+=n;
        }
        else
            cnt += mp['C'];
        if (mp['D'] >= n)
        {
            cnt+=n;
        }
        else
            cnt += mp['D'];
        cout << cnt  << endl;
    }
        return 0;
}