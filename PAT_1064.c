//PAT_1064. Complete Binary Search Tree (30)
//Miibotree
//2015.2.18
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, cnt;
int t[1001];
int a[1001];

void Inorder(int i)
{
	if(i * 2 <= n)// i*2为i结点的左孩子不为空
		Inorder(i * 2);
	t[i] = a[cnt++];
	if(i * 2 + 1 <= n)// i*2为i结点的左孩子不为空
		Inorder(i * 2 + 1);
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		//中序遍历顺序存储结构的二叉树
		cnt = 1;
		Inorder(1);
		printf("%d", t[1]);
		for(int i = 2; i <= n; i++)
			printf(" %d", t[i]);
		printf("\n");
	}
	return 0;
}
