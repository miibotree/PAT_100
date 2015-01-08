//PAT_1024 Palindromic Number
//miibotree
//2015.1.8

#include <stdio.h>
#include <math.h>

int Judge(int n);
int Add(int *n);

int main()
{
	int n = 0;
	int k = 0, i = 0;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		i = 0;
		if (Judge(n))
		{
			printf("%d\n%d\n", n, i);
			continue;
		}
		else
		{
			for (i = 1; i <= k; i++)
			{
				Add(&n);
				if (Judge(n))
				{
					printf("%d\n%d\n", n, i);
					break;
				}
				else if (i == k)
					printf("%d\n%d\n", n, i);
			}
		}	

	}
	return 0;
}

int Judge(int n)//判断回文数
{
	int cnt = 0;
	int a[1000];

	while (n)
	{
		a[cnt] = n % 10;
		n = n / 10;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (a[i] != a[cnt - i - 1])
			return false;
	}
	return true;
}

int Add(int *n)
{
	int cnt = 0;
	int a[1000];
	int p = *n;
	int reverse_n = 0;

	while (p)
	{
		a[cnt] = p % 10;
		p = p / 10;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
		reverse_n += a[i] * pow((double)10, cnt-i-1);
	*n = *n + reverse_n;
	return 0;
}