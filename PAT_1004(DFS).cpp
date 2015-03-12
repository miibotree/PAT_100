//DFS进行树的遍历
#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 101
using namespace std;
vector<int>tree[N];
int n, m;
int cnt[N];
int maxH = 1;
void DFS(int x, int depth)
{
	if(depth > maxH)
		maxH = depth;
	if(tree[x].size() == 0)
	{
		cnt[depth]++;
		return;
	}
	for(int i = 0; i < tree[x].size(); i++)
	{
		int v = tree[x][i];
		DFS(v, depth + 1);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int parent, num, child;
		scanf("%d%d", &parent, &num);
		for(int i = 0; i < num; i++)
		{
			scanf("%d", &child);
			tree[parent].push_back(child);
		}
	}
	DFS(1, 1);
	for(int i = 1; i <= maxH; i++)
	{
		if(i != 1)
			printf(" ");
		printf("%d", cnt[i]);
	}
	return 0;
}