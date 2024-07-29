#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5+10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    int a[N];int sum = 0;//总共要吃的糖
    cin >> a[0];//否则最后一个算不到！！！
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];//糖果列表
        if (a[i] + a[i - 1] > x)
        {
            int cnt = a[i] + a[i - 1] - x;//要吃的量
            if(cnt>a[i]){//如果后者不够
                a[i-1] = cnt - a[i];//前者吃掉剩余的糖
                a[i] = 0;//后者清空
            }
            else{
                a[i] -= cnt;
            }
            sum += cnt;
        }
    }

    cout << sum << endl;
    return 0;
}
