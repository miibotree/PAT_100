//PAT_1039. Course List for Student (25)
//Miibotree
//2015.2.16
//用map超时，用hash
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int hashfunc(char *str)
{
	return (str[0]-'A') * 26 * 26 * 10 + (str[1]-'A') * 26 * 10 + (str[2]-'A') * 10 + str[3]; 
}

set<int> s[200000];

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
				char str[5];
				scanf("%s", str);
				s[hashfunc(str)].insert(idx);
			}
		}
		for(int i = 0; i < n; i++)
		{
			char str[5];
			int tmp;
			scanf("%s", str);
			printf("%s", str);
			tmp = (str[0]-'A') * 26 * 26 * 10 + (str[1]-'A') * 26 * 10 + (str[2]-'A') * 10 + str[3]; 
			printf(" %d", s[tmp].size());
			for(set<int>::iterator it = s[tmp].begin(); it != s[tmp].end(); it++)
				printf(" %d", *it);
			printf("\n");
		}
	}
	return 0;

}