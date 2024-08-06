#include <iostream>  
#include <string>  
#include <vector>  
  
using namespace std;  
  
string canFormSubsequence(const string& s, const string& t) {  
    string result = s; // 复制s到result，以便修改  
    int j = 0; // t的指针  
    for (int i = 0; i < result.size() && j < t.size(); ++i) {  
        if (result[i] == '?' || result[i] == t[j]) {  
            // 如果result[i]是'?'或者已经匹配上了t[j]，则替换'?'为t[j]（如果它是'?'的话）  
            if (result[i] == '?') {  
                result[i] = t[j];  
            }  
            ++j; // 移动t的指针  
        }  
        // 如果result[i]不是'?'且不等于t[j]，则继续遍历result，不需要替换  
    }  
    // 检查是否所有的t中的字符都被匹配了  
    if (j == t.size()) {  
        return "YES\n" + result;  
    } else {  
        return "NO";  
    }  
}  
  
int main() {  
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