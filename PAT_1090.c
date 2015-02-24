//PAT_1090. Highest Price in Supply Chain (16 / 25)
//Miibotree
//2015.2.23
//三组数据超时

#include <stdio.h>
#include <math.h>

int Tree[100001];

int find(int x)
{
	int level  = 0;
	
	while(Tree[x] != -1)
	{
		x = Tree[x];
		level++;
	}
	return level;
}

int main()
{
	int n;
	double p, r;
	int cnt, max_level;
	while(scanf("%d%lf%lf", &n, &p, &r) != EOF)
	{
		r = 1 + r / 100;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			Tree[i] = x;
		}
		cnt = 0; max_level = 0;
		for(int i = 0; i < n; i++)
		{
			int ret = find(i);
			if (ret > max_level)
			{
				cnt = 1;
				max_level = ret;
			}
			else if(ret == max_level)
				cnt++;
		}
		printf("%lf %d\n", p * pow(r, max_level), cnt);
	}
	return 0;
}