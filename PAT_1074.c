//PAT_1074. Reversing Linked List (17/25)
//Miibotree
//2015.2.22
//链表逆置
#include <stdio.h>
#include <stack>

struct Node
{
	int address;
	int next;
	int data;
}List[100001];

stack<Node> s;

void Print()
{
	while(s.empty() == false)
	{
		Node tmp = s.top();
		s.pop();
		printf("%5d %d %5d\n", tmp.address, tmp.data, tmp.next);
	}
}

int main()
{
	int n, k, first;
	while(scanf("%5d%d%d", &first, &n, &k) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			int a, n, d;
			scanf("%05d%d%05d", &a, &d, &n);
			List[a].address = a;
			List[a].data = d;
			List[a].next = n;
		}

		int sum = 0, cnt = 0, cur = first;
		while(s.empty() == false)	s.pop();
		while(sum < n && cur != -1)
		{
			Node tmp;
			tmp.address = cur;
			tmp.data = List[cur].data;
			tmp.next = List[cur].next;

			s.push(tmp);
			cur = List[cur].next;
			cnt++;	sum++;
			if(cnt == k)
			{
				Print();
				cnt = 0;
			}
		}
		if(s.empty() == false)
			Print();
	}
	return 0;
}
