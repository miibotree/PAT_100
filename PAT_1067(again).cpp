//PAT_1067. Sort with Swap(0,*) (25)
//贪心的策略很重要。这道题目自己的想法是这样的：
//首先判断0所在的位置的元素的位置是不是0，如果是的话选择一个还没有在本位的元素。
//而这样思考会使得策略变得复杂。
//事实上，如果出现这种情况的话，我们可以将两个元素交换位置，（因为这样保证了非0元素回到本位），
//然后再选取没有回到本位的元素与0交换位置。
//而这样做的效果跟之前自己的策略效果是一样的，因为之前自己那么做的时候0和那个元素都没有回到本位。

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int pos[100001];//下标是元素，内容是序号
	int step = 0;//总步数
	int cnt = 0;//已经归位的元素个数
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		pos[x] = i;
		if (x == i)
			cnt++;
	}
	if(cnt == n)
	{
		printf("0\n");
		return 0;
	}
	if(pos[0] == 0 && cnt < n - 2)//0在本位且还有没有归位的元素
	{
		for(int i = 1; i < n; i++)
		{
			if(pos[i] != i)//说明没有归位
			{
				//交换两个位置
				swap(pos[0], pos[i]);
				step++;
				cnt--;
				break;
			}
		}
	}
	int zero_pos, change_pos;
	int k = 1, i;
	while(1)
	{
		zero_pos = pos[0];
		if(pos[zero_pos] != 0)//所要交换的位置不是0的位置
		{
			swap(pos[0], pos[zero_pos]);
			step++;
			cnt++;
		}
		else//所要交换的位置是0
		{
			if(cnt == n-2)//还有两个就归位了
			{
				step++;
				printf("%d\n", step);
				break;
			}
			else//找到一个没有归位的位置跟0交换
			{
				for(i = k; i < n; i++)
				{
					if(pos[i] == 0)
						continue;
					if(pos[i] != i)//说明没有归位
					{
						//交换两个位置
						swap(pos[0], pos[i]);
						step++;
						break;
					}
				}
				k = i;
			}
		}
	}
	return 0;
}