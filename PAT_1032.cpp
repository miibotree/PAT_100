//1032. Sharing (25)
//Miibotree
//2015.3.5
#include <stdio.h>

struct node{
	char data;
	int next;
}node[100001];

int addr1, addr2;
bool flag[100001];

int main()
{
	int n;
	scanf("%d%d%d", &addr1, &addr2, &n);
	for(int i = 0; i < n; i++)
	{
		int addr, next;
		char data;
		scanf("%d %c %d", &addr, &c, &next);
		node[addr].data = c;
		node[addr].next = next;
 	}
 	while(node[addr1] != -1)
 	{
 		flag[addr1] = 1;
 		addr1 = node[addr1]->next;
 	}
 	int mark = 0;
 	while(node[addr2] != -1)
 	{
 		if(flag[addr2] == 1)
 		{
 			mark = 1;
 			break;
 		}
 		else
 			addr2 = node[addr2]->next;
 	}
 	if(mark == 1)
 		printf("%05d\n", addr2);
 	else
 		printf("-1\n");
}