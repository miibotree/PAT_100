//PAT_1085. Perfect Sequence (25)
//使用two pointers重写本题代码
//Miibotree
//2015.2.25
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[100001];
int main()
{
	int n;
	LL p;
	while(scanf("%d%lld", &n, &p)!= EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &a[n]);
		sort(a, a+n);
		int i = 0, j = 0;
		int count = 0;
		while(i <= j)
		{
			LL x = a[i] * p;
			if(a[j] > x)
				i++;
			else if(a[j] == x)
			{
				count = max(count, j-i);
				i++;j++;
			}
			else
				j++;
		}
		printf("%d\n", count);
	}
}