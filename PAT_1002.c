//PAT 1002
//Miibotree
//2015.1.5
#include <stdio.h>

int main()
{
	double sum[1001], nk = 0;
	int count = 0;
	int k = 0;
	int m, n = 0;
	int i = 0;

	while (scanf("%d", &m) != EOF)
	{
		count = 0;
		for (i = 0; i < 1001; i++) //initial sum array
			sum[i] = 0;

		for (i = 0; i < m; i++)
		{
			scanf("%d %lf", &k, &nk);
			sum[k] += nk;
		}

		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %lf", &k, &nk);
			sum[k] += nk;
		}

		for (i = 0; i < 1001; i++)
			{if (sum[i] != 0)	count++;}
		printf("%d ", count);

		if (count == 1)
		{
			for (i = 1000; i >=0; i--)
			{
				if (sum[i] != 0)
				{
					printf("%d %.1f\n", i, sum[i]);
					break;
				}
			}
		}
		else{
			for (i = 1000; i >=0 && count > 1; i--)
			{
				if (sum[i] != 0)
				{
					printf("%d %.1f ", i, sum[i]);
					count--;
				}
			}

			for (; i >= 0; i--)
			{
				if (sum[i] != 0)
				{
					printf("%d %.1f\n", i, sum[i]);
					break;
				}
			}
		}
	}


}