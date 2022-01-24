/*
* ���� �ϳ��� ������Ʈ���� �ϳ��� main�� �����ؾ�������,
* ���Ǹ� ���� ���� é���� ������ ���� ������Ʈ�� ���� ��
* �����ų �� �ٸ� main ���ϵ��� '�Ӽ�->���忡�� ����' ��Ŵ
*/

#define LEN 30

#include <stdio.h>
#include <stdlib.h>

int main() {
	int ary[LEN];
	int idx = 0;

	FILE* fp = NULL;
	
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	while (!feof(fp)) {
		fscanf_s(fp, "%d", &ary[idx++]);
	}

	int max = ary[0], min = ary[0];

	for (int i = 0;i < idx;i++) {
		if (ary[i] > max)
			max = ary[i];
		if (ary[i] < min)
			min = ary[i];
	}

	printf("Min: %d\n", min);
	printf("Max: %d\n", max);

	return 0;
}