#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int w, b;
    cin >> w >> b;

    string s = "wbwbwwbwbwbw";

    for (int i = 0; i < 12; i++) {
        int numw = 0, numb = 0;//w的数量，b的数量
        //以i，j为双指针，j移动w+b的长度；
        for (int j = 0; j < w + b; j++) {
            if (s[(i + j) % 12] == 'w') numw++;
            else numb++;
        }
        //ij子集若满足条件则yes
        if (w == numw and b == numb) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
