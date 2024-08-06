#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

int a[60];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l, r;
    cin >> l >> r;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum < n * l || sum > n * r)
    {
        cout << "-1";
        return 0;
    }
    int more = 0, less = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>r){
            more += (a[i] - r);
        }
        if(a[i]<l){
            less += (l - a[i]);
        }
    }
    cout << (less > more ? less : more) << endl;

    return 0;
}