//二分查找，使用upper_bound函数
//参考晴神的代码
//Miibotree
//2015.2.25
//sum[j] - sum[i - 1] = S
//sum[j] = S + sum[i - 1]
#include <cstdio>
const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

int upper_bound(int L, int R, int x)
{
	int left = L, right = R, mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(sum[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	scanf("%d%d", &n, &S);
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i-1] + S);//注意这里的右边界是开区间
		if(sum[j - 1] - sum[i - 1] == S)//注意这里是j - 1，说明查找成功了
			nearS = S;
		else if(j <= n && sum[j] - sum[i - 1] < nearS)
			nearS = sum[j] - sum[i - 1];
	}
	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS)//保证存在的
			printf("%d-%d\n", i, j - 1);
	}
	return 0;
}