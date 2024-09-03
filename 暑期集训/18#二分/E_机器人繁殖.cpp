#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    return 0;
}


//python
def f(z, n):  
    if z == 1:  
        return n + n * 2 - 1  
    return f(z - 1, 2 * n - 1) + n  
  
def main():  
    import sys  
    input = sys.stdin.read  
    data = input().split()  
    n = int(data[0])  
    s = int(data[1])  
      
    l = 0  
    r = 100  
    while l < r:  
        m = (l + r) // 2  
        if f(n, m) >= s:  
            r = m  
        else:  
            l = m + 1  
      
    print(l)  
  
if __name__ == "__main__":  
    main()