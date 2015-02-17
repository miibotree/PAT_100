//PAT_1065. A+B and C (64bit) (20)
//Miibotree
//2015.2.17

#include <stdio.h>

int main()
{
	int n;
	long long a, b, c;
	long long res;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &a, &b, &c);
			long long res = a + b;
			if(a > 0 && b > 0 && res < 0)
				printf("Case #%d: true\n", i);
			else if(a < 0 && b < 0 && res >= 0)
				printf("Case #%d: false\n", i);
			else if(res > c)
				printf("Case #%d: true\n", i);
			else
				printf("Case #%d: false\n", i);
		}
	}
	return 0;
}