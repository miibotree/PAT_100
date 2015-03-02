//PAT_1057. Stack (30)
//Miibotree
//2015.3.2
//分块思想
#include <stdio.h>
#include <stack>
#include <algorithm>
#define limit 317

using namespace std;

stack<int> s;
int bucket[limit];
int table[100001];

void PeekMedian()
{
	int size = vi.size();//获取中间位置size
	if(size % 2 == 1)
		size = (size + 1) / 2;
	else
		size = size / 2;

	int sum = 0;
	int idx = 0;
	for(idx = 0; idx < limit; idx++)//寻找在那个bucket里面
	{
		if(sum + bucket[idx] < size)
			sum += bucket[idx];
		else
			break;
	}
	//找到了bucket，再遍历table找到对应的下标
	idx = idx * limit;//当前块的第一个数字
	while(1)
	{
		sum += table[idx];
		if(sum >= size)
		{
			printf("%d\n", idx);
			break;
		}
		else
			idx++;
	}	
}	

int main()
{
	memset(bucket, 0, limit);
	memset(table, 0, 100001);

	int n;
	scanf("%d", &n);
	getchar();
	char cmd[20];
	while(n--)
	{
		gets(cmd);
		int key;
		char str[10];
		switch(cmd[1])
		{
			case 'u'://push 
				sscanf(cmd, "%s%d", str, &key);
				s.push(key);
				table[key]++;
				bucket[key / limit]++;
			break;

			case 'o'://pop
				if(s.empty() == true)//栈是空的
					printf("Invalid\n");
				else
				{
					int x = s.top();
					s.pop();
					table[x]--;
					bucket[x / limit]--;
					printf("%d\n", x);
				}
				break;
			case 'e'://PeekMedian
				if(s.empty() == true)//栈是空的
					printf("Invalid\n");
				else
				{
					PeekMedian();
				}
		}
	}
	return 0;
}