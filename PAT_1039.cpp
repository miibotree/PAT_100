//PAT_1039. Course List for Student (23/25)
//Miibotree
//2015.2.16
//思路：map+vector 最后一组数据超时（23/25）
#include <stdio.h>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set<int> > S;
int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i = 0; i < k; i++)
		{
			int idx, num;
			scanf("%d%d", &idx, &num);
			for(int j = 0; j < num; j++)
			{
				string name;
				char str[5];
				scanf("%s", str);
				name = str;
				S[name].insert(idx);
			}
		}
		for(int i = 0; i < n; i++)
		{
			char str[5];
			string name;
			scanf("%s", str);
			name = str;
			printf("%s", str);
			printf(" %d", S[name].size());
			for(set<int>::iterator it = S[name].begin();
				it != S[name].end(); it++)
			{
				int re = *it;
				printf(" %d", re);
			}
			printf("\n");
		}
	}
	return 0;
}