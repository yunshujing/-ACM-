#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n,l=1;
    char a[729][730];
    for(int i=0;i<729;i++)for(int j=0;j<730;j++)a[i][j]=0;

    cin>>n;
    a[0][0]='#';
    for(int k=0;k<n;k++){
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if((x==0)&&(y==0))continue;
                if((x==1)&&(y==1)){
                    for(int i=0;i<l;i++)for(int j=0;j<l;j++)a[x*l+i][y*l+j]='.';
                }
                else{
                    for(int i=0;i<l;i++){
                        for(int j=0;j<l;j++){
                            a[x*l+i][y*l+j]=a[i][j];
                        }
                    }
                }
            }
        }
        l*=3;
    }

    for(int i=0;i<l;i++)cout<<a[i]<<endl;

    return 0;
}
