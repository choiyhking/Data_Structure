#include <stdio.h>

int main() {
	int n1, n2;

	printf("Two numbers: ");
	scanf_s("%d %d", &n1, &n2); // scanf�� ����ϸ� ���� �����÷ο찡 �߻��Ͽ� ���ȿ� ����!

	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	printf("%d - %d = %d\n", n1, n2, n1 - n2);
	printf("%d * %d = %d\n", n1, n2, n1 * n2);
	printf("%d / %d = %d\n", n1, n2, n1 / n2);

	return 0;
}