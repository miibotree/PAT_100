//PAT_1013
//Miibotree
//2015.2.26
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001 * 1001 / 2];
int b[1001 * 1001 / 2];
int Tree[1001];

int findRoot(int x)
{
	if(Tree[x] == -1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main()
{
	int n, m, k;
	int i, j;
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		for(i = 1; i <= m; i++)
			scanf("%d%d", &a[i], &b[i]);

		for(i = 1; i <= k; i++)
		{
			int broken;
			scanf("%d", &broken);
			int cnt = 0;
			for(int p = 1; p <= n; p++)
				Tree[p] = -1;

			for(j = 1; j <= m; j++)
			{
				if(a[j] == broken || b[j] == broken)
					continue;
				else
				{
					int t1 = findRoot(a[j]);
					int t2 = findRoot(b[j]);
					if(t1 != t2)
					{
						Tree[t1] = t2;
						cnt++;
					}
				}
			}
			printf("%d\n", n - cnt - 2);
		}
	}
	return 0;
}