//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 1e6 + 10;
// 
//for (int i = 0; i < n; i++){}
//scanf("%d", &n);
//printf("%d", n);
// 结构体
//struct Student {
//    int x;
//    string name;
//    char zy;
//    int sld;
//};



//A
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <char> fh;
stack <int> num;
int sum(int n1, int n2, char x);
queue<char> s;
signed main() {
    string a; int cnt = 0;
    cin >> a;
    for (char n : a) {
        if (n == '@') break;
        //先对字符串处理入栈
        if (n >= '0' && n <= '9') {//如果是数据
            s.push(n);
        }
        else {//如果是符号
            if (n == '.') {//整合
                int sum = 0;
                while (!s.empty()) {
                    sum = sum * 10 + (int)s.front() - '0';
                    s.pop();
                }
                num.push(sum);
            }
            else{//计算
                int n2 = num.top();
                num.pop();
                int n1 = num.top();
                num.pop();
                int x2 = sum(n1, n2, n);
                num.push(x2);
            }
        }
    }
    cout << num.top();
    return 0;
}

int sum(int n1, int n2, char x) {
    if (x == '+')return n1 + n2;
    if (x == '-')return n1 - n2;
    if (x == '*')return n1 * n2;
    if (x == '/')
        if (n1 >= n2)return n1 / n2; 
        else return 0;
}
*/


//B
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
//priority_queue<char, vector<char>, greater<char>> fh;
stack <int> num;
//int sum(int n1, int n2, char x);
signed main() {
    string a; int cnt = 0; int flag = 1;
    cin >> a;
    for (char x: a) {
        if (x != '@') {
            if (x == '(')num.push(x);
            if (x == ')') {
                if (!num.empty())num.pop();
                else { flag = 0; break;  }
            }
        }
        else break;
    }
    if (num.empty()&&flag==1)cout << "YES";
    else cout << "NO";
}
*/


//C
/*
//简单计算机变形
#include<bits/stdc++.h>
using namespace std;
#define llu long long

int level(char e) {
    if (e == '*')    return 2;
    else if (e == '+')    return 1;
    else    return 0;//
}

int main() {
    stack<int> number; stack<char> symbol;
    llu x1; scanf("%lld", &x1);
    x1 = x1 % 10000;
    number.push(x1);
    char tmp;
    int flag = 0;
    while (~scanf("%c", &tmp) && tmp != '\n') {
        llu TMP; scanf("%lld", &TMP); TMP = TMP % 10000;
        flag = level(tmp);
        if (flag == 2) {
            llu X = number.top(); number.pop();
            X *= TMP;
            X = X % 10000;
            number.push(X);
            flag = 0;
        }
        else {
            symbol.push(tmp);
            number.push(TMP);
        }
    }
    while (!symbol.empty()) {
        char c = symbol.top(); symbol.pop();
        llu a = number.top(); number.pop();
        llu b = number.top(); number.pop();
        llu X = (a + b) % 10000;
        number.push(X);
    }
    llu out = number.top() % 10000;
    printf("%lld", out);
    return 0;
}
*/


//D
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, m;
    int tmp;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n * n; i++)
    {
        q.push(1);
    }
    while (!q.empty())
    {
        tmp++;
        if (tmp % m != 0)
        {
            q.push(q.front());
            q.pop();
        }
        else
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
    return 0;
}
*/


//E
/*
#include<bits/stdc++.h>
#include<limits.h>
#define endl '\n'
#define i64 long long
#define fi first
#define se second
#define Endl endl
#define END endl
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;
int main()
{
    vector<int> a;
    int n, m;
    while (cin >> n >> m)
    {
        a.clear();
        a.resize(2 * n);
        iota(a.begin(), a.end(), 0);
        int sum = a.size(), x = 0;
        for (int i = 0; i < n; i++)
        {
            sum = a.size();
            x = (x + m - 1) % sum;
            // de(x)
            a.erase(a.begin() + x);
        }
        int cnt = 0;
        sum = a.size();
        for (int i = 0; i < 2 * n; i++)
        {
            if (cnt < sum && a[cnt] == i)
            {
                cout << "G";
                cnt++;
            }
            else
            {
                cout << "B";
            }
        }
        cout << endl;
    }
    return 0;
}
*/


//F
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> s;
    while (n--)
    {
        int m;
        scanf("%d", &m);
        if (m == 1)
        {
            int k;
            scanf("%lld", &k);
            s.push(k);
        }
        if (m == 2)
        {
            cout << s.top() << endl;
        }
        if (m == 3){
            s.pop();
        }
    }
    return 0;
}
*/


//G
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
#define ll long long int
int main() {
    int n;
    cin >> n;
    int t;
    priority_queue<int,vector<int>,greater<int> > a;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push(t);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int sum1 = 0;
        sum1 += a.top();
        a.pop();
        sum1 += a.top();
        a.pop();
        sum += sum1;
        a.push(sum1);
    }
    cout << sum;
    return 0;
}
*/


//H
/*
#include <bits/stdc++.h>
#include <limits.h>
#define pb emplace_back()
#define endl '\n'
#define i64 long long
#define fi first
#define se second
#define Endl endl
#define END endl
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x << " " << x << " ";
#define deb(x) cerr << #x << " " << x << endl;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << a[1] << endl;
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    if (a[1] > a[2])
    {
        q1.push(a[2]), q2.push(a[1]);
    }
    else
    {
        q1.push(a[1]), q2.push(a[2]);
    }
    for (int i = 3; i <= n; i++)
    {
        int x = a[i];
        if (x < q1.top())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
        if (i % 2)
        {
            while (llabs(q1.size() - q2.size()) > 1)
            {
                if (q1.size() > q2.size())
                {
                    int tmp = q1.top();
                    q2.push(tmp);
                    q1.pop();
                }
                else
                {
                    int tmp = q2.top();
                    q1.push(tmp);
                    q2.pop();
                }
            }
            cout << ((q1.size() > q2.size()) ? q1.top() : q2.top()) << endl;
        }
    }
    return 0;
}

*/
