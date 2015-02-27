//PAT_1030. Travel Plan (30)
//Miibotree
//2015.2.1

#include <stdio.h>
#include <vector>

using namespace std;
struct E
{
	int next;
	int cost;
	int c;
};
vector<E> edge[501];
int dis[501];
int cost[501];
bool mark[501];
int path[501];

int main()
{
	int n, m, s, d;
	while(scanf("%d%d%d%d", &n, &m, &s, &d) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			edge[i].clear();
			mark[i] = false;
			dis[i] = -1;
			cost[i] = 0;
			path[i] = -1;
		}
		for (int i = 0; i < m; i++)
		{
			int c1, c2, a, b;
			scanf("%d%d%d%d", &c1, &c2, &a, &b);
			E tmp;
			tmp.c = a;
			tmp.cost = b;
			tmp.next = c2;
			edge[c1].push_back(tmp);
			tmp.next = c1;
			edge[c2].push_back(tmp);
		}
		mark[s] = true;
		dis[s] = 0;
		int newP = s;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < edge[newP].size(); j++)//当时这里写错了。。。好好反省
			{
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = edge[newP][j].cost;
				if(mark[t] == true)
					continue;
				if(dis[t] == -1 || dis[t] > dis[newP] + c ||
					(dis[t] == dis[newP] + c && cost[t] > cost[newP] + co) )
				{
					dis[t] = dis[newP] + c;
					cost[t] = cost[newP] + co;
					path[t] = newP;
				}
			}
			int min = 0x7fffffff;
			for(int j = 0; j < n; j++)
			{
				if(mark[j] == true)
					continue;
				if(dis[j] == -1)
					continue;
				if(dis[j] < min)
				{
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}

		int x = d;
		int record[503];
		int cnt = 0;
		while(x != s)
		{
			record[cnt++] = x;
			x = path[x];
		}
		record[cnt]=x;
		for(int i = cnt; i >= 0; i--)
			printf("%d ", record[i]);

		printf("%d %d\n", dis[d], cost[d]);
	}
	return 0;
}