#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
int a[100];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum<=m){
        cout << "infinite" << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    
    int cnt = 0;

    int i = 1, j = n;              //注意：不是 n-1
    while (i<j) {
        int mid = i + (j-i+1)/2;
        if(a[mid]*n <= m)
            i = mid;
        else
            j = mid-1;
    }             //终止于l = r
    cnt = a[i];
    cout << cnt << endl;

    return 0;
}