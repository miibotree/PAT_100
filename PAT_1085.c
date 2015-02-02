//PAT_1085. Perfect Sequence (25)
//Miibotree
//2015.2.2
//考察二分查找

#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	long long p;
	int n;
	long long int a[100010];
	while(scanf("%d%lld", &n, &p) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		sort(a, a+n);
		
		int ans = 0;
		long long x;
		for(int i = 0; i < n; i++)
		{
			x = a[i] * p;
			if(a[n-1] <= x)
			{
				ans = max(ans, n-i);
				continue;
			}
			int l, m, h;
			l = i; h = n-1;
			while(l+1 < h)//注意这里，相差1时会跳出循环
			{
				m = (l+h)/2;
				if(a[m] > x)
					h = m;
				else
					l = m;
			}
			ans = max(ans, h-i);//注意这里是h-i 而不是h-l！！
		}
		printf("%d\n", ans);
	}
	return 0;
}