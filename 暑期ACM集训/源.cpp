#include<bits/stdc++.h>

int main() {
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			int n = a * 1100 + b * 11;
			double x = sqrt(n);
			if (fabs(x - (int)x) < 1e-6) {//��ȫƽ���� ��0.000001�ж� 
				printf("%d %.0f\n", n, x);
			}
		}
	}
}



//�׳�֮�͵�ĩ6λ�� 
#include<bits/stdc++.h>
const int M = 1e6;
int main() {
	freopen("2.in", "r", stdin);//�����ض���2.in
	freopen("2.out", "w", stdout);//����ض���2.out 
	int n;
	while (~scanf("%d", &n)) {
		long long s = 0, f = 1;
		for (int i = 1; i <= n; i++) {
			f = f * i % M;   //i!
			s = (s + f) % M; //�׳˺� 
		}
		printf("%lld %lld\n", n, s);
	}
}
