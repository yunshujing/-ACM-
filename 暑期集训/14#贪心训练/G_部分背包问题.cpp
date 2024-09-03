#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct gold{
    int x;
    int y;
    double pj;
}jb[N];

int cmp(gold a,gold b){
    return a.pj>b.pj;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin>>n>>t;

    for(int i=0;i<n;i++){
        cin>>jb[i].x>>jb[i].y;
        jb[i].pj=(double)jb[i].y/(double)jb[i].x;
    }

    sort(jb,jb+n,cmp);

    double sum=0;
    for(int i=0;i<n;i++){
        if(t>=jb[i].x){
            sum+=jb[i].y;
            t-=jb[i].x;
        }
        else if(t>0){
            sum+=(t)*jb[i].pj;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<sum;
    return 0;
}