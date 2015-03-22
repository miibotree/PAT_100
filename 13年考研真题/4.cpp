//PAT_1057. Stack (30)
//分块的思想
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
stack<int> s;

void PeekMedian()
{
	int size = v.size();
	if(size % 2 == 0)
		size = size / 2;
	else
		size = (size + 1) / 2;
	printf("%d\n", v[size-1]);
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n;
	char cmd[10];
	int x;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", cmd);
		if(cmd[1] == 'u')//push
		{
			scanf("%d", &x);
			s.push(x);
			v.insert(upper_bound(v.begin(), v.end(), x), x);
		}
		else if(cmd[1] == 'o')//pop
		{
			if(s.size() == 0)
				printf("Invalid\n");
			else
			{
				x = s.top();
				printf("%d\n", x);
				s.pop();
				v.erase(lower_bound(v.begin(), v.end(), x), lower_bound(v.begin(), v.end(), x)+1);
			}
		}
		else//peekmedian
		{
			if(s.size() == 0)
				printf("Invalid\n");
			else
				PeekMedian();
		}
	}
	return 0;
}