//PAT 1015 Reversible Primes
//Miibotree
//2015.1.6
//思路：1.在D进制下把N逆转得到ReverseN
//		2.将ReverseN转换成10进制下的整数
//		3.分别判断N和reverseN是不是素数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Reverse(char *str, char *reverse_str, int str_len);
int Cal_ReverseN(char *reverse_str, int str_len, int *reverse_n, int d);
int Judge_Prime(int x);

int main()
{
	int n = 0, d = 0, reverse_n = 0;//n的范围小于10^5
	char str[256], reverse_str[256];
	int str_len = 0;
	int flag = 1;

	while (scanf("%d", &n) != EOF)
	{
		if (n < 0)
			break;
		else
			scanf("%d", &d);
		memset(str, 0, 256);
		memset(reverse_str, 0, 256);
		flag = 1;
		reverse_n = 0;

		itoa(n, str, d);//将转换后的D进制数放在str字符串里面
		str_len = strlen(str);
		Reverse(str, reverse_str, str_len);
		Cal_ReverseN(reverse_str, str_len, &reverse_n, d);//reverse_n中存放转换后的十进制
		if (Judge_Prime(n) == false)
			flag = 0;
		if (Judge_Prime(reverse_n) == false)
			flag = 0;

		if (flag == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

int Reverse(char *str, char *reverse_str, int str_len)
{
	int i = 0;
	for (; i < str_len; i++)
		reverse_str[str_len - i - 1] = str[i];
	return 0;
}

int Cal_ReverseN(char *reverse_str, int str_len, int *reverse_n, int d)
{
	int i = str_len - 1;
	int exp = 0;
	double base = 0;
	int coff = 0;


	for (; i >= 0; i--)
	{
		coff = reverse_str[i] - '0';
		base = d;
		exp = str_len - i - 1;
		*reverse_n += coff * pow(base, exp);
	}
	return 0;
}

int Judge_Prime(int x)
{
	if (x == 2)
		return true;
	else
	for (int i = 2; i < x / 2; i++)
	{
		if (x % i == 0)//说明被整除了 不是素数
			return false;
	}
	return true;
}