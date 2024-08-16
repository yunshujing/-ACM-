// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// #define fi first
// #define se second
// #define mod3 998244353
// #define mod7 1000000007
// const int N = 1e6 + 10;
// const double eps =1e-4;
// int p[10000][2];
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);

//     int n, q;
//     cin >> n >> q;
//     int s[n] = {0};
//     for (int i = 0; i < q; i++)
//     {
//         cin >> p[i][0] >> p[i][1];
//     }
    

//     return 0;
// }
#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
const int MOD = 998244353;  
  
int N, Q;  
vector<int> P, V;  
  
// 假设我们有一个函数来检查某个操作是否会导致哭泣  
// 这里我们简化处理，不直接实现，因为完整的实现会依赖于如何跟踪区间最大值  
bool canPerformOperation(int opIdx, const vector<int>& prefixMax, const vector<int>& suffixMax) {  
    // 假设prefixMax和suffixMax已经通过某种方式被计算出来了  
    // 这里我们只是模拟检查过程  
    // 注意：在实际实现中，你需要根据prefixMax和suffixMax来真正检查是否会导致哭泣  
    // 例如，检查V[opIdx]是否大于prefixMax[P[opIdx] - 1]（如果存在的话）和suffixMax[P[opIdx] + 1]（如果存在的话）  
    // 但由于我们没有实际计算这些值，这里只是返回一个固定的true或false作为示例  
    // 实际上，你需要根据问题的具体逻辑来实现这个函数  
    return true; // 假设总是可以执行操作（这只是一个示例）  
}  

int countValidSequences() {  

    return 1;
int main() {  
    cin >> N >> Q;  
    P.resize(Q);  
    V.resize(Q);  
    for (int i = 0; i < Q; ++i) {  
        cin >> P[i] >> V[i];  
    }  
  
    // 调用函数来计算有效的操作序列数量  
    int result = countValidSequences();  
    cout << result << endl;  
  
    return 0;  
}