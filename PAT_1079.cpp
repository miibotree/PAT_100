//PAT_1079. Total Sales of Supply Chain (23/25)
//Miibotree
//2015.2.18
//无论是递归版本还是非递归版本最后一个case都超时,时间复杂度为o(n^log(n))

#include <stdio.h>
#include <math.h>

int T[100001];
int flag[100001];
int amount[100001];

int level(int x)
{
	int cnt = 0;
	while(x != -1)
	{
		cnt++;
		x = T[x];
	}
	return cnt;
}

int main()
{
	int n;
	double p, r, sum = 0;
	while(scanf("%d%lf%lf", &n, &p, &r) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if(x == 0)//经销商
			{
				flag[i] = 1;
				scanf("%d", &amount[i]);
			}
			else
			{
				for(int j = 0; j < x; j++)
				{
					int t;
					scanf("%d", &t);
					T[t] = i;
				}
			}
		}
		T[0] = -1;//根节点
		for(int i = 0; i < n; i++)
		{
			if(flag[i] == 1)//说明是零售商
			{
				//计算深度
				int depth = level(T[i]);
				sum += amount[i] * p * pow(1+r/100, depth);
			}
		}
		printf("%.1f\n", sum);
	}
	return 0;
}