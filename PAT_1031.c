//PAT_1031
//Miibotree
//2015.1.8
//排版题

#include <stdio.h>
#include <string.h>

int main()
{
	char str[81];
	int n1 = 0, n2 = 0;
	int N = 0;
	while(gets(str))
	{
		N = strlen(str);
		for (int i = 3; i <= N; i++)
		{
			int k = (N + 2 - i) / 2;
			if (k <= i && k > n1)
				n1 = k;
		}
		n2 = N + 2 - 2 * n1;

		for (int i = 1; i <= n1; i++)
		{
			if (i == n1)//最后一行
			{
				printf("%c", str[i-1]);
				for(int j = 0; j < n2 - 2; j++)
					printf("%c", str[i + j]);
				printf("%c", str[N - i]);
				printf("\n");
			}
			else
			{
				printf("%c", str[i-1]);
				for(int j = 1; j <= n2 - 2; j++)
					printf(" ");
				printf("%c", str[N - i]);
				printf("\n");
			}
		}

	}
	return 0;
}