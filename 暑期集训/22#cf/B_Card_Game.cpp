#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
//int a[N];
//vector <int> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int cnt = 0;
        if(a1>b1&&a2>b2){
            cnt++;}
        else if(a1==b1&&a2>b2){
			cnt++;
		}
		else if(a1>b1&&a2==b2){
			cnt++;
		}
		if(a1>b2&&a2>b1){
			cnt++;
		}
		else if(a1==b2&&a2>b1){
			cnt++;
		}
		else if(a1>b2&&a2==b1){
			cnt++;
		}
		cout<<cnt*2<<endl;
    }

        return 0;
}
