//upper_bound
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	int n;
	LL a[100001];
	LL p;
	scanf("%d%lld", &n, &p);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a+n);
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		LL x = p * a[i];
		int j = upper_bound(a, i+1, i+n) - a;
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
	return 0;
}