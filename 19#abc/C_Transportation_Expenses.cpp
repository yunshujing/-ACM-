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
    
    int l = 0, r = m;
    while (l<r) {
        int mid = l + (r-l+1)/2;
        int tot = 0;
        for (int i = 1; i <= n;i++) {
            tot += min(mid, a[i]);  
        }
        if(tot < m){
            l = mid +1;
            }
        else
            r = mid;
    }             //ÖÕÖ¹ÓÚl = r
    while (1){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            sum += min(l, a[i]);
        }
        if (sum > m){
            l--;
        }
        else{
            break;
        }
    }
    cout << l << endl;
    return 0;
}


/* #include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
int a[N];
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
    sort(a + 1, a + n + 1);
    if(sum<=m){
        cout << "infinite" << endl;
        return 0;
    }

    int cnt = m/n;
    for (int i = 1; i < n; i++)
    {
        m -= a[i];
        int res = m / (n - i);
        cnt = max(cnt, res);
    }
    cout << cnt << endl;

    return 0;
} */


