//PAT_1076. Forwards on Weibo (30)
//Miibotree
//2015.2.27
//BFS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int id;
	int level;
};

vector<Edge> edge[1001];
queue<int> q;
int flag[1001];
int ans[1001];
int sum;
int L;

void clear()
{
	for(int i = 0; i < 1001; i++)
		flag[i] = false;
}

void bfs(int x, int depth)
{
	while(q.empty() == false)	q.pop();
	Edge start;
	start.id = x;
	start.level = 0;
	q.push(start);
	flag[start.id] = true;
	while(!q.empty())
	{
		Edge top = q.front();
		q.pop();
		int u = top.id;
		for(int i = 0; i < edge[u].size(); i++)
		{
			Edge next = edge[u][i];
			next.level = top.level + 1;
			if(flag[next.id] == false && edge[next.id].level <= L)
			{
				sum++;
				flag[next.id] = true;
				q.push(next);
			}			
		}
	}
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
				Edge tmp;
				tmp.id = i; 
				edge[v].push_back(tmp);
			}
		}
	
		for(int i = 1; i <= n; i++)
		{
			clear();
			sum = 0;
			bfs(i, 0);
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
