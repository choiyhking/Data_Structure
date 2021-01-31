#define MAX 100000

#include <stdio.h>

int sum(int num);

int main()
{
	int num1, num2;
	
	printf("First number: ");
	scanf("%d", &num1);
	
	printf("Second number: ");
	scanf("%d", &num2);
	
	if((num1 > MAX) || (num2 > MAX))
	{
		printf("Wrong input!\n");
		exit(1);
	}
	
	if((sum(num1) == num2) && (sum(num2) == num1))
		printf("Amicable\n");
	else
		printf("Not amicable\n");
	
	return 0;
}

// 약수의 합을 구하는 함수
int sum(int num)
{
	int res = 0;
	
	for(int i=1;i<num;i++)
	{
		if((num % i) == 0)
			res += i;
	}
	
	return res;
}