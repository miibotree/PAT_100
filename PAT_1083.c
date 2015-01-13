//PAT_1083 List Grades (25)
//Miibotree
//2015.1.13

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct _info
{
	char name[11];
	char ID[11];
	int grade;
}info;

bool cmp(info a, info b)//从大到小排列
{
	if (a.grade != b.grade)
		return a.grade>b.grade;//成绩高者在前面
}

int main()
{
	info s[1000];

	int n = 0;
	int min = 0, max = 0;
	while (scanf("%d", &n) != EOF)
	{
		int flag = 0;
		for (int i = 0; i < n; i++)
			scanf("%s %s %d", s[i].name, s[i].ID, &s[i].grade);
		scanf("%d %d", &min, &max);
		sort(s, s+n, cmp);
		for (int i = 0; i < n; i++)
		{
			if (s[i].grade >= min && s[i].grade <= max)
			{
				printf("%s %s\n", s[i].name, s[i].ID);
				flag = 1;
			}
		}
		if (flag == 0)
			printf("NONE\n");
	}
}