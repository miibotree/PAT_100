//PAT_1073. Scientific Notation (20)
//Miibotree
//2015.2.22
//字符串处理
//regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+
#include <stdio.h>
#include <string.h>

int main()
{
	char str[10000];
	char integer[100], fraction[100];
	int exponent;
	bool exp_symbol;//0 is +, 1 is -
	while(gets(str))
	{
		int len = strlen(str);
		//判断整体的符号
		if(str[0] == '-')
			printf("-");
		//整数部分
		char integer = str[1];
		//小数部分
		int k = 3;
		int frac_len = 0; 
		while(k < len && str[k] != 'E')
			fraction[frac_len++] = str[k++];
		fraction[frac_len] = 0;
		//指数部分符号
		k++;
		if(str[k] == '+')
			exp_symbol = 0;
		else
			exp_symbol = 1;

		sscanf(&str[k+1], "%d", &exponent);
		if(exp_symbol == 1)//指数部分是负号
		{
			printf("0.");
			for(int i = 1; i < exponent; i++)
				printf("0");
			printf("%c%s", integer, fraction);

		}
		else//指数部分是正数
		{
			if(exponent == frac_len)
				printf("%c%s", integer, fraction);
			else if(exponent < frac_len)
			{
				printf("%c", integer);
				for(int i = 0; i < frac_len; i++)
				{
					if(i == exponent)
						printf(".");
					printf("%c", fraction[i]);

				}
			}
			else
			{
				printf("%c%s", integer, fraction);
				for(int i = 1; i <= exponent - frac_len; i++)
					printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}