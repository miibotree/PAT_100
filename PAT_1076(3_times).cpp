#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
	int level;
	int id;
};
vector<int> edge[1001];
int n, L, k;
bool inq[1001];
int sum = 0;
bool BFS(Node x)
{
	queue<Node> q;
	q.push(x);
	inq[x.id] = true;
	while(q.empty() == false)
	{
		int top = q.fornt();
		q.pop();
		sum++;
		int u = top.id;
		int nowLevel = top.level;
		for(int i = 0; i < edge[u].size(); i++)
		{
			Node newNode;
			int next = edge[u][i].id;
			int nextLevel = nowLevel + 1;
			newNode.next = next;
			newNode.level = nextLevel;
			if(inq[next] == false && nextLevel <= L)
			{
				inq[next] = true;
				q.push(newNode);
			}
		}
	}
}


int main()
{
	scanf("%d%d", &n, &L);
	for(int i = 1; i <= n; i++)
	{
		int num = 0;
		scanf("%d", &num);
		for(int j = 0; j < num; j++)
		{
			int x;
			scanf("%d", &x);
			edge[x].push_back(i);
		}	
	}
	scanf("%d", &k);
	while(k--)
	{
		int query;
		scanf("%d", &query);
		for(int i = 1; i <= n; i++)
			inq[i] = false;

		Node tmp;
		tmp.id = query;
		tmp.level = 0;
		sum = 0;
		BFS(tmp);
		printf("%d\n", sum - 1);
	}
	return 0;
}