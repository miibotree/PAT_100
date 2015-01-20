//PAT_1028. List Sorting (25)
//Miibotree
//2015.1.20

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Info{
	int ID;
	char name[9];
	int grade;
}info[100001];

bool cmp1(Info a, Info b)
{
	if(a.ID != b.ID)
		return a.ID < b.ID;
}

bool cmp2(Info a, Info b)
{
	int tmp = strcmp(a.name, b.name);
	if (tmp != 0)
		return tmp < 0;
	if (a.ID != b.ID)
		return a.ID < b.ID;
}

bool cmp3(Info a, Info b)
{
	if(a.grade != b.grade)
		return a.grade < b.grade;
	
	if (a.ID != b.ID)
		return a.ID < b.ID;
}

int main()
{
	int n, c;
	while(scanf("%d%d", &n, &c) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%s%d", &info[i].ID, info[i].name, &info[i].grade);
		if (c == 1)
			sort(info, info+n, cmp1);
		else if (c == 2)
			sort(info, info+n, cmp2);
		else
			sort(info, info+n, cmp3);
		for (int i = 0; i < n; i++)
			printf("%06d %s %d\n", info[i].ID, info[i].name, info[i].grade);
	}
	return 0;
}