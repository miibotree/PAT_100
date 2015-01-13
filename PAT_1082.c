//PAT_1082 Read Number in Chinese (12/25)
//Miibotree
//2015.1.13

//Note: 0的处理有两种情况
//		1000 若后面连续都是0，则不用读出来
//		1001 若连续若干个0后面还有非0数字，先读ling 然后从非零数字开始读

#include <stdio.h>
#include <string.h>

void Turn(char *str, int len);
void ChineseNumber(char r);
int DealZero(char *str, int len);

int main(){
	char str[11];
	int len = 0;
	while(gets(str))
	{
		int len = strlen(str);
		if (str[0] == '-')//负数的处理
		{
			printf("Fu ");
			for (int i = 0; i < len; i++)
				str[i] = str[i+1];
			len--;
		}
		if (len <= 4)
		{
			Turn(str, len);
		}
		else if (len > 4 && len <= 8)
		{
			Turn(str, len-4);
			printf(" Wan ");
			Turn(&str[len-4], 4);
		}

		else if (len == 9)//有亿
		{
			ChineseNumber(str[0]);
			printf(" Yi ");

			Turn(&str[1], 4);
			printf(" Wan ");
			Turn(&str[5], 4);
		}
	}
	return 0;
}

void Turn(char *str, int len)
{
	if (len == 1)
		ChineseNumber(str[0]);
	else if (len == 2)
	{
		ChineseNumber(str[0]);
		printf(" ");
		printf("Shi ");
		ChineseNumber(str[1]);
	}
	else if (len == 3)
	{
		ChineseNumber(str[0]);
		printf(" ");
		printf("Bai ");
		ChineseNumber(str[1]);
		printf(" ");
		printf("Shi ");
		ChineseNumber(str[2]);
	}
	else if (len == 4)
	{
		ChineseNumber(str[0]);
		printf(" ");
		printf("Qian ");
		ChineseNumber(str[1]);
		printf(" ");
		printf("Bai ");
		ChineseNumber(str[2]);
		printf(" ");
		printf("Shi ");
		ChineseNumber(str[3]);
	}
}

void ChineseNumber(char r)
{
	switch(r)
	{
		case '0':
			printf("ling");
			break;
		case '1':
			printf("yi");
			break;
		case '2':
			printf("er");
			break;
		case '3':
			printf("san");
			break;
		case '4':
			printf("si");
			break;
		case '5':
			printf("wu");
			break;
		case '6':
			printf("liu");
			break;
		case '7':
			printf("qi");
			break;
		case '8':
			printf("ba");
			break;
		case '9':
			printf("jiu");
			break;
	}
}

/*
int DealZero(char *str, int len)
{

}
*/