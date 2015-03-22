#include <stdio.h>
int main()
{
	int n;
	int a[1001];
	int m;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		for(int i = 0;i < n; i++)
			scanf("%d", &a[i]);

		for(int i = 0; i < n; i++)
		{
			if(a[i] != 1)
			{
				m = a[i];
				while(m != 1)
				{
					if(m % 2 == 0)
						m /= 2;
					else
						m = (3 * m + 1) / 2;
					for(int i = 0; i < n; i++)
					{
						if(a[i] == m)
							a[i] = 1;
					}
				}
			}
		}
		int flag = false;
		for(int i = n-1; i >= 0; i--)
		{
			if(a[i] != 1)
			{
				if(flag)
					printf(" %d", a[i]);
				else
				{
					printf("%d", a[i]);
					flag = true;
				}
			}
		}
		printf("\n");
	}
	return 0;
}