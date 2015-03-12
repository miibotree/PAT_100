#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> course[2501];

int main()
{
	int n, k;
	char name[5];
	string s;
	int cnt, c;
	while( scanf("%d%d", &n, &k) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%s %d", name, &cnt);
			s = name;
			for(int j = 0; j < cnt; j++)
			{
				scanf("%d", &c);
				course[c].push_back(s);
			}
		}
		for(int i =1; i <= k; i++)
		{
			printf("%d %d\n", i, course[i].size());
			sort(course[i].begin(), course[i].end());
			for(int j = 0; j < course[i].size(); j++)
				printf("%s\n", course[i][j].c_str());
		}
	}
	return 0;
}