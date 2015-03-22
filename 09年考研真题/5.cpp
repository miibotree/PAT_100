//并查集
#include <stdio.h>

int tree[256];

int find(int a, int b)
{
	int depth = 1;
	while(tree[a] != b && tree[a] != -1)
	{
		a = tree[a];
		depth++;
	}
	if(tree[a] == -1 && a != b)//没有找到
		return -1;
	else
		return depth;
}

int main()
{
	int n, m;
	char c, fa, mo;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < 256; i++)
			tree[i] = -1;
		for(int i = 0; i < n; i++)
		{
			getchar();
			scanf("%c%c%c", &c, &fa, &mo);
			if(fa != '-')
				tree[fa] = c;
			if(m != '-')
				tree[mo] = c;
		}
		while(m--)
		{
			char a, b;
			int depth = 0;
			getchar();
			scanf("%c%c", &a, &b);
			depth = find(a,b);
			if(depth > 0)
			{
				if(depth == 1)
					printf("parent\n");
				else if(depth == 2)
					printf("grandparent\n");
				else
				{
					for(int i = 1; i <= depth - 2; i++)
						printf("great-");
					printf("grandparent\n");
				}
			}
			else
			{
				depth = find(b,a);
				if(depth > 0)
				{
					if(depth == 1)
						printf("child\n");
					else if(depth == 2)
						printf("grandchild\n");
					else
					{
						for(int i = 1; i <= depth - 2; i++)
							printf("great-");
						printf("grandchild\n");
					}
				}
				else
					printf("-\n");
			}
		}
	}
	return 0;
}