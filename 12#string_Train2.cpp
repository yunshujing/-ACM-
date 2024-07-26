// A
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    string n;
    while (getline(cin, n))
    {
        string a = "`1234567890-=";
        string b = "QWERTYUIOP[]\\";
        string c = "ASDFGHJKL;'";
        string d = "ZXCVBNM,./";
        for (char k : n)
        {
            if (k == ' ')
            {
                cout << ' ';
                continue;
            }
            for (int i = 0; i < (int)a.size(); i++)
            {
                if (a[i] == k)
                {
                    cout << (i > 0 ? a[i - 1] : a[i]);
                    continue;
                }
            }
            for (int i = 0; i < (int)b.size(); i++)
            {
                if (b[i] == k)
                {
                    cout << (i > 0 ? b[i - 1] : b[i]);
                    continue;
                }
            }
            for (int i = 0; i < (int)c.size(); i++)
            {
                if (c[i] == k)
                {
                    cout << (i > 0 ? c[i - 1] : c[i]);
                    continue;
                }
            }
            for (int i = 0; i < (int)d.size(); i++)
            {
                if (d[i] == k)
                {
                    cout << (i > 0 ? d[i - 1] : d[i]);
                    continue;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
*/


// D
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
    while(n--){
        int x;
        cin >> x;
        for (int i = 0; i < 10; i++)
        {
            for
        }
        
    }

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
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        int cnt = 0;
        int sum = 0;
        for(char x:s){
            if(x=='O')
                {cnt++;
            sum += cnt;}
            if(x=='X'){
                cnt = 0;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
*/


// F
// /*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{





    return 0;
}

// */

// G
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
    while(n--){
        int m;
        map<char, int> mp;
        cin >> m;
        string sum;
        for (int i=1; i <= m;i++){
            string x = to_string(i);
            sum =sum+x;
        }
        for(char p:sum){
            int x = p - '0';
            mp[x]++;
        }
        for (int i = 0; i < 9;i++){
            // char u = i;
            cout<<mp[i]<<" ";
        }
        cout << mp[9] << endl;//最后一个不要空格！！！！
    }
    return 0;
}
*/

// I
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    string n,m;
    while(cin>>n>>m){
        int x = n.size(),p=m.size();
        int flag = 0;
        for (int i = 0; i <p;i++){
            if(m[i]==n[flag]){
                flag++;
            }
            if(flag==x){
            cout << "Yes" << endl;
            break;
            }
        }
        if(flag!=x)
            cout << "No" << endl;
    }
    return 0;
}
*/