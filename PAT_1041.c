//PAT_1041 Be Unique (20)
//Miibotree
//2015.1.10
//Hash思想

#include <stdio.h>

int a[10001];
int b[100001];

int main()
{
	int n = 0;
	int tmp = 0;
	int i = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (int j = 1; j < 10001; j++)
			a[j] = 0;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &b[j]);
			a[b[j]]++;
		}

		for (i = 1; i <= n; i++)
		{
			if (a[b[i]] == 1)
			{
				printf("%d\n", b[i]);
				break;
			}
		}
		if (i == n+1)
			printf("None\n");
	}

	return 0;
}