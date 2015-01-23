//PAT_1047.Student List for Course (25)
//Miibotree
//2015.1.23
//vector的应用

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> mapx[2501];

int main()
{
	int k = 0, c = 0, n = 0;
	string s;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			char name[5];
			scanf("%s%d", name, &c);
			s = string(name);
			for (int j = 0; j < c; j++)
			{
				int course;
				scanf("%d", &course);
				mapx[course].push_back(s);
			}
		}

		int len = 0;
		for (int i = 1; i <= k; i++)
		{
			len = mapx[i].size();
			printf("%d %d\n", i, len);
			sort(mapx[i].begin(), mapx[i].end());
			for (int j = 0; j < len; j++)
				printf("%s\n", mapx[i][j].c_str());
		}
	}
	return 0;
}