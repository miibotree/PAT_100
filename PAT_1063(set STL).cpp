#include <stdio.h>
#include <set>
using namespace std;
set<int> s[51];

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		for(int j = 0; j < num; j++)
		{
			int x;
			scanf("%d", &x);
			s[i].insert(x);
		}
	}
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int a, b;
		int nt, nc;
		scanf("%d%d", &a, &b);
		nt = s[a].size();
		set<int>::iterator it;
		for(it = s[b].begin(); it != s[b].end(); it++)
		{
			if(s[a].find(*it) == s[a].end())//注意set的插入操作会消耗很多时间。
				nt++;
		}
		nc = s[a].size() + s[b].size() - nt;
		double ans = nc * 100.0 / nt;
		printf("%.1f%%\n", ans);
	}
	return 0;
}