//PAT_1053. Path of Equal Weight (30)
//Miibotree
//2015.3.2
//一般树的表示方法和树的DFS遍历，路径的表示
#include <stdio.h>
#include <vector>
#include <algorithm>
#define maxn 101
using namespace std;

struct Node
{
	int weight;
	vector<int> child;
}tree[maxn];

vector<int> path;

int n, m, s;

void Print()
{
	int i;
	for(i = 0; i < path.size() - 1; i++)
	{
		printf("%d ", tree[path[i]].weight);
	}
	printf("%d\n", tree[path[i]].weight);
}

void DFS(int idx, int sum)
{
	if(sum > s)
		return;
	else if(sum == s)//打印路径
	{
		if(tree[idx].child.size() == 0)//叶子节点才打印
			Print();
		else//递归出口，后面不必再遍历了
			return;
	}
	else//sum < s
	{
		for(int i = 0; i < tree[idx].child.size(); i++)
		{
			int newIdx = tree[idx].child[i];
			path.push_back(newIdx);//遍历前入vector
			DFS(newIdx, sum + tree[newIdx].weight);
			path.pop_back();//出来后出vector，回溯思想
		}
	}
}

bool cmp(int a, int b)
{
	return tree[a].weight > tree[b].weight;
}

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; i++)
		scanf("%d", &tree[i].weight);
	for(int i = 0; i < m; i++)
	{
		int num, root;
		scanf("%d %d", &root, &num);
		for(int j = 0; j < num; j++)
		{
			int c;
			scanf("%d", &c);
			tree[root].child.push_back(c);
		}
		//对所有孩子节点递增排序
		sort(tree[root].child.begin(), tree[root].child.end(), cmp);
	}
	//当前访问的节点编号，当前路径上的权值和
	path.push_back(0);
	DFS(0, tree[0].weight);
	return 0;
}