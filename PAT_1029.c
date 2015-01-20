//PAT_1029. Median (25)
//Miibotree
//2015.1.20
#include <stdio.h>
#define MAX 1000005
int a[MAX], b[MAX];

int main()
{
	int m, n;
	while(scanf("%d",&m) != EOF)
	{
		for (int i = 0 ; i < m; i++)
			scanf("%d", &a[i]);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		int mid = (n+m-1)/2;
		int i = 0,j = 0, cnt = 0, last;
		while (cnt <= mid)
		{
			if (i < m && j < n)
			{
				if(a[i] < b[j])
				{
					last = a[i];
					i++;
				}
				else
				{
					last = b[j];
					j++;
				}
			}
			else if(i == m && j < n)
			{
				last = b[j];
				j++;
			}
			else
			{
					last = a[i];
					i++;
			}
			cnt++;
		}
		printf("%d\n", last);
	}
	return 0;
}


/*sort显示的是答案错误，而不是超时。。。
#include <stdio.h>
#include <algorithm>
using namespace std;
long int a[2000003];
int main()
{
	int m, n;
	while(scanf("%d",&m) != EOF)
	{
		for (int i = 0 ; i < m; i++)
			scanf("%d", &a[i]);
		scanf("%d", &n);
		for (int i = m; i < n+m; i++)
			scanf("%d", &a[i]);
		sort(a,a+m+n);
		printf("%d\n", a[(m+n)/2]);
	}
	return 0;	
}
*/