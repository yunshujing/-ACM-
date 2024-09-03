#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt=0;
        for (int x = 0; x < n-2;x++)
        {
            if(s[x]=='m'&&s[x+1]=='a'&&s[x+2]=='p'){
                        cnt++;
                        x += 2;
            }
            else if(s[x]=='p'&&s[x+1]=='i'&&s[x+2]=='e'){
                        cnt++;
                        x += 2;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}