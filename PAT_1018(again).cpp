//PAT_1018. Public Bike Management (30)
//Dijkstra + DFS
#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 501
using namespace std;

struct Edge{
	int next;
	int c;
};
vector<Edge> edge[N];
vector<int> pre[N];
vector<int> path, temppath;
int Dis[N], mark[N], w[N], weight[N], num[N];

int n, m, Cmax, Sp;

void Dijkstra(int s)
{
	for(int i = 0; i <= n; i++)
	{
		Dis[i] = -1;
		mark[i] = false;
		num[i] = 0;
		pre[i].push_back(i);
	}
	Dis[s] = 0;
	mark[s] = true;
	num[s] = 1;
	int newP = s;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[newP] + c < Dis[t])
			{
				Dis[t] = Dis[newP] + c;
				num[t] = num[newP];
				pre[t].clear();
				pre[t].push_back(newP);
			}
			else if(Dis[t] == Dis[newP] + c)
			{
				num[t] += num[newP];
				pre[t].push_back(newP);
			}
		}
		int min = 0x3fffffff;
		for(int j = 1; j <= n; j++)
		{
			if(Dis[j] == -1 || mark[j] == true)
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
int optNeed = 0x3fffffff, optRemain = 0x3fffffff;

void DFS(int v)
{
	int Remain = 0, Need = 0;
	if(v == 0)//遍历到了起点
	{
		temppath.push_back(v);
		for(int i = temppath.size() - 2; i >= 0; i--)//需要倒着遍历,起点不用计算
		{
			int idx = temppath[i];
			if(weight[idx] > 0)
				Remain += weight[idx];
			else if(weight[idx] < 0)
			{
				if(Remain > abs(weight[idx]))//目前有的够给
				{
					Remain -= abs(weight[idx]);
				}
				else
				{
					Need += abs(weight[idx]) - Remain;
					Remain = 0;
				}
			}
		}
		if(Need < optNeed || Need == optNeed && Remain < optRemain)
		{
			path = temppath;
			optNeed = Need;
			optRemain = Remain;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	temppath.pop_back();
}
void PrintAns()
{
	printf("%d ", optNeed);
	for(int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d", path[i]);
		if(i != 0)
			printf("->");
	}
	printf(" %d\n", optRemain);
}

int main()
{	
	scanf("%d%d%d%d", &Cmax, &n, &Sp, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &weight[i]);
		weight[i] = weight[i] - Cmax / 2;
	}

	while(m--)
	{
		int c1, c2, c;
		scanf("%d%d%d", &c1, &c2, &c);
		Edge tmp;
		tmp.c = c;
		tmp.next = c1;
		edge[c2].push_back(tmp);
		tmp.next = c2;
		edge[c1].push_back(tmp);
	}
	Dijkstra(0);//从PBMC开始
	DFS(Sp);//从Sp开始从后往前
	PrintAns();
	return 0;
}