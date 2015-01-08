//PAT_1024 Palindromic Number
//Miibotree
//2015.1.8

#include <stdio.h>
#include <string.h>

int Revserse(char *str, char *rev_str);
int Add(char *str, char *rev_str);
int Judge(char *str);

int main()
{
	char str[256];
	char rev_str[256];
	int k = 0;
	while(scanf("%s %d", str, &k) != EOF)
	{
		memset(rev_str, 0, 256);

		if (Judge(str))//输入的数字直接就是回文数
			printf("%s\n0\n", str);
		else
		{
			for (int i = 1; i <= k; i++)
			{
				memset(rev_str, 0, 256);
				Revserse(str, rev_str);
				Add(str, rev_str);
				if (i == k)//turn到了不管是不是回文数都要输出
					printf("%s\n%d\n", str, k);
				else if (Judge(str))//是回文数
				{
					printf("%s\n%d\n", str, i);
					break;
				}
			}
		}


	}
	return 0;
}

int Revserse(char *str, char *rev_str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		rev_str[i] = str[len - i - 1];
	return 0;
}

int Add(char *str, char *rev_str)
{
	int carry_flag = false;
	int carry = 0;
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--)
	{
		str[i] = str[i] + rev_str[i] - '0' + carry;
		if (str[i] - '0' >= 10)//说明出现了进位
		{
			str[i] -= 10;
			carry = 1;
		} 
		else
			carry = 0;
	}
	if (carry == 1)//最高位有进位
	{
		for (int i = len; i > 0; i--)
			str[i] = str[i - 1];
		str[0] = '1';
		str[len + 1] = 0;
	}
	return 0;
}

int Judge(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		if(str[i] != str[len - i - 1])
			return false;
	}
	return true; 
}