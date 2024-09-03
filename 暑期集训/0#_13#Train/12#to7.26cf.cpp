// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// #define N 1e6+10

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);



//     return 0;
// }

// A
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        for (int i = 0;;i++){
            int x = m - 2 * i;
            if(x%4==0){
                cout << i + x / 4 << endl;
                break;
            }
        }
    }
    return 0;
}
*/


// B
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int newSize = n / k;
        vector<string> reducedGrid(newSize, string(newSize, '0'));

        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < n; j += k) {
                reducedGrid[i / k][j / k] = grid[i][j];
            }
        }

        for (const auto& row : reducedGrid) {
            cout << row << endl;
        }
    }
    return 0;
}
*/


// C
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

// 对字符串的指定子区间进行排序的函数  
string sortSubstring(const string& s, int start, int end) {  
    string result = s.substr(start, end - start + 1);  
    sort(result.begin(), result.end());  
    return result;  
} 

// 模拟查询操作的函数  
string query(const string& a, const string& b, int aStart, int aEnd, int bStart, int bEnd) {  
    string sortedA = sortSubstring(a, aStart, aEnd);  
    string sortedB = sortSubstring(b, bStart, bEnd);  
    return "sorted(a(" + to_string(aStart) + "," + to_string(aEnd) + "))='" + sortedA + "' and sorted(b(" + to_string(bStart) + "," + to_string(bEnd) + "))='" + sortedB + "'";  
}  
  
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a = "abcde";  
    string b = "dcba";  

    // 模拟查询  
    cout << query(a, b, 1, 5, 1, 4) << endl; // 假设查询的是a和b的子字符串  

    return 0;
}
*/
