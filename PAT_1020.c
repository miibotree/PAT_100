//PAT_1020  Tree Traversals (25)
//Miibotree
//2015.1.15

//Binary Tree Trace
//Miibotree
//2015.1.15
//输入后序 中序 输出层次

#include <stdio.h>
#include <string.h>

typedef struct Node{
	Node *lchild;
	Node *rchild;
	int value;
}BT[31];

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
		LevelOrder(BT, n);
	}
	return 0;
}

void LevelOrder(Node *BT, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%d\n", BT[i].value);
		else
			printf("%d ", BT[i].value);
	}
}


Node *Create()
{
	BT[pos].lchild == NULL;
	BT[pos].rchild == NULL;
	return &BT[pos++];
}



void Build(int s1, int e1, int s2, int e2)
{
	Node *ret = Create();
	ret->value = post_order[e1];//后序遍历的最后一个节点肯定是根节点
	int roorIdx;
	for (int i = s2; i <= e2; i++)
	{
		if (in_order[i] == ret->value)
		{
			rootIdx = i;
			break;
		}
	}
	if (rootIdx != s2)
		Build(s1, s1+(rootIdx-s2)-1, s2, rootIdx-1);
	if (rootIdx != e2)
		Build(s1+(rootIdx-s2), e1-1, roorIdx+1, e2);
	return ret;
}

