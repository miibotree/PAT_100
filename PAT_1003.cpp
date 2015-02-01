//PAT_1003. Emergency (25)
//Miibotree
//2015.2.1
//Dijstra Algorithm

#include <stdio.h>
#include <vector>

using namespace std;

struct E{
	int next;
	int c;
};

vector<E> edge[5000];
bool mark[5000];
int Dis[5000];
int team[5000];
int cost[5000];
int num[5000];

int main()
{
	int n, m, c1, c2;
	while(scanf("%d%d%d%d", &n, &m, &c1, &c2) != EOF)
	{
		for(int i = 0; i < n; i++)
			edge[i].clear();
		for(int i = 0; i < n; i++)
			scanf("%d", &team[i]);
		while(m--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E tmp;
			tmp.c = c;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		for(int i = 0; i < n; i++)
		{
			Dis[i] = -1;
			mark[i] = false;
			cost[i] = 0;
			num[i] = 0;
		}
		Dis[c1] = 0;
		mark[c1] = true;
		cost[c1] = team[c1];
		num[c1] = 1;
		int newP = c1;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < edge[newP].size(); j++)
			{
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = team[t];
				if(mark[t] == true)
					continue;
				if(Dis[t] == -1 || Dis[newP]+c < Dis[t])//这里是关键点
				{
					Dis[t] =  Dis[newP] + c;
					cost[t] = cost[newP] + co;
					num[t] = num[newP];
				}
				else if(Dis[newP] + c == Dis[t])//这里是关键点
				{
					num[t] += num[newP];
					if(cost[newP]+co > cost[t])
					{
						Dis[t] =  Dis[newP] + c;
						cost[t] = cost[newP] + co;
					}
				}
			}
			int min1 = 999999999;
			for(int j = 0; j < n; j++)
			{
				if(mark[j] == true)
					continue;
				if(Dis[j] == -1)
					continue;
				if(Dis[j] < min1)
				{
					min1 = Dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		
		printf("%d %d\n", num[c2], cost[c2]);
	}
	return 0;
}