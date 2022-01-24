#include <stdio.h>

int main() {
	int n1, n2;

	printf("Two numbers: ");
	scanf_s("%d %d", &n1, &n2); // scanf를 사용하면 버퍼 오버플로우가 발생하여 보안에 위험!

	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	printf("%d - %d = %d\n", n1, n2, n1 - n2);
	printf("%d * %d = %d\n", n1, n2, n1 * n2);
	printf("%d / %d = %d\n", n1, n2, n1 / n2);

	return 0;
}