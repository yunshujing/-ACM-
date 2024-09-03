#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int w;
    cin >> w;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int i = 0, j = n - 1;
    while(i<=j){
        if(i==j){
            cnt++;
            break;
        }
        if(a[i]+a[j]<=w){
            cnt++;
            i++;
            j--;
        }
        else{
            j--;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
