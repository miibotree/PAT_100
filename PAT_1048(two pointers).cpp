//PAT_1048. Find Coins (25)
//Miibotree
//2015.2.26
//two pointers
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100001];
int m, n;

void TwoPointers()
{
	int i = 0, j = n - 1;

	while(i < j)
	{
		if(a[i] + a[j] == m)
		{
			printf("%d %d\n", a[i], a[j]);
			break;
		}
		else if(a[i] + a[j] < m)
			i++;
		else 
			j--;
	}
	if(i >= j)
		printf("No Solution\n");
}

int main()
{
	int i;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		TwoPointers();
	}
	return 0;
}