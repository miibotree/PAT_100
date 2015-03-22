#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
	int value;
	int lchild;
	int rchild;
}node[101];

int order[101];
int n;
int cnt = 0;
void InOrder(int x)
{
	if(node[x].lchild != -1)
		InOrder(node[x].lchild);
	node[x].value = order[cnt++];
	if(node[x].rchild != -1)
		InOrder(node[x].rchild);
}

void LevelOrder()
{
	cnt = 0;
	queue<int> q;
	q.push(0);
	while(q.empty() == false)
	{
		int x = q.front();
		q.pop();
		cnt++;
		if(cnt < n)
			printf("%d ", node[x].value);
		else
			printf("%d\n", node[x].value);
		if(node[x].lchild != -1)
			q.push(node[x].lchild);
		if(node[x].rchild != -1)
			q.push(node[x].rchild);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int L, R;
		scanf("%d %d", &L, &R);
		node[i].lchild = L;
		node[i].rchild = R;
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &order[i]);
	sort(order, order+n);
	InOrder(0);
	LevelOrder();
}