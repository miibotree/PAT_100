//PAT_1007. Maximum Subsequence Sum (25)
//Miibotree
//2015.2.3
#include <stdio.h>

int main()
{
	int k;
	int a[10010];
	while(scanf("%d", &k) != EOF)
	{
		int begin, end;
		int temp, sum;

		for(int i = 0; i < k; i++)
			scanf("%d", &a[i]);
		begin = 0;end = 0;sum = -1;
		for(int i = 0; i < k; i++)
		{
			temp = 0;
			for(int j = i; j < k; j++)
			{
				temp += a[j];
				if(temp > sum)
				{
					sum = temp;
					begin = i;
					end = j;
				}
			}
		}
		if(sum < 0)
			printf("0 %d %d\n", a[0], a[k-1]);
		else
			printf("%d %d %d\n", sum, a[begin], a[end]);
	}
	return 0;
}