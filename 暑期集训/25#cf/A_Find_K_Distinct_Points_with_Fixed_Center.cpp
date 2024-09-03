#include <iostream>  
  
using namespace std;  
  
int main() {  
    int t;  
    cin >> t;
  
    while (t--) {  
        int xc, yc, k;  
        cin >> xc >> yc >> k; 
  
        int step = 1;   
        int point = 0; 
        for (int i = 0; points < k - (k % 2); ++i) { // 如果k是奇数，则循环到k-1  
    cout << xc + step << " " << yc << endl;  
    cout << xc - step << " " << yc << endl;  
    points += 2;  
    step++;  
}  
  
// 如果k是奇数，打印中心点  
if (k % 2 != 0) {  
    cout << xc << " " << yc << endl;  
} 
    }  
  
    return 0;  
} 