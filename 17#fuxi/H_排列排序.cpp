#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int a[maxn];
signed main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int i=1;
		int ans=0;
		while(i<=n){//所有数1对1对应且连续
			if(a[i]==i) i++;//数字在原来该在的位置
			else{//没有在原来位置，则开始记录区间
            //找到乱序中最大的数，因为要排到他原来位置，所有长度即为就要排序的长度
				int maxx=a[i];
				int j=i+1;
				maxx=max(maxx,a[j]);
				while(maxx>j){
					j++;
					maxx=max(maxx,a[j]);
				}
				ans+=j-i+1;
				i=j+1;//更新区间
			}
		}
		cout<<ans<<endl;
	}
}