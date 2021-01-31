#define MAX 100
#define POWER(X) (int)pow(10.0, (double)X) // 10의 X승

#include <stdio.h>
#include <math.h>

int sumFac(int num);
int factorial(int n);

int main()
{
	int n, k;
	int ary[MAX]; // 결과값 저장
	
	printf("N, K: ");
	scanf("%d %d", &n, &k);
	
	ary[0] = n;

	for(int i=1;i<k;i++)
		ary[i] = sumFac(ary[i-1]);
	
	for(int i=0;i<k;i++)
		printf("%d\n", ary[i]);
	
	return 0;
}

// num의 각 digit의 factorial 값의 합을 구하는 함수
int sumFac(int num)
{
	int sum = 0;
	
	// 정수의 자릿수 분리하는 방법!
	while(num > 0)
	{
		sum += factorial(num % 10);
		num = num / 10;
	}
	
	return sum;
}

// factorial 값을 구하는 함수(재귀)
int factorial(int n)
{
	if(n == 0) return 1;
	
	return n * factorial(n - 1);
}