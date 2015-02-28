//PAT_1075.PAT Judge (22/25)
//Miibotree
//2015.2.22
//排序+结构体
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node
{
	int rank;
	int id;
	int score[6];
	int all_score;
	int solved;
	int flag;
	int p_flag[6];
}a[10001];

bool cmp(Node a, Node b)
{
	if(a.all_score != b.all_score)
		return a.all_score > b.all_score;
	if(a.solved != b.solved)
		return a.solved > b.solved;
	if(a.id != b.id)
		return a.id < b.id;
}

int main()
{
	int n, k, m;
	int p[6];

	while(scanf("%d%d%d", &n, &k, &m) != EOF)
	{
		for(int i = 1; i <= k; i++)
			scanf("%d", &p[i]);
		for(int i = 1; i <= m; i++)
		{
			int id, problem, score;
			scanf("%05d%d%d", &id, &problem, &score);
			a[id].id = id;
			a[id].p_flag[problem] = true;
			if(score >= 0)//说明已经提交并且没有编译错误
			{
				a[id].flag = true;

				if(score == p[problem] && a[id].score[problem] < score)//防止完全正确的重复提交计数
					a[id].solved++;
				
				if(a[id].score[problem] < score)
					a[id].score[problem] = score;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= k; j++)
			{
				if(a[i].score[j] != -1)
					a[i].all_score += a[i].score[j];
			}
		}
		sort(a+1, a+n+1, cmp);

		int r = 1, cnt = 1;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].flag == false)//不计入排名
				continue;
			if(a[i].all_score != a[i-1].all_score)
				r = cnt;
			
			printf("%d %05d %d", r, a[i].id, a[i].all_score);
			for(int j = 1; j <= k; j++)
			{
				if(a[i].p_flag[j] == true)
					printf(" %d", a[i].score[j]);
				else
					printf(" -");
			}
			printf("\n");
			cnt++;
		}
	}

	return 0;
}