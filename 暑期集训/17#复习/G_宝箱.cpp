#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int a[1010];

bool cmp(int a, int b){
    return a > b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    sort(a, a + n,cmp);

    int p1 = 0, p2 = 1;
    int sum = a[p1];
    int cz = 0;
    int max = 0;
    while(p1<p2&&p2<=n){
        cz = a[p1] - a[p2];
        if (cz > k){
            if(sum>max){
                max = sum;
            }
            sum -= a[p1];
            p1++;
        }
        if(cz <= k){
            sum += a[p2];
            p2++;
        }
    }
    cout << max << endl;
    return 0;
}
