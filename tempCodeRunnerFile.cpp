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
    getline(cin, s); // �ӱ�׼�����ȡһ���ַ���  
    cout << decompress(s) << endl; // �����ѹ������ַ���  
    
    return 0;
}
  
// ��ѹ���ַ����ĺ���  
string decompress(const string& s) {  
    // ʹ��ջ���洢�ظ������Ͷ�Ӧ���ַ���Ƭ��  
    // pair�ĵ�һ��Ԫ�����ظ��������ڶ���Ԫ�����ַ���Ƭ��  
    stack<pair<int, string>> stk;  
    string current; // ���ڹ�����ǰ���ڴ�����ַ���Ƭ��  
    int repeat = 0; // ���ڼ�¼��ǰ���ظ�����  
  
    // ���������ַ�����ÿ���ַ�  
    for (char c : s) {  
        // ����ַ������֣�������ظ�����  
        if (isdigit(c)) {  
            repeat = repeat * 10 + (c - '0'); // ������ת��Ϊ�������ۼӵ�repeat��  
        }  
        // �������'['����ʾѹ����Ŀ�ʼ  
        else if (c == '[') {  
            // �����'['֮ǰ�Ѿ��������ַ���Ƭ�Σ�������ظ�����1ѹ��ջ��  
            if (!current.empty()) {  
                stk.push({repeat==0?1:repeat, current});  
                current.clear(); // ���current��׼�������µ��ַ���Ƭ��  
            }  
            // ѹ�뵱ǰ���ظ�������һ���µĿ��ַ���Ƭ�ε�ջ��  
            // stk.push({repeat, ""});  
            repeat = 0; // �����ظ�����  
        }  
        // �������']'����ʾѹ����Ľ���  
        else if (c == ']') {  
            // ����ջ�����ַ���Ƭ�κ��ظ�����  
            string content = stk.top().second; /* stk.pop(); */  
            int times = stk.top().first; stk.pop();  
            
            // �����ظ����������ظ����ַ���  
            string repeated;  
            for (int i = 0; i < times; ++i) {  
                repeated += content;  
            }  
            
            // ���ջ��Ϊ�գ����ظ����ַ������ӵ���һ���ַ���Ƭ����  
            if (!stk.empty()) {  
                stk.top().second += repeated;  
            } else {  
                // ���ջΪ�գ�˵������������ѹ���飬ֱ�ӷ��ؽ�ѹ������ַ���  
                return repeated;  
            }  
        }  
        // ����ַ��Ȳ�������Ҳ����'['��']'��������ӵ���ǰ�ַ���Ƭ����  
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
	while (cin>>c)//һֱ�����ַ���ֱ��Ctrl+z
	{
		if (c=='[')
		{
			cin>>n;//����D
			s1=read();//����X
			while (n--) s+=s1;//�ظ�D��X
            //ע�����治��д��while (n--) s+=read();
		}
		else 
		{
			if (c==']') return s;//����X
		    else s+=c;//�������'['��']'���Ǿ���X��һ���ַ������Լӽ�X
		}
	}
}
int main()//�޶�������
{
	cout<<read(); 
	return 0;
}