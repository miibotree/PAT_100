//DFS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[1001];
bool visit[1001];
int n, m, k, d;
int sum = 0;

void DFS(int x)
{
	if(x == d)
		return;
	visit[x] = true;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int v = edge[x][i];
		if(visit[v] == false)
			DFS(v);
	}
}

void  DFSTrave()
{
	for(int i = 1; i <= n; i++)
		visit[i] = false;
	for(int i = 1;i <= n; i++)
	{
		if(visit[i] == false && i != d)
		{
			sum++;//联通块个数
			DFS(i);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	while(m--)
	{
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		edge[c1].push_back(c2);
		edge[c2].push_back(c1);
	}
	while(k--)
	{
		scanf("%d", &d);
		sum = 0;
		DFSTrave();
		printf("%d\n", sum - 1);
	}
	return 0;
}