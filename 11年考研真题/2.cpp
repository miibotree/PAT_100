#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
	a = a > b ? a : b;
	a = a > c ? a : c;
	return a;
}

float ans;
int p,t,g1,g2,g3,gj;

int main()
{

	while(scanf("%d %d %d %d %d %d", &p, &t, &g1, &g2, &g3, &gj) != EOF)
	{
		int diff = abs(g1 - g2);
		if(diff <= t)
			ans = (g1 + g2) / 2.0;
		else
		{
			int diff1 = abs(g1 - g3);
			int diff2 = abs(g2 - g3);
			if(diff1 <= t && diff2 <= t)
				ans = (float)max(g1, g2, g3);
			else if(diff1 <= t && diff2 > t)
				ans = (g1 + g3) / 2.0;
			else if(diff2 <= t && diff1 > t)
				ans = (g2 + g3) / 2.0;
			else
				ans = (float)gj;
		}
		printf("%.1f\n", ans);
	}
	return  0;
}