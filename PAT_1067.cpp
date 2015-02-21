//PAT_1067. Sort with Swap(0,*) (25)
//Miibotree
//2015.2.21
//思路：贪心
//有两种情况 1.swap(0, *)后0没有在自己的位置，可以继续交换
//			 2.swap(0, *)后0在他自己的位置，找一个数跟0交换
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int pos[100001];

int main()
{
	int left, step = 0, x;
	while(scanf("%d", &n) != EOF)
	{
		step = 0;
		left = n - 1;//left表示还有left个位置没有排在他们应该排的位置
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			pos[x] = i;//x这个数字在i的位置
			if(x == i && x != 0)
				left--;
		}
		int k = 1, i;
		while(left)
		{
			if(pos[0] == 0)//0被排在了自己的位置但是还有其他元素没有排在正确的位置
			{
				for(i = k; i < n; i++)//注意这里的k的优化方法
				{
					if(i != pos[i])
					{
						swap(pos[0], pos[i]);
						step++;
						break;
					}
				}
				k = i;
			}
			while(pos[0] != 0)//0没有被排在自己的位置
			{
				swap(pos[0], pos[pos[0]]);
				left--;
				step++;
			}
		}
		printf("%d\n", step);
	}
	return 0;
}