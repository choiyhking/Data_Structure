#define LEN 11 // length + 1

#include <stdio.h>

int main() {
	char isbn[LEN];
	int digit, mult, sum = 0;

	printf("ISBN: ");
	scanf_s("%s", isbn, sizeof(isbn));

	for (int i = 0;i < 10;i++) {
		if (isbn[i] == '?') {
			mult = 10 - i;
		}
		else if (isbn[i] == 'X') {
			sum += 10;
		}
		else { // 0~9
			sum += (isbn[i] - '0') * (10 - i);
		}
	}

	for (int i = 0;i <= 10;i++) {
		if ((sum + mult * i) % 11 == 0) {
			digit = i;
			break;
		}
	}

	if (digit == 10)
		printf("Missing digit: %c", 'X');
	else
		printf("Missing digit: %d", digit);

	return 0;
}