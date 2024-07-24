#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

void solve();

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); // 关闭同步流

    int n;
    cin >> n;
    while (n--){
        solve();
    }
    return 0;
}

void solve(){
    int m;
    cin>>m;
    if(m==1){
        cout<<"0"<<endl;return;
    }
    string k;
    map <string,int> map;
    while(m--){
        cin>>k;
        map[k]++;
    }
    string name; int max_num = 0; int sum_num = 0;
    for (auto x : map) {
        sum_num += x.second;//累计总数
        if (x.second > max_num) {//找最大数和其键
            max_num = x.second; 
            name = x.first;
        }
    }
    int cnt = 0;//操作次数
		while (max_num < sum_num) {//查杀
			cnt++; //fz
            cnt += max_num;
			max_num *= 2;
		}
		cnt -= (max_num - sum_num);//操作数-超出数
    cout<<cnt<<endl;return;
}