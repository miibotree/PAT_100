//PAT_1013. Battle Over Cities (25)
//Miibotree
//2015.2.5
//并查集
//注意细节：结点总数1000，边总数最多1000×1000/2
#include <stdio.h>

int Tree[1001];
int f[1000*1000/2], t[1000*1000/2];

int FindRoot(int x)
{
	if(Tree[x] == -1)
		return x;
	else
	{
		int tmp = FindRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main()
{
	int n, m, k;
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{

		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &f[i], &t[i]);//先把边保存下来
		}

		for(int i = 1; i <= k; i++)
		{
			for(int j = 1; j <= n; j++)//初始化
				Tree[j] = -1;
			
			int x;
			scanf("%d", &x);
			for(int j = 1; j <= m; j++)
			{
				int a = f[j];
				int b = t[j];
				if(a == x || b == x)//由于战争破坏，该边无效
					continue;
				else
				{

					a = FindRoot(a);
					b = FindRoot(b);
					if(a != b)//由于输入的这条边可以使a b联通 故合并
						Tree[a] = b;
				}
			}
			//统计联通数
			int cnt = 0;
			for(int j = 1; j <= n; j++)
			{
				if(Tree[j] == -1)
					cnt++;
			}
			printf("%d\n", cnt-2);
		}
	}
}