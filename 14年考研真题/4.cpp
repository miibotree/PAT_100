//14年考研真题
//1080. Graduate Admission (30)
//Miibotree
//2015.3.4
//结构体排序加模拟
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int quota[101];
int cnt[101];
vector<int> result[101];

struct student{
	int id;
	int GE;
	int GI;
	int AVG;
	int rank;
	int choice[6];
}stu[40001];

bool cmp(student a, student b)
{
	if(a.AVG != b.AVG)
		return a.AVG > b.AVG;
	else 
		return a.GE > b.GE;//注意这里如果没有写好的话有一组数据会超时
 
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int number;
		scanf("%d", &number);
		quota[i] = number;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &stu[i].GE, &stu[i].GI);
		stu[i].id = i;
		stu[i].AVG = (stu[i].GE + stu[i].GI) / 2;
		for(int j = 0; j < k; j++)
			scanf("%d", &stu[i].choice[j]);
	}
	sort(stu, stu + n, cmp);
	//calu rank
	int rank = 1;
	stu[0].rank = 1;
	for(int i = 1; i < n; i++)
	{
		if(stu[i].AVG == stu[i - 1].AVG && stu[i].GE == stu[i - 1].GE)
			stu[i].rank = rank;
		else
		{
			stu[i].rank = i + 1;
			rank = i + 1;
		}
	}
	int pre_school = -1;//记录前一个人进的是哪个学校
	for(int i = 0; i < n; i++)//按照排名录取
	{
		for(int j = 0; j < k; j++)
		{
			int school = stu[i].choice[j];
			int flag = 0;
			if (cnt[school] < quota[school])
				flag = 1;
			
			else if(cnt[school] >= quota[school] && stu[i].rank == stu[i - 1].rank && school == pre_school)	
				flag = 1;
			if(flag == 1)
			{
				result[school].push_back(stu[i].id);
				cnt[school]++;
				pre_school = school;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		int j = 0;
		
		if(result[i].size() == 0)
			printf("\n");
		else
		{
			sort(result[i].begin(), result[i].end());
			for(j = 0; j < result[i].size() - 1; j++)
				printf("%d ", result[i][j]);
			printf("%d\n", result[i][j]);
		}
	}
}
