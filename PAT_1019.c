//PAT_1019 General Palindromic Number
//Miibotree
//2015.1.6

#include <stdio.h>

int main()
{
	int n = 0, b = 0;
	int a[10000];
	int flag = 1;
	while (scanf("%d%d", &n, &b) != EOF)
	{
		flag  = 1;
		int cnt = 0;
		if (n == 0)
		{
			printf("Yes\n0\n");//注意题目描述 0也是回文数
			continue;
		}
		
		while(n)
		{
			a[cnt] = n % b;
			cnt++;
			n = n / b;
		}

		for (int i = 0; i < cnt / 2; i++)
		{
			if (a[i] != a[cnt - i - 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			printf("Yes\n");
		else
			printf("No\n");

		for (int i = cnt - 1; i >=0; i--)
		{
			if (i > 0)
				printf("%d ", a[i]);
			else
				printf("%d\n", a[i]);
		}
	}


	return 0;
}