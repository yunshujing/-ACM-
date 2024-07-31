#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
// 找到最长的连续序列，并在其末尾插入新字符
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n;i++){
        string s;
        cin >> s;

        int len = s.size();
        int tmp = s[0];

        if(len==1){//长度为1
            char ch= char(((int)s[0] + 1-'a') % 26 + 'a') ;
            s.insert(0, 1, ch);
            cout << s << endl;
            continue;
        }

        bool flag = false;//是否连续
        int maxcnt = 1,cnt=1;//最长长度
        int p;//最长长度的指针
        for (int j = 1; j < len;j++){
            if(s[j-1]==s[j]){//相同则累计长度
                flag = true;
                cnt++;
                if(j==len-1){//边缘问题
                    if(cnt>maxcnt){
                    maxcnt = cnt;
                    p = j;
                    }
                }
            }
            else {
                if(cnt>maxcnt){//不同则记录最长长度
                    maxcnt = cnt;
                    p = j - 1;
                }
                cnt = 0;
            }
        }

        char x = s[p];//最长长度的最后一位
        char ch= char(((int)x + 1-'a') % 26 + 'a') ;
        s.insert(p, 1, ch);
        cout << s << endl;
    }
    return 0;
}
