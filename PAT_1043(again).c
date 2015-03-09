//PAT_ It a Binary Search Tree (25)
#include <stdio.h>

struct Node{
	Node *lchild;
	Node *rchild;
	int value;
}tree[1001];
int loc = 1;
int a[1001];
int preOrder[1001];
int MpreOrder[1001];
int postOrder[1001];
int MpostOrder[1001];
int cnt;
int n;

Node *Create()
{
	tree[loc].lchild = tree[loc].rchild = NULL;
	return &tree[loc++];
}


Node *Insert(Node *T, int x)
{
	if(T == NULL)
	{
		T = Create();
		T.value = x;
		return T;
	}
	if(x < T->value)//插入到左边
		T = Insert(T->lchild, x);
	else
		T = Insert(T->rchild, x);
	return T;
}


void GetPreOrder(Node *t)
{
	preOrder[cnt++] = t->value;
	if(t->lchild != NULL)
		GetPreOrder(t->lchild);
	if(t->rchild != NULL)
		GetPreOrder(t->rchild);
}

void GetMPreOrder(Node *t)
{
	MpreOrder[cnt++] = t->value;
	if(t->rchild != NULL)
		GetMPreOrder(t->rchild);
	if(t->lchild != NULL)
		GetMPreOrder(t->lchild);
}

void GetPostOrder(Node *t)
{
	if(t->lchild != NULL)
		GetPostOrder(t->lchild);
	if(t->rchild != NULL)
		GetPostOrder(t->rchild);
	postOrder[cnt++] = t->value;
}

void GetMPostOrder(Node *t)
{
	if(t->rchild != NULL)
		GetMPostOrder(t->rchild);
	if(t->lchild != NULL)
		GetMPostOrder(t->lchild);
	MpostOrder[cnt++] = t->value;
}

void Print(int a[])
{
	printf("YES\n");
	for(int i = 0; i < n; i++)
	{
		if(i != 0)
			printf(" ");
		printf("%d", a[i]);
	}
}

bool Compare(int a[], int b[])
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	Node *root;
	for(int i = 0 ; i < n; i++)
	{
		scanf("%d", &a[i]);
		root = Insert(root, a[i]);
	}
	cnt = 0;
	GetPreOrder(root);
	cnt = 0;
	GetMPreOrder(root);
	cnt = 0;
	GetPostOrder(root);
	cnt = 0;
	GetMPostorder(root);
	if(Compare(a, preOrder) == true)
		Print(PostOrder);
	else if(Compare(a, MpreOrder) == true)
		Print(MPostOrder);
	else
		printf("NO\n");
	return 0;
}