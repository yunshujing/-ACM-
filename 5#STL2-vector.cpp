#define _CRT_SECURE_NO_WARNINGS

//A
// #include<bits/stdc++.h>
// #include<limits.h>
// using namespace std;
// int main() {
// 	vector <int> a;
// 	int n, m; 
// 	while (cin >> n >> m) {
// 		a.clear();
// 		a.resize(2 * n);//重定义大小

// 		iota(a.begin(), a.end(), 0);//遍历重定义0,1,2,3,4....
// 		//for (int i = 0; i < n * 2; i++) {
// 		//	a.push_back(1);
// 		//}//输入
// 		int sum = a.size(), x = 0;

// 		for (int i = 0; i < n; i++) {//多次删除坏人
// 			sum = a.size();//长度
// 			int x = (x + m - 1) % sum;
// 			a.erase(a.begin() + x);//删除坏人
// 		}
// 		int cnt = 0;//
// 		sum = a.size();//剩余好人个数
// 		for (int i = 0; i < n * 2; i++) {
// 			if (cnt < sum && a[cnt] == i) { cout << "G"; cnt++; }
// 			else { cout << "B"; }
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }


//B
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int x; char y;
//	cin >> x; 
//  getchar();//读取回车
//	stack <char> a;
//	int flag = 1;
//	while(x>=1)
//	{	
//		while(flag==1)
//		{
//			while (scanf("%c", &y) && y != ' ') {//cin会跳过空格
//				if (y == '\n') {
//					flag = 0; break;
//				}
//				a.push(y);
//			}//输入
//			//y=' '运行下一行
//			while (!a.empty()) {
//				cout << a.top();
//				a.pop();
//			}//输出
//			if (flag=1) 
//				cout << ' ';
//		}
//		cout << endl;
//		x--;
//	}
//	return 0;
//}



//C
//#include<bits/stdc++.h>
//using namespace std;
//float sum(float k1, float k2, char op);
//int main() {
//	stack<float> num;//数字栈
//	stack<char> op;//符号栈
//	while (1) {
//		float n1;
//		scanf("%f",&n1);
//		num.push(n1);
//		char fh;
//		scanf("%c",&fh);
//		if (fh == '*' || fh == '/') {
//			while (fh == '*' || fh == '/')
//			{
//				float n2;
//				scanf("%f", &n2);
//				n1 = num.top();
//				num.pop();
//				n1 = sum(n1, n2, fh);
//				num.push(n1);//乘除把栈顶提出算完再入栈
//				scanf("%c", &fh);
//				if (fh == '+' || fh == '-') {
//					break; // 如果是加减或等于号，则退出乘除循环
//				}
//			}
//		}
//		if (fh == '+' || fh == '-') {
//			op.push(fh);
//		}
//		else if (fh == '\n') {
//			break; // 退出循环条件
//		}
//	}
//	//乘除已经算完，只要算加减
//	while (!op.empty())
//	{
//		float m1, m2; char fh2;
//		m2= num.top();
//		num.pop();
//		m1 = num.top();
//		num.pop();
//		fh2 = op.top();
//		op.pop();
//		m1 = sum(m1, m2, fh2);
//		num.push(m1);//加减
//	}
//	cout <<fixed << setprecision(2)<< num.top() << endl;
//	return 0;
//}
//
//float sum(float k1, float k2, char op) {//加减乘除
//	if (op == '*') {
//		return k1 * k2;
//	}
//	if (op == '/') {
//		return k1 / k2;
//	}
//	else if (op == '+') {
//		return k1 + k2;
//	}
//	else if (op == '-') {
//		return k1 - k2;
//	}
//}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include<bits/stdc++.h>
//using namespace std;
//int charLevel(char c);
//
//int main() {
//	while (1) {
//		stack<char> symbol; stack<double> number;
//		double x1; scanf("%lf", &x1);
//		number.push(x1);
//		char tmp;
//		int flag = 0;
//		while (~scanf("%c", &tmp) && tmp != '\n') {
//			if (tmp == ' ') {//消化空格
//				scanf("%c", &tmp);
//			}
//			//处理运算符号
//			symbol.push(tmp);
//			if (charLevel(tmp) >= 3) {
//				flag = charLevel(tmp);
//			}
//			scanf("%c", &tmp);//消化符号后一个的空格
//			double TMP; scanf("%lf", &TMP);
//			//
//			if (flag == 4) {// *
//				symbol.pop();
//				double a = number.top(); number.pop();
//				a = TMP * a;
//				number.push(a);
//				flag = 0;
//			}
//			else if (flag == 3) {// /
//				symbol.pop();
//				double a = number.top(); number.pop();
//				a = a / TMP;
//				number.push(a);
//				flag = 0;
//			}
//			else {
//				number.push(TMP);
//			}
//		}
//		//退出
//		if (x1 == 0 && number.size() == 1) {
//			break;
//		}
//		while (!symbol.empty()) {
//			char c = symbol.top(); symbol.pop();
//			flag = charLevel(c);
//			if (flag == 2) {// +
//				double a = number.top(); number.pop();
//				double b = number.top(); number.pop();
//				number.push(a + b);
//				flag = 0;
//			}
//			else {// -
//				double a = number.top(); number.pop();
//				double b = number.top(); number.pop();
//				number.push(b - a);
//				flag = 0;
//			}
//		}
//		printf("%.2lf\n", number.top());
//	}
//	return 0;
//}
//
//int charLevel(char c) {
//	/*if (c == '*' || c == '/') {
//		return 3;
//	}
//	else if (c == '+' || c == '-') {
//		return 2;
//	}
//	else { return 1; }*/
//	if (c == '*') {
//		return 4;
//	}
//	else if (c == '/') {
//		return 3;
//	}
//	else if (c == '+') {
//		return 2;
//	}
//	else if (c == '-') {
//		return 1;
//	}
//	return 0;
//}



//G
//#include<bits/stdc++.h>
//#include<string.h>
//using namespace std;
//char a[6] = { 'h','e','l','l','o' };
//int x=0;
//bool flag = false;
//int main() {
//	string y;
//	cin >> y;
//	int len = y.length();//求长度c++
//	for (int i = 0; i < len; i++) {
//		if (y[i] == a[x]) {
//			x++;
//		}
//	}
//	if (x == 5)flag = true;
//	if (flag)printf("YES");
//	else printf("NO");
//	return 0;
//}


//K
//#include<bits/stdc++.h>
//#include<string.h>
//using namespace std;
//char a[6] = { 'r','g','b' };
//char b[6] = { 'R','G','B' };
//int jnd[3] = { 0 };
//int x = 0;
//int main() {
//	string y; int num;
//	cin >> num;
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
//	while (num-- > 0) {
//		cin >> y;x=0;int jnd[3] = { 0 };
//		for (char c : y) {
//			for (int j = 0; j < 3; j++)
//			{
//				if (c == b[j] && jnd[j] == 1) {
//					x++;
//				}
//				else if (c == a[j]) {
//					jnd[j] = 1;
//				}
//			}
//		}
//		bool flag = false;		//重定义要在下面,不然不重置
//		if (x == 3)flag = true;
//		if (flag)printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}
