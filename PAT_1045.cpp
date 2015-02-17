//PAT_1045. Favorite Color Stripe (30)
//Miibotree
//2015.2.17
//最长公共子序列LCS的变种：相同元素可以重复
//递推公式：
//		dp[0][j] = 0; dp[i][0] = 0;
//		dp[i][j] = max(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
//需要掌握DP的深邃啊
//参考博客：http://blog.csdn.net/tiantangrenjian/article/details/19921051
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[10001];
int b[10001];
int dp[10001][10001];//m * l

int main()
{
	int n, m, l;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%d", &l);
		for(int i = 1; i <= l; i++)
			scanf("%d", &b[i]);

		for(int i = 0; i <= m; i++)
			dp[i][0] = 0;
		for(int i = 0; i <= l; i++)
			dp[0][i] = 0;

		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= l; j++)
			{
				if(a[i] != b[j])
				{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
				}
				else
				{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]) + 1;
				}
			}
		}
		printf("%d\n", dp[m][l]);
	}
	return 0;
}