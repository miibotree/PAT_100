//PAT_1057. Stack (17/30)
//Miibotree
//2015.2.20

#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> s, tmp_s;

void PeekMedian()
{
	int a[100001], cnt = 0;
	while(tmp_s.empty() == false)
	{
		a[cnt++] = tmp_s.top();
		tmp_s.pop();
	}
	sort(a, a+cnt);
	if(cnt % 2 == 0)//偶数
		printf("%d\n", a[cnt / 2 - 1]);
	else
		printf("%d\n", a[(cnt + 1) / 2 - 1]);
}

int main()
{
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
			break;

			case 'o'://pop
				if(s.empty() == true)//栈是空的
					printf("Invalid\n");
				else
				{
					int x = s.top();
					s.pop();
					printf("%d\n", x);
				}
				break;
			case 'e':
				if(s.empty() == true)//栈是空的
					printf("Invalid\n");
				else
				{
					tmp_s = s;
					PeekMedian();
				}
		}
	}
	return 0;
}