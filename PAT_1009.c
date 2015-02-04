//PAT_1009. Product of Polynomials (25)
//Miibotree
//2015.2.4
//思路：指数相加，系数相乘
#include <stdio.h>

double a[1001], b[1001];
double sum[1000001];

int main()
{
	for(int i = 0; i <= 1000; i++)
	{
		a[i] = 0;b[i] = 0;
	}
	for(int i = 0; i <= 1000000; i++)
		sum[i] = 0;

	int k;
	int ex;
	double co;
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d %lf", &ex, &co);
		a[ex] = co;
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d %lf", &ex, &co);
		b[ex] = co;
	}
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			if(a[i] != 0 && b[j] != 0)
			{
				sum[i+j] += a[i] * b[j];
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i <= 1000000; i++)
	{
		if(sum[i] != 0)
			cnt++;
	}
	printf("%d", cnt);
	for(int i = 1000000; i >= 0; i--)
	{
		if(sum[i] != 0)
			printf(" %d %.1f", i, sum[i]);
	}
	printf("\n");
	return 0;
}
