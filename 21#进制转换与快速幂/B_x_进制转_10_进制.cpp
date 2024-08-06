#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;
int x_to_ten_base(int n,string s);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    cout <<x_to_ten_base(n,s)<< endl;
    return 0;
}

int x_to_ten_base(int n,string s){
    int sum = 0;
    for (char x:s){
        sum *= n;
        if(x>='A'&&x<='Z'){
            sum += (int) (x - 'A' + 10);
        }
        else
            sum += (int)(x - '0');
        
    }
    return sum;
}
