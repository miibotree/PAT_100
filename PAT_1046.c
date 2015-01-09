//PAT_1046 Shortest Distance
//Miibotree
//2015.1.9
//思路：先把圆的距离之和加起来，然后分别求两段距离取小者

#include <stdio.h>

int main()
{
	int n = 0, m = 0;
	int a[100000];
	int dis[10000];//卡的是超时 最后一个case没有通过。所以要做的是预处理 限时100ms
	int sum = 0;
	int x = 0, y = 0;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		dis[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			dis[i] = sum;//一开始就把每个点到0点的距离给算出来
		}

		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			if (x > y)
				{int tmp = x; x = y; y = tmp;}
			
			if ((dis[y-1] - dis[x-1]) < sum - (dis[y-1] - dis[x-1]))
				printf("%d\n", dis[y-1] - dis[x-1]);
			else
				printf("%d\n", sum - (dis[y-1] - dis[x-1]));
		}
	}
	return 0;
}