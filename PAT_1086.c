//PAT_1086. Tree Traversals Again (9/25 segment fault)
//Miibotree
//2015.1.16
//思路：由前序遍历和中序遍历确定一颗二叉树，然后输出后序遍历

#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

stack<int> s;

struct Node
{
	Node *lchild;
	Node *rchild;
	int value;
}Tree[100];

int loc = 0;
int j = 1;
int prenum[100];//前序遍历
int innum[100];//中序遍历

void PostOrder(Node *T, int n);
Node *Create();
Node *Build(int s1, int e1, int s2, int e2);

int main()
{
	int n = 0;
	char str[100];
	int a = 0;

	while (scanf("%d", &n) != EOF)
	{
		loc = 0;
		while(s.empty() == false) s.pop();
		for (int i = 0; i < n; i++)
			prenum[i] = i+1;
		int cnt = 0;
		getchar();
		for (int i = 1; i <= 2*n; i++)
		{
			scanf("%s", str);
			if (!strcmp(str, "Push"))
			{
				scanf("%d", &a);
				s.push(a);
			}
			else if(!strcmp(str, "Pop"))
			{
				innum[cnt++] = s.top();
				s.pop();
			}
		}

		Node *T = Build(0, n-1, 0, n-1);
		j = 1;
		PostOrder(T, n);
	}
}


void PostOrder(Node *T, int n)
{
	if (T->lchild != NULL)
		PostOrder(T->lchild, n);
	if (T->rchild != NULL)
		PostOrder(T->rchild, n);
	if (j < n)
	{
		printf("%d ", T->value);
		j++;
	}
	else
		printf("%d\n", T->value);
}

Node *Create()
{
	Tree[loc].lchild = NULL;
	Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

Node *Build(int s1, int e1, int s2, int e2)
{
	Node *ret = Create();
	ret->value = prenum[s1];
	int rootIdx;
	for (int i = s2; i <= e2; i++)
	{
		if (innum[i] == ret->value)
		{
			rootIdx = i;
			break;
		}
	}
	if (rootIdx != s2)				//注意这里rootIdx-s2为左子树的长度
		ret->lchild  = Build(s1+1, s1+rootIdx-s2, s2, rootIdx-1);//遍历左子树
	if (rootIdx != e2)
		ret->rchild  = Build(s1+rootIdx-s2+1, e1, rootIdx+1, e2);//遍历右子树
	return ret;
}