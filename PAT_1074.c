//PAT_1074. Reversing Linked List (25)
//Miibotree
//2015.3.5
//链表逆置 按照晴神的解题步骤来好了
#include <stdio.h>
#include <algorithm>
#define maxn 100001
using namespace std;

struct Node{
	int addr, key,next;
	int order;
}node[maxn];

bool cmp(Node a, Node b)
{
	if(a.order == -1 || b.order == -1)
		return a.order > b.order;
	else
		return a.order < b.order;
}

int main()
{
	int head, k, n;
	int p, cnt;
	scanf("%d%d%d", &head, &n, &k);
	for(int i = 0; i < maxn; i++)
		node[i].order = -1;
	for(int i = 0; i < n; i++)
	{
		int addr, key, next;
		scanf("%d%d%d", &addr, &key, &next);
		node[addr].key = key;
		node[addr].next = next;
		node[addr].addr = addr;
		p = head;	
		cnt = 0;
	}
	while(p != -1)
	{
		cnt++;
		node[p].order = cnt;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = cnt;
	for(int i = 0; i < n / k; i++)//分了这么多组 （10 / 4 = 2）
	{
		//[i * K, (i + 1)* K - 1],倒着输出就反一下，最后一个节点i * K 特殊处理
		for(int j = (i + 1) * k - 1; j > i * k; j--)//每一个完整块倒着输出(不包含最后一个节点)
			printf("%05d %d %05d\n", node[j].addr, node[j].key, node[j-1].addr);
		//每一个完整块最后一个节点的处理
		if(i < n / k - 1)//不是最后一个完整块
			printf("%05d %d %05d\n", node[i * k].addr, node[i * k].key, node[(i + 2) * k - 1].addr);
		else//是最后一个完整块
		{
			//没有尾巴
			if(n % k == 0)
			{
				printf("%05d %d -1\n", node[i * k].addr, node[i * k].key);
			}
			//有尾巴
			else
			{
				//先输出最后一个完整快的next
				printf("%05d %d %05d\n", node[i * k].addr, node[i * k].key, node[(i + 1) * k].addr);
				//然后顺序输出尾巴
				for(int j = (i + 1) * k; j < n - 1; j++)//这里j的初始条件要注意
					printf("%05d %d %05d\n", node[j].addr, node[j].key, node[j + 1].addr);
				printf("%05d %d -1\n", node[n - 1].addr, node[n - 1].key);
			}	
		}
	}
	return 0;	
}
