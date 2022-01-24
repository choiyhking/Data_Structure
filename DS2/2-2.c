#define LEN 30

#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int digitSum(int n);

int main() {
	int n, k; // n�� ���� ��, k�� �� ������ �� ���� ����
	int ary[LEN];

	printf("N, K: ");
	scanf_s("%d %d", &n, &k);

	ary[0] = n;

	for (int i = 1;i < k;i++) {
		ary[i] = digitSum(ary[i - 1]);
	}
		
	for (int i = 0;i < k;i++) {
		printf("%d ", ary[i]);
	}

	return 0;
}

int factorial(int n) {
	if (n <= 1) return 1;

	return n * factorial(n - 1);
}

int digitSum(int n) { // �� �ڸ� ���� ���丮�� ���� ���� ���ϴ� �Լ�
	int sum = 0;
	
	while (n > 0) {
		sum += factorial(n % 10);
		n = n / 10;
	}

	return sum;
}