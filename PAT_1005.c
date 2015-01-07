//PAT_1005 Spell It Right
//Miibotree
//2015.1.7
//思路：N <= 10^100 把N看成字符串，把每一位加起来
//sum最大为100 × 9 = 900 

#include <stdio.h>
#include <string.h>

void echo (int n);

int main()
{	
	char str[101];
	int len = 0, i = 0, sum = 0;
	while(gets(str))
	{
		sum = 0;
		len = strlen(str);
		for (i = 0; i < len; i++)
			sum += str[i] - '0';

		if (sum < 10)
		{
			echo(sum);
			printf("\n");
		}
		else if (sum < 100)
		{
			echo(sum / 10);
			printf(" ");
			echo(sum % 10);
			printf("\n");
		} 
		else
		{
			echo(sum / 100);
			printf(" ");
			echo((sum % 100) / 10);
			printf(" ");
			echo(sum % 10);
			printf("\n");
		}
	}
	return 0;
}

void echo (int n)
{
	switch(n)
	{

		case 0:
			printf("zero");
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");	
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
	}


}
