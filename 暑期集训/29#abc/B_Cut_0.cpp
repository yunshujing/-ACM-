// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define double long double
// #define endl "\n"
// #define fi first
// #define se second
// #define mod3 998244353
// #define mod7 1000000007
// const int N = 1e6 + 10;
// const double eps =1e-4;

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);

//     string x; cin >> x;
//     int flag = 0;
//     for (int i = x.size() - 1; i >= 0; i--) {
//         if (flag == 0 && x[i] == '0') {
//             x.erase(i, 1);
//         }
//         else if (flag == 0 && x[i] == '.') {
//             flag = 1; x.erase(i, 1); break;
//         }
//         else if (flag == 0 && x[i] != '0') {
//             flag = 1; break;
//         }
//     }
//     cout << x << endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define fi first
#define se second
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    double x;
    cin >> x;
    cout << x;

    return 0;
}
