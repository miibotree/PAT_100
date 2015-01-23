//PAT_1063. Set Similarity(25)
//Miibotree
//2015.1.23
//学习set STL的用法
//set内部的实现是一颗红黑树，自动排序，在insert时直接过滤重复的数值
//使用set_intersection函数可以求两集和的交集，set_union函数求并集

#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

set<int> s[51];
set<int> res;
int main()
{
	int n, m ,in;
	int k, a, b;
	float nc, nt;
	while(scanf("%d", &n) != EOF)//n组set
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);//每组有m个数据
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &in);
				s[i].insert(in);
			}
		}
		scanf("%d", &k);
		for (int i = 0 ; i < k; i++)
		{
			scanf("%d%d", &a, &b);
			set_intersection(s[a-1].begin(), s[a-1].end(), s[b-1].begin(), s[b-1].end(), 
								inserter(res, res.begin()));
			nc = res.size();
			nt = s[a-1].size() + s[b-1].size() - nc;
			res.clear();
			printf("%.1f%%\n", nc/nt*100);
		}
	}
	return 0;
}