#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;

    int i=0, j=sqrt(n);
    while (i<j) {
        int mid = i + (j-i+1)/2;
        if(fabs(mid*mid*mid)<=n)
            i = mid;
        else
            j = mid-1;
    }
    cout << i << endl;
    return 0;
}