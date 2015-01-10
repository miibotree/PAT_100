//PAT_1054 The Dominant Color (20)
//Miibotree
//2015.1.10
//思路： 数组中某个元素超过一半称为 主元素。使用删除法删除主元素
#include <stdio.h>

int Majority(int a[], int n);//主元素算法

int  a[480001];

int main()
{
	int m = 0, n = 0;

	while(scanf("%d %d", &m, &n) != EOF)
	{
		for (int k = 0; k < m * n; k++)
			scanf("%d", &a[k]);
		printf("%d\n", Majority(a, m*n));
	}
	return 0;
}

int Majority(int a[], int n)//主元素算法
{
	int i, c, count = 1;
	c = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] == c)
			count++;
		else
		{
			if (count > 0)
				count --;
			else{
				c = a[i];
				count = 1;
			}
		}
	}
	/*  如果题目没有说明保证存在主元素，则需要判断这一步
	if (count > 0)
		for (i = count = 0; i < n; i++)
			if(a[i] == c)
				count ++;
	if (count > n / 2)
		return c;
	else
		return -1;
	*/
	return c;
}