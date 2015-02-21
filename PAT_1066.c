//PAT_1066. Root of AVL Tree (25)
//Miibotree
//2015.2.21
//写一个avl树
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node
{
	int value;
	int bf;
	Node *lchild;
	Node *rchild;
}AVLTree[21];

int loc;

Node *Create();
Node* Insert(Node *T, int x);
int Height(Node *T);
Node *LeftLeft(Node *T);
Node *RightRight(Node *T);
Node *LeftRight(Node *T);
Node *RightLeft(Node *T);

int main()
{
	int n, x;
	while(scanf("%d", &n) != EOF)
	{
		Node *T = NULL;
		loc = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			T = Insert(T, x);
		}
		printf("%d\n", T->value);
	}
}

Node *Create()
{
	AVLTree[loc].lchild = AVLTree[loc].rchild = NULL;
	return &AVLTree[loc++];
}

Node* Insert(Node *T, int x)
{
	if(T == NULL)//当前树为空
	{
		T = Create();
		T->value = x;
		T->bf = 0;
	}
	else if(x < T->value)//插入到左子树
	{
		T->lchild = Insert(T->lchild, x);
		if(Height(T->lchild) - Height(T->rchild) == 2)
		{
			if(x < T->lchild->value)
				T = LeftLeft(T);//LL
			else
				T = LeftRight(T);//LR
		}
	}
	else if(x > T->value)
	{
		T->rchild = Insert(T->rchild, x);
		if(Height(T->lchild) - Height(T->rchild) == -2)
		{
			if(x > T->rchild->value)
				T = RightRight(T);//RR
			else
				T = RightLeft(T);//RL
		}
	}
	T->bf = max(Height(T->lchild), Height(T->rchild)) + 1;
	return T;
}

int Height(Node *T)
{
	if(T == NULL)
		return -1;
	else
		return T->bf;
}

Node *LeftLeft(Node *T)
{
	Node *root;
	Node *pivot;
	root = T;
	pivot = T->lchild;
	root->lchild = pivot->rchild;
	pivot->rchild = root;
	root->bf = max(Height(root->lchild), Height(root->rchild)) + 1;
	pivot->bf = max(Height(pivot->lchild), Height(pivot->rchild)) + 1;
	return pivot; 
}

Node *RightRight(Node *T)//RR 左旋
{
    Node* root, *pivot;
    root = T;
    pivot = T->rchild;
    root->rchild = pivot->lchild;
    pivot->lchild = root;
 
    root->bf  = max(Height(root->lchild), Height(root->rchild)) + 1;
    pivot->bf = max(Height(pivot->lchild), Height(pivot->rchild)) + 1;
    return pivot;
}
 
Node *LeftRight(Node *T)//LR pivot左旋 root右旋
{
    T->lchild = RightRight(T->lchild);
    return LeftLeft(T);
}
 
Node *RightLeft(Node *T)//RL pivot右旋 root左旋
{
    T->rchild = LeftLeft(T->rchild);
    return RightRight(T);
}