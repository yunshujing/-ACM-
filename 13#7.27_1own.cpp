// // 
// // /*
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// #define N 1e6+10

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

    

//     return 0;
// }
// // */


// A
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    bool flag = false;
    for (int i = 2; i * i <= n + 1; ++i) {  
        if ((n + 1) % i == 0) {  
            int j = (n + 1) / i; 
            if (i > 1 && j > 1) {
                flag = true;
            }
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
*/


// B
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e9+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int a, b, sum = 0,time=0,s=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        time =time + a + b * k;//时间点
        s= b * 20;//罚时
        sum += (time + s);
    }
    cout << sum << endl;

    return 0;
}
*/


// C
// /*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    

    return 0;
}
// */


// D
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e9+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<int, int,greater<int>> mp;
    for (int i = 0; i < n; i++) {
		mp[i] = 0;
	}
    for (int i = 0; i < m;i++)
    {
        int s;
        cin >> s;
        mp[s]++;
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (mp[i]==0)
        {
            cout << i << " ";
            flag = false;
        }
    }
    if (flag)//判断是否齐
        cout << n ;
    return 0;
}
*/


// E
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c;
    cin >> n >> c;
    map<int,int,greater<int>> mp;
    for(int i=0;i<n;i++){
        int s;
        cin >> s;
        mp[s]++;
    }
    int samsun = 0;
    for (const auto &pair1 : mp){
        auto sum = pair1.first - c;
        auto it = mp.find(sum);
        if (it!=mp.end())
        {
            int x = it->second;
            samsun += pair1.second * x;
        }
        
    }
    cout << samsun << endl;
    return 0;
}
*/




// H
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int l=0, s=0;
    for (int i = 1; i <= n; i++){
        l += i;
        s += i * i;
    }
    l = l * 2 + 2 * n;
    cout << l << endl;
    cout << s << endl;

    return 0;
}
*/




