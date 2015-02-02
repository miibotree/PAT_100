//PAT_1087. All Roads Lead to Rome (30)
//Miibotree
//2015.2.2
//Dijkstra Algorithm
//1.主要算法是dijkstra
//2.可能有多条最短路径，需要记录
//3.需要记录path
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

struct E{
	int next;
	int c;
};

vector<E> edge[1000];
bool mark[201];
char city[201][4];
int path[201];
int cost[201];
int happy[201];
int dis[201];
int num[201];

int find(char *str, int n)
{
	for (int i = 0; i < n; i++)
	{
		if(!strcmp(str, city[i]))
			return i;
	}
	return -1;
}

int main()
{
	int n, k;
	int d;//记录rome的编号
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i = 0; i < n; i++)//init
		{
			edge[i].clear();
			mark[i] = false;
			path[i] = -1;
			dis[i] = -1;
			cost[i] = 0;
			num[i] = 0;
		}

		scanf("%s", city[0]);
		for(int i = 1; i < n; i++)
		{
			scanf("%s %d", city[i], &happy[i]);
			if(!strcmp(city[i], "ROM"))
				d = i;
		}
		while(k--)
		{
			char str1[4], str2[4];
			int c;
			scanf("%s %s %d", str1, str2, &c);
			int a = find(str1, n);
			int b = find(str2, n);
			E tmp;
			tmp.c = c;
			tmp.next = a;
			edge[b].push_back(tmp);
			tmp.next = b;
			edge[a].push_back(tmp);
		}
		dis[0] = 0;
		mark[0] = true;
		num[0] = 1;
		int newP = 0;
		for(int i = 1; i < n; i++)
		{
			for (int j = 0; j < edge[newP].size(); j++)
			{
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = happy[t];
				if(mark[t] == true)
					continue;
				if(dis[t] == -1 || dis[newP]+c < dis[t])
				{
					dis[t] = dis[newP] + c;
					cost[t] = cost[newP] + co;
					num[t] = num[newP];
					path[t] = newP;
				}
				else if(dis[newP] + c == dis[t])
				{
					num[t] += num[newP];
					if(cost[newP] + co > cost[t])
					{
						dis[t] = dis[newP] + c;
						cost[t] = cost[newP] + co;
						path[t] = newP;
					}
				}
			}
			int min = 999999999;
			for(int j = 0; j < n; j++)
			{
				if(mark[j] == true || dis[j] == -1)
					continue;
				if(dis[j] < min)
				{
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		printf("%d %d %d ", num[d], dis[d], cost[d]);

		int x = d;
		int record[503];
		int cnt = 0;
		while(x != 0)
		{
			record[cnt++] = x;
			x = path[x];
		}
		record[cnt]=x;
		printf("%d\n", cost[d]/cnt);
		for(int i = cnt; i > 0; i--)
			printf("%s->", city[record[i]]);
		printf("%s\n", city[record[0]]);

	}
	return 0;
}