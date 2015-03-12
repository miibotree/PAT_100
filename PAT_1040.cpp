//PAT_1040. Longest Symmetric String (25)
//使用二维DP求解
#include <stdio.h>
#include <string.h>
int dp[1001][1001];
char a[1001];
int main()
{
	gets(a);
	int ans = 1, L, i;
	int len = strlen(a);
	//step1.init
	for(i = 0; i < len; i++)
	{
		dp[i][i] = 1;
		if(i < len - 1)
		{
			if(a[i] == a[i+1])
			{
				dp[i][i+1] = 1;
				ans = 2;
			}
		}
	}
	//step2.dp 
	for(L = 3; L <= len; L++)
	{
		for(i = 0; i + L - 1 < len; i++)
		{
			int j = i + L - 1;
			if(a[i] == a[j] && dp[i+1][j-1] == 1)
			{
				dp[i][j] = 1;
				ans = L;
			}
			else
				dp[i][j] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}