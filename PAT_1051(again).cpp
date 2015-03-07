#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
int main()
{
	int a[1001];
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while(k--)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		while(s.empty() == false)	s.pop();
		int current = 0;//出栈序列的第0个元素
		int flag  = true;
		for(int i = 1; i <= n; i++)
		{
			s.push(i);
			if(s.size() > m)
			{
				flag = false;
				break;
			}
			while(s.empty() == false && s.top() == a[current])
			{
				s.pop();
				current++;
			}
		}
		if(s.empty() == true && flag == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}