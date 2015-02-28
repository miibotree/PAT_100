//PAT_1085. Perfect Sequence (25)
//使用two pointers重写本题代码
//Miibotree
//2015.2.25
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[100010];
int main()
{
	int n;
	LL p;
	while(scanf("%d%lld", &n, &p)!= EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		sort(a, a+n);
		int i = 0, j = 0;
		int count = 0;
		while(i < n && j < n)
		{
			LL x = a[i] * p;
			while(j < n && a[j] <= x)
			{
				count = max(count, j-i+1);
				j++;
			}
			i++;
		}
		printf("%d\n", count);
	}
}