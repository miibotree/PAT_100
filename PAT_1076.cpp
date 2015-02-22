//PAT_1076. Forwards on Weibo (30)
//Miibotree
//2015.2.22
//图的深度遍历DFS

#include <stdio.h>
#include <vector>
using namespace std;

vector<int> Edge[1001];
int flag[1001];
int ans[1001];
int sum;
int L;

void clear()
{
	for(int i = 0; i < 1001; i++)
		flag[i] = false;
}

void dfs(int x, int depth)
{
	if(depth > L)
		return;
	if(flag[x] == false)
	{
		flag[x] = true;
		sum++;
	}
	for(int i = 0; i < Edge[x].size(); i++)
		dfs(Edge[x][i], depth + 1);
}

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &L) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			int cnt, v;
			scanf("%d", &cnt);
			for(int j = 1; j <= cnt; j++)
			{
				scanf("%d", &v);
				Edge[v].push_back(i);
			}
		}
	
		for(int i = 1; i <= n; i++)
		{
			clear();
			sum = 0;
			dfs(i, 0);
			ans[i] = sum - 1;
		}

		scanf("%d", &k);
		for(int i = 1; i <= k; i++)
		{
			int p;
			scanf("%d", &p);
			printf("%d\n", ans[p]);
		}
	}

	return 0;
}
