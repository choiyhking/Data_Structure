#include <stdio.h>
#include <stdlib.h>

int amicable(int n);

int main() {
	int n1, n2;

	printf("First number: ");
	scanf_s("%d", &n1);

	printf("Second number: ");
	scanf_s("%d", &n2);

	if (amicable(n1) == n2 && amicable(n2) == n1)
		printf("Amicable\n");
	else
		printf("Not amicable\n");

	return 0;
}

int amicable(int n) { // 자신을 제외한 약수의 합을 구하는 함수
	int sum = 0;

	for (int i = 1;i < n;i++) {
		if (n % i == 0)
			sum += i;
	}

	return sum;
}