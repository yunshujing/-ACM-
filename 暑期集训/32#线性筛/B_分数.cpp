#include<bits/stdc++.h>
using namespace std;
const int n=2e6;
int p[n+5];
int v[n+5];
int ans[n+5];
int k=0;
void Euler_sieve(int n){
	for(int i=0;i<=n;i++){
		v[i]=0;
	}
	for(int i=2;i<=n;i++){
		if(v[i]==0) p[k++]=i;
		for(int j=0;j<k;j++){
			if(i*p[j]>n) break;
			v[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
void init(){
	int now=0;
	for(int i=1;i<=n;i++){
		if(!v[i]) now=i;
		ans[i]=now;
	}
}
int main()
{
	int t;
	cin>>t;
	Euler_sieve(n);
	init();
	while(t--){
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
}