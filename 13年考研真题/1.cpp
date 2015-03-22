//PAT_1054. The Dominant Color (20)
//Miibotree
//2015.3.5
#include <stdio.h>
int main()
{
	int m, n, x;
	scanf("%d%d", &m, &n);
	scanf("%d", &x);
	int cnt = 1;
	int ans = x;
	for(int i = 2; i <= n * m; i++)
	{
		scanf("%d", &x);
		if(x == ans)
			cnt++;
		else
			cnt--;
		if(cnt == 0)
		{
			ans = x;
			cnt = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}