//PAT_1052. Linked List Sorting (25)
//Miibotree
//2015.3.5
//链表排序
#include <stdio.h>

struct Node{
	int addr;
	int key;
	int next;
	bool flag;
}node[100001];

bool cmp(Node a, Node b)
{
	if(a.flag == 0 || b.flag == 0)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}

int main()
{
	for(int i = 0; i < 100001; i++)
		node[i].flag = false;
	int n, m, head;
	scanf("%d %d", &n, &head);
	for(int i = 0; i < n; i++)
	{
		int addr, key, next;
		scanf("%d%d%d", &addr, &key, &next);
		node[addr].addr = addr;
 		node[addr].key = key;
		node[addr].next = next;
		node[addr].flag = true;
	}
	m = 0;	int p = head;
	while(p != -1)
	{
		m++;
		p = node[p].next;
	}
	sort(node, node + 100001, cmp);
	printf("%d %05d\n", m, node[0].addr);
	for(int i = 0; i < m - 1; i++)
	{
		printf("%05d %d %05d\n", node[i].addr, node[i].key, node[i+1].addr);
	}
	printf("%05d %d -1\n", node[m-1].addr, node[m-1].key);
	return 0;
}