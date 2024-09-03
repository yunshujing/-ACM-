#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e8;
int prime[N + 5]; // 存放所有素数，下标从0开始
int vit[N + 5];   // 是否被筛掉
int k = 0;        // 统计素数个数

/* // 埃氏筛
void E_sieve(int n){
    // 初始化
    k = 0;
    for (int i = 0; i <= n; i++){
        vit[i] = 0;
    }
    //
    for (int i = 2; i * i <= n; i++){
        if (vit[i] == 0){
            for (int j = i * i; j <= n; j += i){
                vit[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (vit[i] == 0){
            prime[k++] = i;
        }
    }
}
 */
// 欧拉筛 O(n)
// 让每一个数只被自己最小的质因子筛掉
void E_sieve(int n){
    // 初始化
    k = 0;
    for (int i = 0; i <= n; i++){
        vit[i] = 0;
    }
    // 做筛子的数 每一个数
    for (int i = 2; i <= n; i++){
        // 是素数直接存入
        if (vit[i] == 0){
            prime[k++] = i;
        }
        // 枚举的倍数乘已经有的素数，这个素数要作为最质因子
        for (int j = 0; j < k; j++){
            // 超过n退出
            if (i * prime[j] > n){
                break;
            }
            vit[i * prime[j]] = 1; // 合数筛掉
            // 倍数里有小的质因子，后面更大的质因子就不用看了
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    E_sieve(n);
    while (q--)
    {
        int x;
        cin >> x;
        cout << prime[x - 1] << endl;
    }
}