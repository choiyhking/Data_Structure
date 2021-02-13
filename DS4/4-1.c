// INT_MAX = 2147483647
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *n1 = (char *)malloc(sizeof(char)*MAX);
	char *n2 = (char *)malloc(sizeof(char)*MAX);
	int *ans = (int *)malloc(sizeof(int)*MAX);
	
	printf("First Number: ");
	scanf("%s", n1);
	
	getchar(); // buffer 비우기
	
	printf("Second Number: ");
	scanf("%s", n2);
	
	int len1 = (int)strlen(n1);
	int len2 = (int)strlen(n2);
	int carry = 0, sum = 0, rem = 0, idx = 0;
	
	while(len1 > 0 && len2 > 0)
	{
		sum = (n1[len1-1] - 48) + (n2[len2-1] - 48); // 뒤에서 부터 읽기
		rem = (sum + carry) % 10; 
		carry = (sum + carry) / 10;
		
		ans[idx++] = rem;
		
		len1--; len2--;
	}
	
	if(len1 > 0) // 남은 자릿수 처리
	{
		while(len1 > 0)
		{
			sum = (n1[len1-1] - 48);
			rem = (sum + carry) % 10; 
			carry = (sum + carry) / 10;
			
			ans[idx++] = rem;
			
			len1--;
		}
	}
	else if(len2 > 0)
	{
		while(len2 > 0)
		{
			sum = (n2[len2-1] - 48);
			rem = (sum + carry) % 10; 
			carry = (sum + carry) / 10;
			
			ans[idx++] = rem;
			
			len2--;
		}
	}
	
	if(carry > 0) // 마지막 캐리가 있는 경우
		ans[idx++] = carry;
	
	for(int i=idx-1;i>=0;i--)
		printf("%d", ans[i]);
	printf("\n");
	
	return 0;
}