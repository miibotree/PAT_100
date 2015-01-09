//PAT_1060 Are They Equal (25)
//Miibotree
//2015.1.9
//scores(19/25) 没有考虑:
//1、转换后小数点后第1位应当为非0数，这个数字可出现在原数的小数点之后，如0.00123；
//2、原有数据可能长度不足，如0.00123取5位有效数字，后面的2位应认为是0；
//3、注意计算指数时，系数为正和系数为负计算式有区别

#include <stdio.h>
#include <string.h>

typedef struct _sn
{
	char d[256];
	int e;
}sn;

int StandForm(char *str, sn *x, int n);
int JudgeEqual(sn x, sn y);

int main(){
	int n = 0;
	char str1[256], str2[256];
	sn x, y;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%s %s", str1, str2);
		StandForm(str1, &x, n);
		StandForm(str2, &y, n);
		JudgeEqual(x, y);
	}
	return 0;
}

int StandForm(char *str, sn *x, int n)
{
	int len = strlen(str);
	int cnt = 0;
	for(int i = 0; i < len; i++)
	{
		if(str[i] != '.')
			cnt++;
		else
			break;
	}
	x->e = cnt;
	x->d[0] = '0';x->d[1] = '.';

	if (cnt < len)//存在小数点
	{
		for (int i = cnt; i < len - 1; ++i)//去掉小数点
			str[i] = str[i + 1];
		str[len - 1] = 0;
	}	
	for (int i = 0; i < n; i++)//得到底数
		x->d[i+2] = str[i];
	x->d[n+2] = 0;
	return 0;
}

int JudgeEqual(sn x, sn y)
{
	if (x.e != y.e || strcmp(x.d, y.d) != 0)//指数不相同或者底数不相等，则不相等
	{
		printf("NO %s*10^%d %s*10^%d\n", x.d, x.e, y.d, y.e);
	}
	else
		printf("YES %s*10^%d\n", x.d, x.e);
	return 0;
}