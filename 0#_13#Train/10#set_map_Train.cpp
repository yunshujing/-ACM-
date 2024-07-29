// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// const int N = 1e6 + 10;
// void solve();
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);
// 
//     return 0;
// }
// 
// void solve(){
// 
// }



// A
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
void solve();
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    string s;
    while(n--){
        solve();
    }
    return 0;
}

void solve(){
    int m;
    cin>>m;
    string s;
    cin>>s;
    if(m!=5){
        cout <<"NO"<<endl;
        return ;
    }
    mp<char,int> mp;
    for(char x:s){
        mp[x]++;
    }
    if(!mp['T']||!mp['i']||!mp['m']||!mp['u']||!mp['r']){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    return;
}
*/

// B
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
void solve();
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    string s;
    while(n--){
        solve();
    }
    return 0;
}

void solve(){
    int m;
    cin>>m;
    string s;
    cin>>s;
    if(s=="1"){
        cout<<"YES"<<endl;return;
    }
    if(s=="0"){
        cout<<"NO"<<endl;return;
    }
    mp <char,int> mp;
    for(char x:s){
        mp[x]++;
    }
    s=s+"1";
    int cnt=0;
    for(char& x:s){
        if(x=='0'){
            cnt++;
        }
        if(x=='1'){
            cnt--;
            if(cnt>0)
            {
            mp['0']=mp['0']-cnt;
            cnt=0;}
            else cnt=0;
        }
    }
    if(mp['1']>mp['0']){
        cout<<"YES"<<endl;return;
    }
    else{
         cout<<"NO"<<endl;return;
    }
}
*/



// C
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); // 关闭同步流

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        int m;
        cin >> m;
        
        map<string, int> mp;
        for (int i = 0; i < m; i++)
        {
            string k;
            cin >> k;
            mp[k]++;
        }
        string name;
        int max_num = 0;
        int sum_num = 0;
        for (auto x : mp)
        {
            sum_num += x.second; // 累计总数
            if (x.second > max_num)
            { // 找最大数和其键
                max_num = x.second;
                name = x.first;
            }
        }
        int cnt = 0; // 操作次数
        while (max_num < sum_num)
        {          // 查杀
            cnt++; // fz
            cnt += max_num;
            max_num *= 2;
        }
        cnt -= (max_num - sum_num); // 操作数-超出数
        cout << cnt << endl;
    }
    return 0;
}
*/

// D
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
void solve();
signed main(){
	int t; cin >> t; getchar();
	for (int i = 0; i < t; i++) {
		stack<char> s;
		char tmp;
		int num_0 = 0;
		int chenben = 0;

		while (~scanf("%c", &tmp) && tmp != '\n') {
			if (tmp == '1') {
				s.push(tmp);
			}
			else if (tmp == '0' && s.size() == 0) {
				num_0++;
			}
			else {
				chenben += s.size()+1;
				num_0++;
			}
		}
		cout << chenben << "\n";
	}
	return 0;
}
*/



// E
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
void solve();
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}

void solve(){
    string m;
    cin >> m;
    if(m=='1'||m=='0'){
        cout<<m<<endl;
        return;
    }
    //计算四舍五入的最大值
    queue<char> s;
    for(char x:m){
        
    }

}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int x1 = 0;
    while (t--) {
        string s1,s2;
        cin >> s1;
        int count = 0;
        for (int i = s1.size() - 1; i >= 0; i--) {
            int x = (int)(s1[i]) - 48;
            if (x1 == 1) {
                x += 1;
                x1 = 0;
            }
            if (x >= 5) {
                if (i == 0) {
                    s2 = '1';
                    count = s1.size();
                }
                else{
                    s2 = '0';
                    count = s1.size() - i - 1;
                    x1 = 1;
                }
            }
            else {
                s2 = to_string(x) + s2;
            }
        }
        for (int i = 0; i < count; i++) {
            s2 = s2 + '0';
        }
        cout << s2 << "\n";
        x1 = 0;
    }
    return 0;
}