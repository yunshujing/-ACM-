#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
char a[N];
//vector <int> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int num = 0;
    do{
        bool flag = 0;//判断整体有没有回文
        for (int i = 0; i < n;i++){//检查字符串中是否有回文
            bool flog = 1;//判断这个片段有没有回文
            for (int j = i,v=j+k-1; j <= v; j++,v--)//双指针
            {
                if(a[j]!=a[v])
                    {flog = 0;
                        break;
                    }
            }
            if(flog){
                flag = 1;
                break;
            }
        }
        if(!flag)num++;
    } while (next_permutation(a, a+n));
    cout << num << endl;
    return 0;
}
