#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
	int w;
	vector<int> child;
};
Node tree[101];
vector<int> path;
int n, m, weight;
bool cmp(int a, int b)
{
		return tree[a].w > tree[b].w;
}

void PrintPath()
{
	for(int i = 0; i < path.size(); i++)
	{
		if(i != 0)
			printf(" ");
		printf("%d", path[i]);
	}
	printf("\n");
}

void DFS(int idx, int sum)
{
	if(tree[idx].child.size() == 0 && sum == weight)
	{
		PrintPath();
		return;
	}
	for(int i = 0; i < tree[idx].child.size(); i++)
	{
		int child = tree[idx].child[i];
		path.push_back(tree[child].w);
		DFS(child, sum + tree[child].w);
		path.pop_back();
	}
}


int main()
{
	scanf("%d%d%d", &n, &m, &weight);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &tree[i].w);
	}
	while(m--)
	{
		int parent, num;
		scanf("%d%d", &parent, &num);
		for(int i = 0; i < num; i++)
		{
			int child;
			scanf("%d", &child);
			tree[parent].child.push_back(child);
		}
	}
	for(int i = 0;i < n; i++)
		sort(tree[i].child.begin(), tree[i].child.end(), cmp);

	path.push_back(tree[0].w);
	DFS(0, tree[0].w);//从根节点开始遍历
	return 0;
}