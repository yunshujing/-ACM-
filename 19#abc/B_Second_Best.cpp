#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int max1 = 0,max2 = 0;
    int p1=0, p2=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i]>max1){
            max2 = max1;
            max1 = a[i];
            p2 = p1;
            p1 = i;
        }
        else if(a[i]>max2){
            max2 = a[i];
            p2 = i;
        }
    }
    cout << p2 << endl;

    return 0;
}