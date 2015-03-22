#include <stdio.h>
int main()
{
	int m, n;
	int a[20][20], b[20][20], c[20][20];
	while(scanf("%d%d", &m, &n) != EOF)
	{
		if(m == 0)
			break;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%d", &b[i][j]);
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; i++)
		{
			int flag = true;
			for(int j = 1; j <= n; j++)
			{
				if(c[i][j] != 0)
					flag = false;
			}
			if(flag)
				ans++;
		}
		for(int j = 1; j <= n; j++)
		{
			int flag = true;
			for(int i = 1; i <= m; i++)
			{
				if(c[i][j] != 0)
					flag = false;
			}
			if(flag)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}