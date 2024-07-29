// A
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10
*/
/*
#include<iostream>
using namespace std;
int a[14];
int bushu(int x){//步数
	int remain,p;
	if(a[x]) return a[x];//
	for(int i=x+1;;i++){//找步数
		for( p=0,remain=2*x;remain>x;remain--){
			p = (p + i - 1) % remain;//循环//杀人
			if(p<x) remain=0; //不杀好人
		}//找到就退出（最小步数)
		if(remain==x){//只剩下好人
			a[x]=i;
			return i;
        }
    }
        return 0;
}
int main()
{
	int k;
	while(scanf("%d",&k)==1) {
		if(k==0) break;
		else printf("%d\n",bushu(k));
	}
	return 0;
}
*/



// B

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

int f(int a, int b, int n);
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, n;
    while(cin>>a>>b>>n && !(a==0&&b==0&&n==0)){
        cout << f(a, b, n) << endl;
    }
    return 0;
}

int f(int a,int b,int n){
    if(n==1||n==2)
        return 1;
    else
        return (a * f(a, b, n - 1) + b * f(a, b, n - 2)) % 7;
}







// C
/*
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main(){
    while (scanf("%d", &n) != EOF){
        if(n % 8 == 2 || n % 8 == 6)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl; 
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        int x = m % 10;//
        if (x == 5 || x == 6){
            cout << x << endl;
            continue;
            }
        int sum=x;
        for (int i = 0; i < (m-1)%4;i++){
            sum *= x;
        }
            cout << sum%10  << endl;
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;

        double sum=0.00,x;
        for(int i=1;i<=m;i++){
            x = (1.00 / i);
            if (i%2==1)
            {
                sum += x;
            }
            if (i%2==0)
            {
                sum -= x;
            }
        }
        cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}
*/


// G
/*
#include<bits/stdc++.h>
using namespace std;
// #define int long long;
#define endl "\n"
#define N 1e6+10

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s;
    int n;
    while (cin >> s >> n && !(s == 0 && n == 0)){
        s *= 100;
        bool flag = false;
        for (int x = 0; x < 100;x++)
            if ((s + x) % n == 0){
                
                if (flag) cout << " "; // 如果不是第一个满足条件的 x，则输出空格  
                cout << (x < 10 ? "0" : "") << x; // 如果 x 是个位数，则前面补 0 
                flag = true;
            }
        if (!flag) {  
            cout << "00"; // 如果没有找到满足条件的 x，则输出 00  
        }  
        cout << endl;
    }
    return 0;
}
*/