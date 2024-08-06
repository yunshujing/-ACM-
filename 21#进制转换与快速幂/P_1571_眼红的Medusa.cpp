//map法
/* 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;
int a[N];
map<int, bool> mp;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b;
        mp[b]=true;
    }
    for (int i = 0; i < n;i++){
        if(mp[a[i]]){
            cout << a[i] << " ";
        }
    }
    return 0;
}
//  */


// 二分法
/* 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
int a[N],b[N];
//vector <int> a;
int bin_search(int *a, int n, int x);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b, b + m);
    for (int i = 0; i < n; i++){
        int x = a[i];
        int l = bin_search(b, m, x);
        if(x==b[l]){
            cout << x << " ";
        }
    }
    return 0;
}

int bin_search(int *a, int n, int x){  //a[0]～a[n-1]是单调递增的
    int l = 0, r = n;              //注意：不是 n-1
    while (l < r) {
        int mid = (l + r)/2; 
        //int mid = (l + r) >> 1;  
        if (a[mid] >= x)  r = mid;
        else    l = mid + 1;
    }                   //终止于left = right
    return l;       //特殊情况：a[n-1] < x时，返回n
}
 */