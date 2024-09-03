// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// #define fi first
// #define se second
// #define mod3 998244353
// #define mod7 1000000007
// const int N = 1e6 + 10;
// const double eps =1e-4;
// string s[1000];
// int len[1000];

// signed main(){
//     ios::sync_with_stdio(false);
//     // cin.tie(nullptr);
//     cout.tie(nullptr);

//     int n;
//     cin >> n;
//     int max=0;
//     for (int i = 0; i < n; i++){
//         cin>>s[i];
//         len[i] = s[i].size();
//         if(len[i]>max){
//             max = len[i];
//         }
//         if(len[i]<len[i-1]){
//             int cnt = len[i - 1] - len[i];
//             string st = s[i];
//             while (cnt--)
//                 st = st + '*';
//             s[i] = st;
//         }
//     }
//     for (int i = 0; i < max; i++){
//         for (int j = n-1; j >=0;j--){
//                 cout << s[j][i] ;
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>  
#include <vector>  
#include <string>  
#include <algorithm> // 用于 std::max  
  
using namespace std;  
  
#define int long long  
#define endl "\n"  
  
signed main() {  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
    cout.tie(nullptr);  
  
    int n;  
    cin >> n;  
    vector<string> s(n);  
    int maxLength = 0;  
  
    // 读取字符串并找到最长长度  
    for (int i = 0; i < n; i++) {  
        cin >> s[i];  
        maxLength = max(maxLength, static_cast<int>(s[i].size()));  
    }  
  
    // 竖写输出  
    for (int i = 0; i < maxLength; i++) {  
        for (int j = n - 1; j >= 0; j--) {  
            if (i < s[j].size()) {  
                cout << s[j][i]; // 如果当前位置在字符串内，则输出字符  
            } else if(i<s[j-1].size()) {  
                cout << '*'; // 否则输出 '*'  
            }  
        }  
        cout << endl;  
    }  
    
    return 0;  
}