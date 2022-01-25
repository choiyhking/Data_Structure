#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

int main() {
	int n, rhyme, temp, data;

	printf("Number of friends: ");
	scanf_s("%d", &n);
	
	printf("Words in rhyme: ");
	scanf_s("%d", &rhyme);

	List list;
	ListInit(&list);

	for (int i = 0;i < n;i++) {
		LInsert(&list, i + 1);
	}

	temp = n;
	while (temp > 1) { // until there is one left
		if (temp == n) {
			LFirst(&list, &data);
			for (int i = 0;i < rhyme - 1;i++) {
				LNext(&list, &data);
			}
		}
		else {
			for (int i = 0;i < rhyme;i++) {
				LNext(&list, &data);
			}
		}
		// printf("%d ", LRemove(&list));
		LRemove(&list);

		temp--;
	}
	LFirst(&list, &data);
	printf("Number %d is left\n", data);

	return 0;
}