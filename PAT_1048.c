//PAT_1048. Find Coins (25)
//Miibotree
//2015.1.23
//hash

#include <stdio.h>
#include <algorithm>

using namespace std;

int coin[100005];

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < 100005; i++)
			coin[i] = 0;

		int x;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			coin[x]++;
		}
		int flag = 1;

		for (int i = 1; i <= 100000; i++)
		{
			int y = m - i;
			if(i == y)//需要两枚相同的硬币
			{
				if (coin[i] >= 2)
				{
					printf("%d %d\n", i, i);
					flag = 0;
					break;
				}
			}
			else
			{
				if(coin[i] >= 1 && coin[y] >= 1)
				{
					printf("%d %d\n", i, y);
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
			printf("No Solution\n");
	}
	return 0;
}