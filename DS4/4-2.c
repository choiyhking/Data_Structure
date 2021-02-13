#include <stdio.h>
#include <ctype.h>

int main()
{
	char input[11];
	int sum = 0, idx = 0, ans;
	
	printf("ISBN: ");
	scanf("%s", input);
	
	for(int i=0;i<10;i++)
	{
		if(isdigit(input[i]))
			sum += (input[i] - '0') * (10 - i);
		else
		{
			if(input[i] == 'X')
				sum += 10 * (10 - i);
			else // input[i] == '?'
				idx = 10 - i;
		}
	}
	
	// Each of the digits can take a value between 0 and 9, last digit can be 10('X')
	for(ans=0;(sum+(ans*idx))%11 != 0 && ans<=10;ans++);
	
	printf("Missing Digit: %d\n", ans);
	
	return 0;
}