#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int nums=1;
		b[0]=a[0];
		for(int i=1;i<n;i++){
			if(a[i]>b[nums-1]) b[nums++]=a[i];
			else{
				for(int j=0;j<nums;j++){
					if(b[j]>a[i]){
						b[j]=a[i];
						break;
					}
				}
			}
		}
		cout << nums<<endl;
}