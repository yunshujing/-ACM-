#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

bool cmp(int a, int b){
    return a > b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    vector<int> s;
    for (int i = 0; i<n;i++){
        int x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end(),cmp);
    int mx1 = s[0], mx2 = s[1];
    int cnt = 0;
    while(mx1>=1&&mx2>=1){
        s[0]--;
        s[1]--;
        sort(s.begin(), s.end(),cmp);
        mx1 = s[0], mx2 = s[1];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}