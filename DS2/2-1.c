// ������Ʈ�� ���� ���� ���� ���� ������Ʈ�� ���� ���ֱ�!

#include <stdio.h>
#include <stdlib.h>

int prime(int n);

int main() {
	int n;

	printf("Number: ");
	scanf_s("%d", &n);

	if (prime(n))
		printf("Prime\n");
	else
		printf("Not Prime\n");
	
	return 0;
}

int prime(int n) {
	for (int i = 2;i < n;i++) {
		if (n % i == 0) // 1�� �ڱ� �ڽ� �̿ܿ� �������� ���� �ִ�
			return 0; // -> not prime
	}
	return 1; // prime
}