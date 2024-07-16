#define _CRT_SECURE_NO_WARNINGS

/*
#include<stdio.h>
int main() {
	int a, b;
	while (~scanf("%d %d", &a, &b)) {
		printf("%d\n", a + b);
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main() {
	int a, b, n = 0;
	scanf("%d", n);
	while (n--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
*/


/*
#include<stdio.h>
int main() {
	int a, b;
	while (~scanf("%d %d", &a, &b)&&(a||b)) {
		printf("%d\n", a + b);
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main() {
	int a, b=0,n;
	while (~scanf("%d", &n) && n) {
		while (n--)
		{
			scanf("%d", &a);
				b = b + a;
		}
		printf("%d\n", b);
		b = 0;
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main() {
	int a, b = 0, n,m;
	while (~scanf("%d", &n) && n) {
		while (~scanf("%d", &m) && m) {
			while (m--)
			{
				scanf("%d", &a);
				b = b + a;
			}
			printf("%d\n", b);
			b = 0;
		}
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main() {
	int a, b = 0, n;
	while (~scanf("%d", &n) && n) {
		while (n--)
		{
			scanf("%d", &a);
			b = b + a;
		}
		printf("%d\n", b);
		b = 0;
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main() {
	int a, b;
	while (~scanf("%d %d", &a, &b)) {
		printf("%d\n\n", a + b);
	}
	return 0;
}
*/

/*H
#include<stdio.h>
int main() {
	int a, b = 0, n,m;
	while (~scanf("%d", &n) && n) {
		while (~scanf("%d", &m) && m) {
			while (m--)
			{
				scanf("%d", &a);
				b = b + a;
			}
			printf("%d\n\n", b);
			b = 0;
		}
	}
	return 0;
}
*/


////K
//#include<stdio.h>
//int main() {
//	int ah, am, as, bh, bm, bs, x, y,z,h,m,s,n;
//	while (~scanf("%d", &n)) {
//		while (~scanf("%d %d %d %d %d %d", &ah, &am, &as, &bh, &bm, &bs)) {
//			x = ah * 3600 + am * 60 + as;
//			y = bh * 3600 + bm * 60 + bs;
//			z = x + y;
//			h = z / 3600;
//			m = z % 3600 / 60;
//			s = z % 3600 % 60;
//			printf("%d %d %d\n", h, m, s);
//		}
//	}
//}

#include<stdio.h>
int main() {
	int n, m, i,j; int a[10], b[10];
	while (~scanf("%d %d", &n, &m)&&(n||m)) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a[i]);
		}
		for (int j = 0; j < m; j++)
		{
			scanf("%d", b[j]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				if (a[i]==b[j])
				{
					a[i] = -1;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i]>0) {
				printf("%d", a[i]);
			}
			
		}
	}
}
