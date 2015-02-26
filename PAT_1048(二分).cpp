//PAT_1048. Find Coins (25)
//Miibotree
//2015.2.26
//二分
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100001];

int BinarySearch(int L, int R, int key)
{
	int left = L, right = R, middle;
	while(left <= right)
	{
		middle = (left + right) / 2;
		if(a[middle] == key)
			return middle;
		else if(a[middle] < key)
			left = middle + 1;
		else
			right = middle - 1;
	} 
	return -1;
}

int main()
{
	int m, n, i;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		for(i = 0; i < n; i++)
		{
			int j = BinarySearch(i, n-1, m-a[i]);
			if(i != j && j != -1)
			{
				printf("%d %d\n", a[i], m-a[i]);
				break;
			}
		}
		if(i == n)
			printf("No Solution\n");
	}
	return 0;
}