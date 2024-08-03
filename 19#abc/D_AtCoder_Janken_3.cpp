#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
char a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length();i++)
    {
        if(s[i]=='R'){
            a[i] += 'P';
        }
        if(s[i]=='S'){
            a[i] += 'R';
        }
        if(s[i]=='P'){
            a[i] += 'S';
        }
    }
    int cnt = 0;
    for (int i = 0; i < s.length();i++){
        if(a[i]!=a[i+1]){
            cnt++;
        }
        else{
            cnt++;
            i++;
        }
    }
    cout << cnt << endl;
    return 0;
}
