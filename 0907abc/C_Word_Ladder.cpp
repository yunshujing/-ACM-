#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

struct Step
{
    char zm;
    int zb;
};

Step step2[110];

bool cmp(Step a, Step b){
    return a.zm < b.zm;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);

    string s, t;
    vector<string> x;
    int flag = 1;
    cin >> s >> t;
    int len = s.size();
    int c = 0;
    for (int i = 0; i < len;i++){
        if(s[i]>t[i]){
            string ss1 = s.substr(0, i);
            char ss2 = t[i];
            string ss3 = s.substr(i+1);
            string sss = ss1 + ss2 + ss3;
            x.push_back(sss);
            s = sss;
            flag= 0;
        }
        else if(s[i]!=t[i]){
            step2[c].zm = t[i];
            step2[c].zb = i;
            c++;
            flag = 0;
        }
    }
    if(flag){
        cout << "0" << endl;
        return 0;
    }

    sort(step2, step2+c, cmp);
    for (int i = 0; i < c;i++){
        int j = step2[i].zb;
        string ss1 = s.substr(0, j);
        char ss2 = step2[i].zm;
        string ss3 = s.substr(j+1);
        string sss = ss1 + ss2 + ss3;
        x.push_back(sss);
    }
    
    int cnt = 0;
    
    if(!x.empty()){
        cnt = x.size();
        cout << cnt << endl;
        
        for (int i = 0; i < cnt;i++){
            cout << x[i] << endl;
        }
    }
    return 0;
}