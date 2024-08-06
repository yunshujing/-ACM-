#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct apple{
    int high;
    int power;
}ap[N];

int cmp(apple a,apple b){
    return a.power<b.power;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    int n,s;//苹果数，力气
    cin>>n>>s;

    int a,b;//椅子高度，手臂长
    cin>>a>>b;

    for(int i=1;i<=n;i++){
        cin>>ap[i].high>>ap[i].power;
    }

    sort(ap+1,ap+n+1,cmp);//对苹果按照力气从小到大排序

    //摘苹果
    int ans=0;
    for(int i=1;i<=n;i++){
        //判断高度是否足够
        if(ap[i].high>a+b){//超出高度
            continue;
        }
        else if(s>=ap[i].power){
            s-=ap[i].power;
            ans++;
        }
    }
    cout << ans<<endl;
    return 0;
}