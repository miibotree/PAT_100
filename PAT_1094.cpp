//PAT_1094. The Largest Generation (25)
//Miibotree
//2015.3.22
#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct node
{
	int level;
	vector<int> c;
}tree[101];

int n, m;
int levelNum[30];

void BFS()
{
	queue<int> q;
	tree[1].level = 1;
	levelNum[1] = 1;
	q.push(1);//序号入队列
	while(q.empty() == false)
	{
		int x = q.front();
		q.pop();
		int nowLevel = tree[x].level;
		for(int i = 0; i < tree[x].c.size(); i++)
		{
			int next = tree[x].c[i];
			tree[next].level = nowLevel + 1;
			levelNum[tree[next].level]++;
			q.push(next);
		} 
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int num, root, child;
		scanf("%d%d", &root, &num);
		for(int j = 0; j < num; j++)
		{
			scanf("%d", &child);
			tree[root].c.push_back(child);
		}
	}
	BFS();
	int ans = -1, ansLevel = -1;
	for(int i = 1; i < 30; i++)
	{
		if(levelNum[i] > ans)
		{
			ans = levelNum[i];
			ansLevel = i;
		}
	}
	printf("%d %d", ans, ansLevel);
	return 0;
}