//PAT_1068.Find More Coins (30)
//Miibotree
//2015.2.21
//DP动态规划
//0-1背包问题  
//		1.要求正好装满
//		2.要求回溯输出路径
//		3.选择最小串，一开始从大到小进行排序

#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 10001;
const int maxv = 101;
int w[maxn], dp[maxv] = {0};
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		for(int i = 1; i <= n; i++)//dp递归方程
		{
			for(int j = m; j >= w[i]; j--)
			{
				if(dp[j] <= dp[j - w[i]] + w[i])
				{
					dp[j] = dp[j - w[i]] + w[i];
					choice[i][j] = 1;
				}
				eles
					choice[i][j] = 0;
			}
		}
		if(dp[m] != m)
			printf("No Solution\n");
		else
		{
			int k = n, num = 0, v = m;
			while(k >= 0)
			{
				if(choice[k][v] == 1)
				{
					flag[k] = true;
					v -= w[k];
					num++;
				}
				else
					flag[k] = false;
				k--;
			}
			for(int i = n; i >= 1; i--)
			{
				if(flag[i] == true)
				{
					printf("%d\n", w[i]);
					num--;
					if(num > 0)	printf(" ");
				}
			}
		}
	}
	return 0;
}

