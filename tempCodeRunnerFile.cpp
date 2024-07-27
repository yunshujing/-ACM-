#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

bool cmp(int e1, int e2) {
	return e1 > e2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    int a[200001], b[200001];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    sort(a + 0, a + n, cmp);
	sort(b + 0, b + n, cmp);
    int swt=0, sly=0,cnt=0;
    for (int i = 0; i < n;i++){
        swt += a[i];
        sly += b[i];
        if(swt>x||sly>y){
            break;
        }
        else
            cnt++;
    }
    cout << cnt;
    return 0;
}