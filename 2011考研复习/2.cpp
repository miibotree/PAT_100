#include <stdio.h>
#include <queue>
using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	int value;
}t[31];
int loc = 0;


int n;
int postOrder[31];
int inOrder[31];

Node *Create()
{
	t[loc].lchild = t[loc].rchild = NULL;
	return &t[loc++];
}

Node *Build(int postL, int postR, int inL, int inR)
{
	Node *root = Create();
	root->value = postOrder[postR];
	int k;//在中序遍历中找到根节点
	for(int i = inL; i <= inR; i++)
	{
		if(inOrder[i] == root->value)
		{
			k = i;
			break;
		}
	}
	int numLeft = k - inL;
	if(k != inL)
		root->lchild = Build(postL, postL + numLeft - 1, inL, k - 1);
	if(k != inR)
		root->rchild = Build(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}

void LevelOrder(Node * t)
{
	int cnt = 0;
	queue<Node *>q;
	q.push(t);
	while(q.empty() == false)
	{
		Node *tmp;
		tmp = q.front();
		q.pop();
		cnt++;
		if(cnt != n)
			printf("%d ", tmp->value);
		else
			printf("%d\n", tmp->value);
		if(tmp->lchild != NULL)
			q.push(tmp->lchild);
		if(tmp->rchild != NULL)
			q.push(tmp->rchild);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &postOrder[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &inOrder[i]);
	Node *root = NULL;
	root = Build(0, n-1, 0, n-1);
	LevelOrder(root);
	return 0;
}