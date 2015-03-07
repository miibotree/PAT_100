//PAT_1037. Magic Coupon (25)
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int a[100001], b[100001];
	int m, n;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + m);
	sort(b, b + n);

	int i = 0; j = 0;
	int sum = 0;
	while(a[i] < 0 && b[j] < 0)
		sum += a[i++] * b[j++];
	i = m - 1; 
	j = n - 1;
	while(a[i] > 0 && b[j] > 0)
		sum += a[i--] * b[j--];
	printf("%d\n", sum);

	return 0;
}