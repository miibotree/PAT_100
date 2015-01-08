//PAT_1023
//Miibotree
//2015.1.8
//分析：字符串处理

#include <stdio.h>
#include <string.h>

int Add(char *str1, char *str2, int len1, int *carry_flag);

int main()
{
	char str1[22], str2[22];

	while(gets(str1))
	{
		int str1_num[10] = {0}, str2_num[10] = {0};
		int len1 = 0, len2 = 0;
		int flag = true, carry_flag = false;
		memset(str2, 0, 22);

		len1= strlen(str1);
		for (int i = 0; i < len1; i++)
		{
			str1_num[str1[i] - '0']++;
		}
		
		Add(str1, str2, len1, &carry_flag);

		if (carry_flag == true)//乘2之后有进位，位数肯定不一样了
		{
			printf("No\n");
			printf("1");
			puts(str2);
		}
				
		else//没有进位
		{
			len2= strlen(str2);
			for (int i = 0; i < len2; i++)
			{
				str2_num[str2[i] - '0']++;
			}

			for (int i = 0; i < 10; i++)
			{
				if (str1_num[i] != str2_num[i])
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				printf("Yes\n");
			else
				printf("No\n");
			puts(str2);
		}
	}


	return 0;
}

int Add(char *str1, char *str2, int len1, int *carry_flag)
{
	int carry = 0;//表示进位
	for (int i = len1 - 1; i >= 0; i--)
	{
		str2[i] = str1[i] + str1[i] - '0' + carry;
		if (str2[i] - '0' >= 10)//说明有进位
		{
			carry = 1;
			str2[i] = str2[i] - 10;
		} 
		else
			carry = 0;
	}
	if(carry == 1)
		*carry_flag = true; 
	return 0;
}