#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;
string decompress(const string &s);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    string s;  
    getline(cin, s); // 从标准输入读取一行字符串  
    cout << decompress(s) << endl; // 输出解压缩后的字符串  
    
    return 0;
}
  
// 解压缩字符串的函数  
string decompress(const string& s) {  
    // 使用栈来存储重复次数和对应的字符串片段  
    // pair的第一个元素是重复次数，第二个元素是字符串片段  
    stack<pair<int, string>> stk;  
    string current; // 用于构建当前正在处理的字符串片段  
    int repeat = 0; // 用于记录当前的重复次数  
  
    // 遍历输入字符串的每个字符  
    for (char c : s) {  
        // 如果字符是数字，则更新重复次数  
        if (isdigit(c)) {  
            repeat = repeat * 10 + (c - '0'); // 将数字转换为整数并累加到repeat上  
        }  
        // 如果遇到'['，表示压缩块的开始  
        else if (c == '[') {  
            // 如果在'['之前已经构建了字符串片段，则将其和重复次数1压入栈中  
            if (!current.empty()) {  
                stk.push({repeat==0?1:repeat, current});  
                current.clear(); // 清空current以准备构建新的字符串片段  
            }  
            // 压入当前的重复次数和一个新的空字符串片段到栈中  
            // stk.push({repeat, ""});  
            repeat = 0; // 重置重复次数  
        }  
        // 如果遇到']'，表示压缩块的结束  
        else if (c == ']') {  
            // 弹出栈顶的字符串片段和重复次数  
            string content = stk.top().second; /* stk.pop(); */  
            int times = stk.top().first; stk.pop();  
            
            // 根据重复次数构建重复的字符串  
            string repeated;  
            for (int i = 0; i < times; ++i) {  
                repeated += content;  
            }  
            
            // 如果栈不为空，则将重复的字符串附加到上一个字符串片段上  
            if (!stk.empty()) {  
                stk.top().second += repeated;  
            } else {  
                // 如果栈为空，说明这是最外层的压缩块，直接返回解压缩后的字符串  
                return repeated;  
            }  
        }  
        // 如果字符既不是数字也不是'['或']'，则将其添加到当前字符串片段中  
        else {  
            current += c;  
        }  
    }  
    return stk.empty() ? current : stk.top().second;  
}





#include<bits/stdc++.h>
using namespace std;
string read()
{
	int n;
	string s="",s1;
	char c;
	while (cin>>c)//一直读入字符，直到Ctrl+z
	{
		if (c=='[')
		{
			cin>>n;//读入D
			s1=read();//读入X
			while (n--) s+=s1;//重复D次X
            //注：上面不能写成while (n--) s+=read();
		}
		else 
		{
			if (c==']') return s;//返回X
		    else s+=c;//如果不是'['和']'，那就是X的一个字符，所以加进X
		}
	}
}
int main()//巨短主函数
{
	cout<<read(); 
	return 0;
}