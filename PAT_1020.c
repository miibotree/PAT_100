//PAT_1020  Tree Traversals (25)
//Miibotree
//2015.1.15

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	int value;
}BT[31];

queue<Node*> q;

void LevelOrder(Node *BT, int n);
Node *Create();
Node* Build(int s1, int e1, int s2, int e2);

int post_order[31];
int in_order[31];
int pos;

int main()
{
	int n = 0;

	while(scanf("%d", &n) != EOF)
	{
		pos = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &post_order[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &in_order[i]);
		Node *T = Build(0, n-1, 0, n-1);
		LevelOrder(T, n);
	}
	return 0;
}

void LevelOrder(Node *BT, int n)
{
	int cnt = 0;
	while(q.empty() == false)
		q.pop();
	Node* p;
	q.push(BT);
	while(q.empty() == false)
	{
		p = q.front();
		q.pop();

		if (cnt < n-1)
		{
			printf("%d ", p->value);
			cnt++;
		}
		else
			printf("%d\n", p->value);

		if (p->lchild != NULL)
			q.push(p->lchild);
		if (p->rchild != NULL)
			q.push(p->rchild);

	}
}


Node *Create()
{
	BT[pos].lchild = NULL;
	BT[pos].rchild = NULL;
	return &BT[pos++];
}



Node* Build(int s1, int e1, int s2, int e2)
{
	Node *ret = Create();
	ret->value = post_order[e1];//后序遍历的最后一个节点肯定是根节点
	int rootIdx;
	for (int i = s2; i <= e2; i++)
	{
		if (in_order[i] == ret->value)
		{
			rootIdx = i;
			break;
		}
	}
	if (rootIdx != s2)
		ret->lchild = Build(s1, s1+(rootIdx-s2)-1, s2, rootIdx-1);
	if (rootIdx != e2)
		ret->rchild = Build(s1+(rootIdx-s2), e1-1, rootIdx+1, e2);
	return ret;
}

