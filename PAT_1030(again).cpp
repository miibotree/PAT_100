//PAT_1030. Travel Plan (30)
#include <stdio.h>
#include <vector>
#define N 501
using namespace std;

struct Edge
{
	int next;
	int cost;
	int c;
};
vector<Edge> edge[N];
int Dis[N], Cost[N], mark[N], pre[N];
int s, t, n, m;

void Dijkstra(int s)
{
	for(int i = 0; i < n; i++)
	{
		Dis[i] = -1;
		Cost[i] = 0;
		mark[i] = false;
		pre[i] = i;
	}
	Dis[s] = 0;
	mark[s] = true;
	int newP = s;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			int cost = edge[newP][j].cost;
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[newP] + c < Dis[t])
			{
				Dis[t] = Dis[newP] + c;
				Cost[t] = Cost[newP] + cost;
				pre[t] = newP;
			}
			else if(Dis[newP] + c == Dis[t] && Cost[newP] + cost < Cost[t])
			{
				Cost[t] = Cost[newP] + cost;
				pre[t] = newP;
			}
		}
		int min = 0x3fffffff;
		for(int j = 0; j < n; j++)
		{
			if(mark[j] == true || Dis[j] == -1)
				continue;
			if(Dis[j] < min)
			{
				min = Dis[j];
				newP = j;
			}
		}
		mark[newP] = true;
	}
}

void PrintPath(int v)
{
	if(v == s)
	{
		printf("%d\n", s);
		return 0;
	}
	PrintPath(pre[v]);
	printf("%d ", v);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	while(m--)
	{
		int c1, c2, d, c;
		scanf("%d%d%d%d", &c1, &c2, &d, &c);
		Edge tmp;
		tmp.c = d;
		tmp.cost = c;
		tmp.next = c1;
		edge[c2].push_back(tmp);
		tmp.next = c2;
		edge[c1].push_back(tmp);
	}
	Dijkstra(s);
	PrintPath(t);//递归输出的
	printf("%d %d\n", Dis[t], Cost[t]);
	return 0;
}