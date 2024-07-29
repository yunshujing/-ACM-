#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct nongmin{
	int x;
	int y;
	double pj;
}jb[N];

int cmp(nongmin a,nongmin b){
	return a.x<b.x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	int n,t;
	cin>>n>>t;//总量，个数

	for(int i=0;i<t;i++){
		cin>>jb[i].x>>jb[i].y;//x为单价y为数量
		
	}

	sort(jb,jb+t,cmp);//根据单价从小到大采购

	double sum=0;
	for(int i=0;i<n;i++){
        if(n>=jb[i].y){
            sum += jb[i].x * jb[i].y;
            n-=jb[i].y;
		}
		else if(n>0){
            sum += (n)*jb[i].x;
            break;
        }
	}
	cout<<fixed<<setprecision(0)<<sum;
    return 0;
}