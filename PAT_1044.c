//PAT_1044. Shopping in Mars (25)
//Miibotree
//2015.2.16
//100ms n<10^5 用o(n^2)的算法,但是进行了一些优化
//就是考察优化的
//参考博客：http://blog.csdn.net/ljiabin/article/details/8633542

#include <stdio.h>

int a[100001];
int t1[100001], t2[100001];
int main()
{

	int n, m;
	int i, j;
	int jmp;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int flag = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int min = 100000001;
		int cnt = 0;
		jmp = 0;
		for(i = 1; i <= n; i++)
		{
			int sum = 0; 
			for(j = i + jmp; j <= n; j++)//使用jmp跳转优化
			{
				sum = sum + a[j];
				if (sum == m)
				{
					flag = 1;
					printf("%d-%d\n", i, j);
					break;//后面会更大，直接跳出循环
				}
				if(sum > m)
				{
					if(sum < min)
					{
						cnt = 0;
						min = sum;
						t1[cnt] = i;
						t2[cnt++] = j;
					}
					else if(sum == min)
					{
						t1[cnt] = i;
						t2[cnt++] = j;
					}
					if(sum == m && j - i > 1)//设置jmp的值
						jmp = j - i - 1;
					else
						jmp = 0;
					break;
				}
			}
			if(sum == m && j == n)//优化外层循环
				break;
		}
		if(flag == 0)
		{
			for(i = 0; i < cnt; i++)
				printf("%d-%d\n", t1[i], t2[i]);
		}
	}
	return 0;
}