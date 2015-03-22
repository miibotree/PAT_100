#include <stdio.h>
int n, m;
long int a[1000001], b[1000001];

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
			scanf("%d", &b[i]);
		int middle = (n + m + 1) / 2;
		int i = 1, j = 1;
		int cnt = 0;
		long int ans = 0;
		while(cnt < middle)
		{
			if(i <= n && j <= m)
			{
				if(a[i] < b[j])
				{
					ans = a[i];
					cnt++;
					i++;
				}
				else
				{
					ans = b[j];
					cnt++;
					j++;
				}
			}
			else if(i > n && j <= m)
			{
				ans = b[j];
				cnt++;
				j++;
			}
			else if(i <= n && j > m)
			{
				ans = a[i];
				cnt++;
				i++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}