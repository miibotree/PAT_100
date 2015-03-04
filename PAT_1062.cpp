//PAT_1062. Talent and Virtue (25)
//Miibotree
//2015.3.4
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct student{
	char id[10];
	int virtue;
	int talent;
	int total;
	int flag;
}stu[100001];
bool cmp(student a, student b)
{
	if(a.flag != b.flag)
		return a.flag < b.flag;
	else if(a.total != b.total)
		return a.total > b.total;
	else if(a.virtue != b.virtue)
		return a.virtue > b.virtue;
	else
		return strcmp(a.id, b.id) < 0;
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n, m, H, L;
	scanf("%d%d%d", &n, &L, &H);
	m = n;
	for(int i = 0; i < n; i++)
	{
		scanf("%s%d%d", stu[i].id, &stu[i].virtue ,&stu[i].talent);
		stu[i].total = stu[i].virtue + stu[i].talent;
		if(stu[i].virtue < L || stu[i].talent < L)
		{
			stu[i].flag = 5;
			m--;
		}
		else if(stu[i].virtue >= H && stu[i].talent >= H)
			stu[i].flag = 1;
		else if(stu[i].virtue >= H)
			stu[i].flag = 2;
		else if(stu[i].virtue >= stu[i].talent)
			stu[i].flag = 3;
		else
			stu[i].flag = 4;
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", m);
	for(int i = 0; i < m; i++)
		printf("%s %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
	return 0;
}