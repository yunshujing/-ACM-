#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

struct time1{
    int x;
    int y;
} bs[N];

bool cmp(time1 a, time1 b){
    return a.y < b.y;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);//关闭同步流

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> bs[i].x >> bs[i].y;
    }

    sort(bs, bs + n,cmp);
    int cnt=0;int last = -1;
    for (int i = 0; i < n;i++){
        if(last<=bs[i].x){
            cnt++;
            last = max(last, bs[i].y);
        }
    }
    cout << cnt << endl;
    return 0;
}