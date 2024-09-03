#include<bits/stdc++.h>  
using namespace std;  
#define int long long  
#define endl "\n"  
const int N = 1e6 + 10; // 注意这个常量在代码中没有直接使用，但定义也没问题  
const double eps = 1e-7; // 这个常量同样在代码中没有使用  
  
signed main(){  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
    cout.tie(nullptr);  
  
    string s, sx = "", sk = ""; // 初始化 sx 和 sk 为空字符串  
    cin >> s;  
  
    int a = 0, b = 0;  
    for(char x : s){  
        if(x >= 'a' && x <= 'z'){  
            a++;  
            sx += x;  
            sk += (x - 'a' + 'A'); // 将小写转换为大写并添加到 sk  
        }  
        else if(x >= 'A' && x <= 'Z'){ // 确保只处理大写字母  
            b++;  
            sx += (x - 'A' + 'a'); // 将大写转换为小写并添加到 sx  
            sk += x;  
        }  
    }  
  
    if(a > b){  
        cout << sx << endl; // 输出小写字母组成的字符串  
    }  
    else{  
        cout << sk << endl; // 输出大写字母组成的字符串  
    }  
  
    return 0;  
}