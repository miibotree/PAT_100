//PAT 1015 Reversible Primes
//Miibotree
//2015.1.6
//思路：1.在D进制下把N逆转得到ReverseN
//		2.将ReverseN转换成10进制下的整数
//		3.分别判断N和reverseN是不是素数

#include <stdio.h>
#include <math.h>

int Reverse(int n, int d);
int Judge_Prime(int x);

int main()
{
	int n = 0, d = 0, reverse_n = 0;//n的范围小于10^5

	while (scanf("%d", &n) != EOF)
	{
		if (n < 0)
			break;
		else
			scanf("%d", &d);
		reverse_n = Reverse(n, d);

		if (Judge_Prime(n) && Judge_Prime(reverse_n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

int Reverse(int n, int d)
{
	int cnt = 0;
	int b[100];
	while (n)
	{
		b[cnt] = n % d;
		cnt++;
		n = n / d;
	}
	int ans = 0;
	for (int i = 0; i < cnt; i++)
		ans += b[cnt - i - 1] * pow((float)d,i);
	return ans;
}

int Judge_Prime(int x)
{
	if (x < 2)
		return false;

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