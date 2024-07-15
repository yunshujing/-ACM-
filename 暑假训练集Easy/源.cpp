#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main(){
//	printf("Hello,World!");
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	printf("  *\n");
//	printf(" ***\n");
//	printf("*****\n");
//	printf(" ***\n");
//	printf("  *");
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int a,b,s = 0;
//	while(~scanf("%d %d",&a,&b)){
//		s=a+b;
//		printf("%d\n",s);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	char n;
//	while(~scanf("%c",&n)){
//		for(int i = 1;i < 3;i++){
//			for(int j = 3-i;j > 0 ;j--){
//				printf(" ");
//			}
//			for(int k = 1;k <= i*2-1;k++){
//				printf("%c",n);
//			}
//			printf("\n");
//		}
//		for(int k = 1;k <= 5;k++){
//				printf("%c",n);
//		}
//	}
//	return 0;
//}


//int main(){
//	int a,b,s = 0;
//	while(~scanf("%d %d",&a,&b)){
//		s=a*b;
//		printf("%d\n",s);
//	}
//	return 0;
//}


//int main(){
//	char s;
//	while(~scanf("%c",&s)){
//		if (s >= 'a' && s <= 'z') { 
//			s=s-'a'+'A';
//			printf("%c",s);
//		}
//	}
//	return 0;
//} 


//int main(){
//	int b,c,d,e,f;double n=0.0,s = 0.0;
//	while(~scanf("%lf",&n)&& n >= 100 && n < 1000){
//		b = n*10;
//		c = b/1000;
//		d = b/100%10;
//		e = b/10%10;
//		f = b%10;
//		s = (f*1000+e*100+d*10+c)/1000.0;
//		printf("%.3lf",s);
//	}
//	return 0;
//}


//int main(){
//	int n,a;
//	double t;
//	while(~scanf("%lf %d",&t,&n)){
//		a = n*2;
//		double x= t/n*1.000;
//		printf("%.3lf\n%d",x,a);
//	}
//	return 0;
//}

//
//#include<math.h>
//int main(){
//	double a, b, c, p, s;
//	while (~scanf("%lf %lf %lf", &a, &b, &c)) {
//		p = (a + b + c) *0.5;
//		s = sqrt(p * (p - a) * (p - b) * (p - c));
//		printf("%.1lf", s);
//	}
//	return 0;
//}

//
//#include<math.h>
//int main() {
//	int h, r;
//	double v,x;
//	while (~scanf("%d %d", &h, &r))
//	{
//		v = 3.14* r * r * h;
//		x = 20 * 1000 / v;
//		printf("%.0lf",ceil(x));
//	}
//	return 0;
//}


//int main() {
//	int a, b, c, d, e, f;
//	while (~scanf("%d %d %d %d",&a,&b,&c,&d)&& 0<=a &&c <= 24&& 0<=a && c<=24&&0<=b&&d<=60&&0<=b&& d<=60)
//	{
//		int s = (c - a - 1) * 60 + (60 - b) + d;
//		int n = s / 60;
//		int m = s % 60;
//		printf("%d %d", n, m);
//	}
//	return 0;
//}


//
//int main() {
//	int a, b, c;
//	while (~scanf("%d %d", &a, &b)){
//		c = (a * 10 + b) / 19;
//		printf("%d", c);
//	}
//	return 0;
//}


//
//int main() {
//	int a, b, c,d;
//		while (~scanf("%d %d %d", &a, &b,&c)){
//			d = a * 0.2 + b * 0.3 + c * 0.5;
//			printf("%d", d);
//		}
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int m, t, s;
//	while (~scanf("%d %d %d", &m, &t, &s)&& 1<=m&&m<=100&& 0<=t&&t<=100&& 1<=s&&s<=10000) {
//		if (t == 0) {
//		printf("%d", 0); return 0;
//		}
//		double k = (double)s / t;
//		double flag = k - (int)k;
//		if ((int)k>m)
//		{
//			printf("%d", 0);
//		}
//		else
//		{
//			if (flag) {
//				printf("%d", m - (int)k - 1);
//			}
//			else {
//				printf("%d", m - (int)k);
//			}
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int m; char a[4] = { 0 };
//	while (~scanf("%d", &m)) {
//		if (m % 2 == 0 && m > 4 && m <= 12)
//		{
//			a[0]=1;
//			a[1]=1;
//		}
//		else {
//			if (m % 2 == 0 || (m > 4 && m <= 12)) {
//				a[1] = 1;
//				a[2] = 1;
//			}
//			else
//			{
//				if (m % 2 != 0 && (m <= 4 || m > 12)) {
//					a[3] = 1;
//				}
//			}
//		}
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%d ", a[i]);
//		}
//		printf("%d", a[3]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int m;
//	while (~scanf("%d", &m)) {
//		if ((m%4==0&&m%100!=0)||m%400==0)
//		{
//			printf("1");
//		}
//		else {
//			printf("0");
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int m;
//	while (~scanf("%d", &m)) {
//		if (m >1)
//			printf("Today, I ate %d apples.",m);
//		else
//			printf("Today, I ate %d apple.", m);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int temp; char a[3] = { 0 };
//	while (~scanf("%d %d %d", &a[0], &a[1], &a[2])) {
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = i; j < 3; j++)
//			{
//				if (a[i] > a[j]) {
//					temp = a[i];
//					a[i] = a[j];
//					a[j] = temp;
//				}
//			}
//		}
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%d ", a[i]);
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int m,n;
//	while (~scanf("%d %d", &m, &n)) {
//		if ((m % 4 == 0 && m % 100 != 0) || m % 400 == 0) {
//			if (n == 2)
//			{
//				printf("29");
//			}
//			else
//			{
//				if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
//				{
//					printf("31");
//				}
//				else
//				{
//					printf("30");
//				}
//			}
//		}
//		else
//		{
//			if (n == 2)
//			{
//				printf("28");
//			}
//			else
//			{
//				if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
//				{
//					printf("31");
//				}
//				else
//				{
//					printf("30");
//				}
//			}
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int m[3]; scanf("%d %d %d", &m[0], &m[1], &m[2]);
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2 - i; j++) {
//			if (m[j] > m[j + 1]) {
//				int tmp = m[j];
//				m[j] = m[j + 1];
//				m[j + 1] = tmp;
//			}
//		}
//	}
//	int flag = 0;
//	if (m[0] + m[1] > m[2] && fabs(m[0] - m[1]) < m[2]) {
//		flag = 1;//可以组成三角形
//	}
//
//	if (flag == 0) {
//		printf("Not triangle\n"); return 0;
//	}
//	if (m[0] * m[0] + m[1] * m[1] == m[2] * m[2]) {
//		printf("Right triangle\n");
//	}
//	if (m[0] * m[0] + m[1] * m[1] > m[2] * m[2]) {
//		printf("Acute triangle\n");
//	}
//	if (m[0] * m[0] + m[1] * m[1] < m[2] * m[2]) {
//		printf("Obtuse triangle\n");
//	}
//	if (m[0] == m[1] || m[0] == m[2] || m[1] == m[2]) {
//		printf("Isosceles triangle\n");
//	}
//	if (m[0] == m[1] && m[1] == m[2]) {
//		printf("Equilateral triangle\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int n=0; int a[100];
//	while (~scanf("%d", &n)&&n<=100) {
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &a[i]);
//		}
//		for (int i = 0; i < n-1; i++) {
//			for (int j = 0; j < n-i-1; j++) {
//				if (a[j] > a[j + 1]) {
//					int tmp = a[j];
//					a[j] = a[j + 1];
//					a[j + 1] = tmp;
//				}
//			}
//		}
//		printf("%d", a[0]);
//	}
//	return 0;
//}

10086