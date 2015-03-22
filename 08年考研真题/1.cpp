#include <stdio.h>
int main()
{
	int z[1000];
	long long a, b, c;
	int m;
	while(scanf("%d%lld%lld", &m, &a, &b) != EOF)
	{
		if(m == 0)
			break;
		c = a + b;
		int cnt = 0;
		do{
			z[cnt++] = c % m;
			c = c / m;
		}while(c != 0);
		for(int i = cnt - 1; i >= 0; i--)
			printf("%d", z[i]);
		printf("\n");
	}
	return 0;
}