//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 1e6 + 10;
// 
//for (int i = 0; i < n; i++){}
//scanf("%d", &n);
//printf("%d", n);
// 结构体
//struct Student {
//    int x;
//    string name;
//    char zy;
//    int sld;
//};

//A
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1e5 + 10
signed main(){
	int n, k;
	cin >> n >> k;
	set <int> s;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		s.insert(m);
	}
	if (s.size() < k)
		cout << "NO RESULT" << endl;
	else
	{
		int y = 0;
		for (auto x : s)
		{
			if (s.count(x))
			{
				y++;
			}
			if (y == k)
				cout << x << endl;
		}
	}
	return 0;
}
*/


// B


// C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define N 1e5 + 10
// signed main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);cout.tie(nullptr);

// 	string s;
// 	set <string> st;
// 	while (cin>>s)
// 	{
// 		queue<char> q;
		
// 		for (char n : s)
// 		{
// 			if (n >= 'a' && n <= 'z'){ // 入队列
// 				q.push(n);
// 			}
// 			if (n == ' '){ // 整合
// 				string sum;
// 				while (!q.empty())
// 				{
// 					sum = sum + q.front();
// 					q.pop();
// 				}
// 				st.insert(sum);
// 			}
// 		}
// 		cout << st.size()+1 << endl;
// 	}
// 	return 0;
// }











//D
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1e5 + 10
signed main(){
	string s;
	while (getline(cin, s) && s != "#")
	{
		queue<char> q;
		set <string> st;
		s=s+' ';
		for (char n : s)
		{
			if (n >= 'a' && n <= 'z'){ // 入队列
				q.push(n);
			}
			if (n == ' '){ // 整合
				string sum;
				while (!q.empty())
				{
					sum = sum + q.front();
					q.pop();
				}
				st.insert(sum);
			}
		}
		cout << st.size() << endl;
	}
	return 0;
}
*/

//E
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1e5 + 10
signed main()
{
	int n;
	cin >> n;
	map <string, int> myMap;
	while (n--){
		int cz, cj;
		string name;
		cin>>cz;
		if (cz == 1){
			cin>>name>>cj;
			myMap[name] = cj;
			cout << "OK" << endl;
		}
		if (cz == 2){
			cin>>name;
			auto it = myMap.find(name); // 验证键更安全
			if (it != myMap.end())
			{
				int value = it->second; // 访问找到的元素的值
				cout << value << endl;
			} // `myMap.first`为键，`myMap.second`为值
			else
			{
				cout << "Not found" << endl;
			}
		}
		if (cz == 3){
			cin>>name;
			auto it = myMap.find(name);
			if (it != myMap.end())
			{
				myMap.erase(it);
				cout << "Deleted successfully" << endl;
			} // 验证键更安全
			else
			{
				cout << "Not found" << endl;
			}
		}
		if (cz == 4){
			int tmp=myMap.size();
			cout << tmp <<endl;
		}
	}
	return 0;
}
*/


// F
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define N 1e6 + 10
const long long inf=0x3f3f3f3f3f3f3f3f;
int v[1010][1010]={0};
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		int ta = ((a[0] - 'A') * 26) + a[1] - 'A'; // city2
		int tb = ((b[0] - 'A') * 26) + b[1] - 'A'; // state
		ans += v[tb][ta];	//[state,city2]存在的数
		if (ta == tb)	 // 自检
		{
			ans -= v[ta][tb];
		}
		v[ta][tb]++; //[city2,state]存在则加一
	}
	cout<<ans;
	return 0;
}

// 不知道为啥错
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define N 1e6 + 10

signed main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	unordered_map<string, string> map;
	
	while (n--)
	{
		string fi, se;
		cin >> fi >> se;
		string tmp = fi.substr(0, 2); 
		map[tmp] = se;
	}
	int cnt = 0;
	for (auto x : map)
	{
		auto it = map.find(x.se);
		if (it != map.end() )
		{
			string value = it->second;
			if(value == x.fi){
				cnt++;
			}
		}
	}
	cout << cnt/2 << endl;
	return 0;
}

// ai生成
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 存储城市名前两个字母对应的所有州代码
    map<string, set<string>> prefix_to_states;
    // 存储每个州代码对应的城市名前两个字母
    map<string, set<string>> state_to_prefixes;
    // 存储城市和州的列表
    vector<pair<string, string>> city_state_list;

    for (int i = 0; i < n; ++i) {
        string city, state;
        cin >> city >> state;
        string prefix = city.substr(0, 2);
        prefix_to_states[prefix].insert(state);
        state_to_prefixes[state].insert(prefix);
        city_state_list.emplace_back(city, state);
    }

    int special_city_count = 0;

    // 遍历城市和州的列表
    for (const auto& [city, state] : city_state_list) {
        string prefix = city.substr(0, 2);
        // 检查当前城市名前两个字母对应的州代码集合
        auto it = state_to_prefixes.find(prefix);
        if (it != state_to_prefixes.end()) {
            for (const auto& pfx : it->second) {
                if (pfx != prefix) {
                    special_city_count++;
                    break;
                }
            }
        }
    }

    cout << special_city_count << endl;

    return 0;
}
*/








// H
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1e5 + 10
signed main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		set<int> st;
		int n, m;
		cin >> n >> m;
		int nm=n+m,k;
		while (nm--)
		{
			cin >> k;
			st.insert(k);
		}
		
		//double xsdd = (cnt * 1.000 / (st1.size() + st2.size() - cnt) * 1.000);
		int xsd = (m+n-st.size()) * 100/st.size();
		// if (n + m - cnt == 0) xsd = 100.0;  
		printf("%lld\n", xsd);
	}
	return 0;
}
*/
