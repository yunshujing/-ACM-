// // 
// // /*
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// #define N 1e6+10

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

    

//     return 0;
// }
// // */


// A
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
    int sum = 0;
    int flag = 0;
    bool f = true;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s=="salty"){
            flag = 0;
        }
        if(s=="sweet"){
            if(flag==0)
                {
                    sum++;
                    flag = 1;
                }
            else if(i!=n-1){
                f = false;
            }
        }
    }
    if(f){
        cout << "Yes";
    }
    else cout << "No";

    return 0;
}
*/




// B
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

    int h, w, si, sj;
    string s;
    char c[1000][1000];
    cin >> h >> w;
    cin >> si >> sj;
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++){
            cin >> c[i][j];
        }
    }
    cin >> s;
    si -= 1;
    sj -= 1;
    for (char x : s)
    {
        if(x=='L'&&c[si][sj-1]=='.')
            sj--;
        if(x=='R'&&c[si][sj+1]=='.')
            sj++;
        if(x=='U'&&c[si-1][sj]=='.')
            si--;
        if(x=='D'&&c[si+1][sj]=='.')
            si++;
    }
    si += 1;
    sj += 1;
    cout << si << " " << sj;
    return 0;
}
*/


// C
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1e6+10

bool cmp(int e1, int e2) {
	return e1 > e2;
}
int a[200001], b[200001];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    sort(a + 0, a + n, cmp);
	sort(b + 0, b + n, cmp);
    int ca = 0, cb = 0;
    int sa = 0, sb = 0;
	for (int i = 0; i < N; i++) {
		sa += a[i];
        ca++;
        if (sa > x) {
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		sb += b[i];
        cb++;
        if (sb > y) {
			break;
		}
	}

	if (ca >= cb) {
		cout << cb;
	}
	else {
		cout << ca;
	}
    return 0;
}
// */
/*
#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;
//#define ll long long
#define int long long

int A[200001];
int B[200001];

bool cmp(int e1, int e2) {
	return e1 > e2;
}

signed main() {//空 .  非空 #
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, X, Y; cin >> N >> X >> Y;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int j = 0; j < N; j++) {
		cin >> B[j];
	}
	sort(A + 0, A + N, cmp);
	sort(B + 0, B + N, cmp);
	int cnta = 0, cntb = 0;
	int suma = 0, sumb = 0;
	for (int i = 0; i < N; i++) {
		cnta++;
		suma += A[i];
		if (suma > X) {
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		cntb++;
		sumb += B[i];
		if (sumb > Y) {
			break;
		}
	}

	if (cnta >= cntb) {
		cout << cntb;
	}
	else {
		cout << cnta;
	}
	return 0;
}
*/




// D
// /*
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

    

    return 0;
}
// */
#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <cmath>  
  
using namespace std;  
  
int main() {  
    int N, Q;  
    cin >> N >> Q;  
  
    vector<int> a(N);  
    for (int i = 0; i < N; ++i) {  
        cin >> a[i];  
    }  
  
    while (Q--) {  
        int bj, kj;  
        cin >> bj >> kj;  
  
        vector<long long> distances(N); // 使用 long long 以防溢出  
        for (int i = 0; i < N; ++i) {  
            distances[i] = abs(static_cast<long long>(a[i]) - bj);  
        }  
  
        sort(distances.begin(), distances.end()); // 对距离进行排序  
  
        // 注意：索引是从0开始的，但题目中的k_j是从1开始的，所以我们需要-1  
        cout << distances[kj - 1] << endl;  
    }  
  
    return 0;  
}