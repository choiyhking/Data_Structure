#define MAX 101 // 'sprintf' put NULL at the end

#include <stdio.h>
#include <string.h>

int main() {
	char buf1[MAX], buf2[MAX]; // up to 100 digits
	char n1[MAX], n2[MAX], res[MAX];
	int len, carry = 0, sum = 0, idx = 0;
	
	printf("First Number: ");
	scanf_s("%s", buf1, sizeof(buf1));
	int n1Len = strlen(buf1);
	sprintf_s(n1, sizeof(n1), "%0100s", buf1); // after right alignment, the remaining spaces are filled with zeros -> inefficient..
											   	
	printf("Second Number: ");
	scanf_s("%s", buf2, sizeof(buf2));
	int n2Len = strlen(buf2);
	sprintf_s(n2, sizeof(n2), "%0100s", buf2);

	if (n1Len >= n2Len) len = n1Len;
	else len = n2Len;
	
	for (int i = MAX-2;i >= MAX-2-len;i--) {
		sum = carry + (n1[i] - '0') + (n2[i] - '0'); // char to integer: char-'0'
		carry = 0;
		
		res[idx++] = ((sum % 10) + 48); // integer to char: char + 48
		carry = sum / 10;
	}

	for (int i = idx-1;i >=0;i--) {
		if ((i == idx - 1) && (res[i] == '0')) 
			continue;

		printf("%c", res[i]);
	}
	
	return 0;
}