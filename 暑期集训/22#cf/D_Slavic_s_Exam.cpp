#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;

string canFormSubsequence(const string& s, const string& t) {  
    string result = s; // 复制s到result，以便修改  
    int j = 0; // t的指针
    bool flag = 0;
    for (int i = 0; i < result.size() && j < t.size(); ++i) {  
        if (result[i] == '?' || result[i] == t[j]) {  
            // 如果result[i]是'?'或者已经匹配上了t[j]，则替换'?'为t[j]（如果它是'?'的话）  
            if (result[i] == '?') {  
                result[i] = t[j];  
            }  
            ++j; // 移动t的指针
            if(j==t.size()){
                j = 0;
                flag = 1;
            }
        }  
        // 如果result[i]不是'?'且不等于t[j]，则继续遍历result，不需要替换  
    }  
    // 检查是否所有的t中的字符都被匹配了  
    if (flag) {  
        return "YES\n" + result;  
    } else {  
        return "NO";  
    }  
}  
  
signed main() {  
    int T;  
    cin >> T;  
    cin.ignore(); // 忽略T后面的换行符  
    while (T--) {  
        string s, t;  
        getline(cin, s); // 读取整行作为s  
        getline(cin, t); // 读取整行作为t  
        cout << canFormSubsequence(s, t) << endl;  
    }  
    return 0;  
}