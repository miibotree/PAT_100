//PAT_1003. Emergency (25)
#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 501
using namespace std;

struct Edge
{
	int next;
	int c;
};
vector<Edge> edge[N];

int n, m, s, t;
int Dis[N], weight[N], w[N], mark[N], num[N];

void Dijkstra(int s)
{
	for(int i = 0; i < n; i++)
	{
		Dis[i] = -1;
		w[i] = 0;
		mark[i] = false;
		num[i] = 0;
	}
	Dis[s] = 0;
	w[s] = weight[s];
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
				num[t] = num[newP];
				w[t] = w[newP] + weight[t];
				Dis[t] = Dis[newP] + c;
			}
			else if(Dis[newP] + c == Dis[t])
			{
				num[t] += num[newP];
				if(w[newP] + weight[t] > w[t])
					w[t] = w[newP] + weight[t];
			}
		}
		int min = 0x3fffffff;
		for(int j = 0; j < n; j++)
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

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 0; i < n; i++)
		scanf("%d", &weight[i]);
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
	Dijkstra(s);
	printf("%d %d\n", num[t], w[t]);
	return 0;
}