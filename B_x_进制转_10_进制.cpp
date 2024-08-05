#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int sum = 0;
    for (char x:s){
        sum *= n;
        if(x>='A'&&x<='Z'){
            sum += (int) (x - 'A' + 10);
        }
        else
            sum += (int)(x - '0');
        
    }
    cout << sum << endl;
    return 0;
}