#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;

void cmp(int i);

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int s;
    cin >> s;
    int x = 0, y = 1;
    int len = s.size();
    int g = 0, r = 0;
    int max = 0, sum = 0;
    while(len--){
        y = x + ken - 1;

        if(g==r){
            sum = g * 2;
            break;
            /* if(max<sum)
                max = sum; */
        }
    }

    return 0;
}

void cmp(int i)
{
    if (s[i] = "G")
        sum++;
    else
        sum--;
}