// 프로젝트가 여러 개일 때는 시작 프로젝트로 설정 해주기!

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
		if (n % i == 0) // 1과 자기 자신 이외에 나눠지는 수가 있다
			return 0; // -> not prime
	}
	return 1; // prime
}