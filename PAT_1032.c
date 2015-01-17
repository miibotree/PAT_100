//PAT_1032. Sharing (25)
//Miibotree
//2015.1.17

#include <stdio.h>

struct Node
{
	char Data;
	int Next;
}LinkList[100005];

int Length(int addr);

int main()
{
	int addr1, addr2, n;
	int len1, len2;
	int i, j, diff;
	int addr; 
	char data; 
	int next;

	while (scanf("%d %d %d", &addr1, &addr2, &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d %c %d", &addr, &data, &next);
			LinkList[addr].Data = data;
			LinkList[addr].Next = next;
		}
		len1 = Length(addr1);
		len2 = Length(addr2);
		diff = 0;
		if (len1 > len2)//len1先走
		{
			diff = len1 - len2;
			while (diff--)
				addr1 = LinkList[addr1].Next;
		}
		else if (len1 < len2)
		{
			diff = len2 - len1;
			while (diff--)
				addr2 = LinkList[addr2].Next;
		}
		int flag = 0;
		while (addr1 != -1)//注意这里的结束条件 一开始写成了LinkList[addr]->next != -1 导致有一个case没有通过
		{
			if (addr1 == addr2)
			{
				flag = 1;
				break;
			}
			addr1 = LinkList[addr1].Next;
			addr2 = LinkList[addr2].Next;
		}
		if (flag == 1)
			printf("%05d\n", addr1);
		else
			printf("-1\n");
	}
	return 0;
}

int Length(int addr)
{
	if (addr == -1)
		return 0;
	int cnt = 1;
	while (LinkList[addr].Next != -1)
	{
		cnt++;
		addr = LinkList[addr].Next;
	}
	return cnt;
}