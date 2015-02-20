//PAT_1055. The World's Richest (25)
//Miibotree
//2015.2.20
//一道简单的排序题

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

struct person{
	char name[10];
	int age;
	int worth;
}p[100001];

bool cmp(person a, person b)
{
	if(a.worth != b.worth)
		return a.worth > b.worth;
	if(a.age != b.age)
		return a.age < b.age;
	int tmp = strcmp(a.name, b.name);
	if(tmp != 0)
		return tmp < 0;
}

vector<person> v;

int main()
{
	int n, m;
	for(int i = 0; i < n; i++)
		scanf("%s%d%d", p[i].name, p[i].age, p[i].worth);
	sort(p, p + n, cmp);
	for(int j = 1; j <= m; j++)
	{
		int maxnum, amin, amax, cnt = 0;
		scanf("%d%d%d", &maxnum, &amin, &amax);
		printf("Case #%d:\n", j);
		for(int i = 0; i < n; i++)
		{
			if(p[i].age >= amin && p[i].age <= amax)
			{
				v.push_back(p[i]);
				cnt++;
				if(cnt == maxnum)
					break;
			}
		}
		if(cnt == 0)
			printf("None\n");
		else
		{
			for(int i = 0; i < cnt; i++)
				printf("%s %d %d\n", v[i].name, v[i].age, v[i].worth);
		}
	}
	return 0;
}