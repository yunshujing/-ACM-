#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        int i = 0, j = s.size() - 1;
        bool flag = true;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                flag = false;
            }
            i++;
            j--;
        }
        if(flag)
        cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}