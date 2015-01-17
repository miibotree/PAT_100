//1052. Linked List Sorting (25)
//Miibotree
//2015.1.17
//注意：1. 链表为空
//		2.有些节点不在链表上
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node{
	int addr;
	int value;
	int next;
}a[100001], b[100001];

bool cmp(node a, node b)
{
	if(a.value != b.value)
		return a.value < b.value;
}

int main()
{
	int n, ba;
	int x, y, z;
	while (scanf("%d%d", &n, &ba) != EOF)
	{		
		for (int i = 0; i < n; i++)	
		{
			scanf("%d%d%d", &x, &y, &z);
			a[x].addr = x;
			a[x].value = y;
			a[x].next = z;
		}

		if (ba == -1)//注意这里可能n不为0 但是首地址是-1
		{
			printf("0 -1\n");
			continue;
		}

		int cnt = 0;
		while (ba != -1)
		{
			b[cnt].addr = a[ba].addr;
			b[cnt].value = a[ba].value;
			b[cnt].next = a[ba].next;
			ba = a[ba].next;
			cnt++;
		}
		sort(b, b+cnt, cmp);

		printf("%d %05d\n", cnt, b[0].addr);

		for (int i = 0; i < cnt-1; i++)
			printf("%05d %d %05d\n", b[i].addr, b[i].value, b[i+1].addr);
		printf("%05d %d -1\n", b[cnt-1].addr, b[cnt-1].value);

	}
	return 0;
}
