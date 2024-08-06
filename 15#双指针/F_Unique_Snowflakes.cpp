#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> h;

    while(n--){
        int m;
        cin >> m;
        int a[N];
        for (int i = 0; i < m;i++){
            cin >> a[i];
        }





    }

    return 0;
}
















#include <iostream>  
#include <unordered_set>  
  
using namespace std;  
  
int main() {  
    int numTestCases;  
    cin >> numTestCases;  
  
    while (numTestCases--) {  
        int n;  
        cin >> n;  
  
        unordered_set<int> uniqueSnowflakes;  
        int maxUnique = 0;  
  
        for (int i = 0; i < n; ++i) {  
            int snowflakeId;  
            cin >> snowflakeId;  
  
            if (uniqueSnowflakes.insert(snowflakeId).second) {  
                maxUnique = max(maxUnique, static_cast<int>(uniqueSnowflakes.size()));  
            }  
        }  
  
        cout << maxUnique << endl;  
  
        uniqueSnowflakes.clear();  
    }  
  
    return 0;  
}