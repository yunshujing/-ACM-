#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);

    string s, t;
    vector<string> x;
    cin >> s >> t;
    int len = s.size();
    for (int i = 0; i < len;i++){
        if(s[i]>t[i]){
            string ss1 = s.substr(0, i);
            char ss2 = t[i];
            string ss3 = s.substr(i+1);
            string sss = ss1 + ss2 + ss3;
            x.push_back(sss);
            s = sss;
        }
    }
    for (int i = len-1; i >= 0;i--){
            if(s[i]<t[i]){
                string ss1 = s.substr(0, i);
                char ss2 = t[i];
                string ss3 = s.substr(i+1);
                string sss = ss1 + ss2 + ss3;
                x.push_back(sss);
                s = sss;
            }
        }
    cout << x.size() << endl;
    for (int i = 0; i < x.size(); i++){
        cout << x[i] << endl;
    }

    return 0;
}