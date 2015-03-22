//PAT_1097. Deduplication on a Linked List (25)
//Miibotree
//2015.3.22
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int hashTable[10001];

struct  Node
{
	int address;
	int key;
	int next;
	int flag;//需不需要删除的标志
};
Node node[100001];

bool cmp(Node a, Node b)
{
	return a.flag < b.flag;
}

int main()
{
	int n, head;
	scanf("%d%d", &head, &n);
	for(int i = 0; i < 100001; i++)
		node[i].flag = 100000;
	for(int i = 0; i < n; i++)
	{
		int addr, value, next;
		scanf("%d%d%d", &addr, &value, &next);
		node[addr].address = addr;
		node[addr].key = value;
		node[addr].next = next;
	}
	int p = head;
	int cnt = 0;//在链表上的个数
	int remain = 0;//剩下的元素
	while(p != -1)
	{
		if(hashTable[abs(node[p].key)] == false)
		{
			hashTable[abs(node[p].key)] = true;
			node[p].flag = -100000 + cnt;
			cnt++;
		}
		else
		{
			node[p].flag = remain;
			remain++;
		}
		p = node[p].next;
	}


	sort(node, node + 100000, cmp);
	if(n == 1)
	{
		printf("%05d %d -1\n", node[0].address, node[0].key);
		return 0;
	}

	for(int i = 0; i < cnt - 1; i++)
	{
		printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
	}
	printf("%05d %d -1\n", node[cnt - 1].address, node[cnt - 1].key);

	for(int i = cnt; i < cnt + remain - 1; i++)
	{
		printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
	}
	printf("%05d %d -1\n", node[cnt+remain-1].address, node[cnt+remain-1].key);

	return 0;
}