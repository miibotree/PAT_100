//最小生成树
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Edge{
	int a, b;
	int cost;
	bool operator < (const Edge &A) const{
        return cost < A.cost;
	}
}edge[600];

int tree[101];

bool cmp(Edge x, Edge y)//用sort会出错
{
	if(x.cost != y.cost)
		return x.cost > y.cost;
}

int findRoot(int x)
{
	if(tree[x] == -1)
		return x;
	else
	{
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}
int main()
{
	int cost, state;
	int n;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		int m = n * (n - 1) / 2;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d%d", &edge[i].a, &edge[i].b, &cost, &state);
			if(state == 1)
				cost = 0;
			edge[i].cost = cost;
		}
		sort(edge, edge + m);
		for(int i = 1; i <= n; i++)
			tree[i] = -1;
		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);
			if(a != b)
			{
				tree[a] = b;
				ans += edge[i].cost;
			}
		}
		printf("%d\n", ans);
	} 
	return 0;
}