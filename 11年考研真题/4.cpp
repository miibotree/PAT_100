#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct student{
	int id;
	int ge;
	int gi;
	int sum;
	int rank;
	int choice[6];
}stu[40001];

struct school{
	int num;
	int quota;
	vector<int>q;
}sch[101];
int n, m, k;

bool cmp(student a, student b)
{
	if(a.sum != b.sum)
		return a.sum > b.sum;
	else
		return a.ge > b.ge;
}


int main()
{
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		for(int i = 0; i < m; i++)
		{
			sch[i].q.clear();
			sch[i].num = 0;
		}


		for(int i = 0; i < m; i++)
			scanf("%d", &sch[i].quota);
		for(int i = 0; i < n; i++)
		{
			stu[i].id = i;
			scanf("%d%d", &stu[i].ge, &stu[i].gi);
			stu[i].sum = stu[i].ge + stu[i].gi;
			for(int j = 0; j < k; j++)
				scanf("%d", &stu[i].choice[j]);
		}
		sort(stu, stu + n, cmp);
		int r = 1;
		stu[0].rank = 1;
		for(int i = 1; i < n; i++)
		{
			if(stu[i].sum == stu[i-1].sum && stu[i].ge == stu[i-1].ge)
				stu[i].rank = stu[i-1].rank;
			else
			{
				stu[i].rank = i+1;
				r = i+1;
			}
		}
		int lastschool = -1;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < k; j++)
			{
				int c = stu[i].choice[j];
				if(sch[c].num < sch[c].quota)//可以招生
				{
					sch[c].num++;
					sch[c].q.push_back(stu[i].id);
					lastschool = c;
					break;
				}
				else if(sch[c].num >= sch[c].quota && stu[i].rank == stu[i-1].rank && lastschool == c)
				{//特殊情况，也可以招生
					sch[c].num++;
					sch[c].q.push_back(stu[i].id);
					lastschool = c;
					break;
				}
			}
		}
		for(int i = 0; i < m; i++)
		{
			vector<int> tmp;
			tmp = sch[i].q;
			if(tmp.size() == 0)
				printf("\n");
			else
			{
				sort(tmp.begin(), tmp.end());
				for(int j = 0; j < tmp.size(); j++)
				{
					if(j != 0)
						printf(" ");
					printf("%d", tmp[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}