#include <stdio.h>
#include <queue>
#include <vector>
#define MAXN 101
using namespace std;
struct Node
{
	vector<int> c;
	int level;
	int id;
};

vector<Node> tree[MANX];
int cnt[MANX];

void BFS()//区号进入队列就好了
{
	tree[1].level = 1;
	queue<int> q;
	q.push(1);
	while(q.empty() == false)
	{
		int idx = q.front();
		int nowLevel = tree[idx].level;
		q.pop();
		//判断当前节点是不是叶子节点
		if(tree[idx].child.size() == 0)//是叶子节点
			cnt[tree[idx].level]++;
		else//不是叶子节点，所有的孩子节点入队列
		{
			for(int i = 0; i < tree[idx].child.size(); i++)
			{
				int next = tree[idx].child[i];
				tree[next].level = nowLevel + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		tree[i].id = i;
		tree[i].level = 0;
	}
	while(k--)
	{
		int parent, child, num;
		scanf("%d %d", &parent, &num);
		for(int i = 0; i < num; i++)
		{
			scanf("%d", &child);
			tree[parent].c.push_back(child);
		}
	}
	BFS();
	for(int i = 1; i <= n; i++)
	{
		if(i != 1)
			printf(" ");
		printf("%d", cnt[i]);
	}
}