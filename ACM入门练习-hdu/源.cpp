#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main() {
//	int a, b;
//	while (~scanf("%d %d", &a, &b)) {
//		printf("%d\n", a + b);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int a, b, n = 0;
//	scanf("%d", n);
//	while (n--)
//	{
//		scanf("%d %d", &a, &b);
//		printf("%d\n", a + b);
//	}
//	return 0;
//}

#include<stdio.h>
int main() {
	int a, b;
	while (~scanf("%d %d", &a, &b)&&(a||b)) {
		printf("%d\n", a + b);
	}
	return 0;
}

