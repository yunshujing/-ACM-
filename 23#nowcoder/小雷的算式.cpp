#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
// int a[N];
vector <int> a;
bool cmp(int a, int b){
    return a > b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    string s;
    getline(cin, s);

    int cnt = 0, sum = 0;
    for (int i = 0; i < s.size();i++)
    {
        char x = s[i];
        if(x>='0'&&x<='9'){
            cnt = cnt * 10 + (int)(x - '0');
        }
        if(x=='+'||i == s.size()-1){
            a.push_back(cnt);
            sum += cnt;
            cnt = 0;
        }
    }
    int len = a.size();
    sort(a.begin(), a.end(),cmp);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << (i < (len - 1) ? "+" : "\n");
    }
    cout << sum << endl;
    return 0;
}