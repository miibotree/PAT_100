#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100001];
int n, m;

bool cmp(int x, int y)
{
	if(x != y)
		return x > y;
}

int main()
{
	while(scanf("%d%d", &n, m&) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n,cmp);
		if(n < m)
			m = n;
		int sum = 0;
		for(int i = 0; i < m; i++)
			sum+=a[i];
		for(int i = 0; i < m; i++)
		{
			if(i != 0)
				printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return  0;
}