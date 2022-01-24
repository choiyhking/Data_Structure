/*
* 원래 하나의 프로젝트에는 하나의 main만 존재해야하지만,
* 편의를 위해 같은 챕터의 과제는 동일 프로젝트에 만든 뒤
* 실행시킬 때 다른 main 파일들은 '속성->빌드에서 제외' 시킴
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