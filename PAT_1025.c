//PAT_1025. PAT Ranking (25)
//Miibotree
//2015.1.19

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Info{
	char reg_num[15];
	int final_rank;
	int location_number;
	int local_rank;
	int score;
}info[30001];

bool cmp(Info a, Info b)
{
	if (a.score != b.score)
		return a.score > b.score;
	int tmp = strcmp(a.reg_num, b.reg_num);
	if (tmp != 0)
		return tmp < 0;
}

int main()
{
	int position, cnt, k;
	int current_rank;
	while (scanf("%d", &position) != EOF)
	{
		cnt = 0;
		for (int i = 0 ; i < position; i++)
		{
			scanf("%d", &k);
			for (int j = 0 ; j < k; j++)
			{
				scanf("%s%d", info[cnt].reg_num, &info[cnt].score);
				info[cnt].location_number = i+1;
				cnt++;
			}
			sort(&info[cnt-k],&info[cnt],cmp);
			info[cnt-k].local_rank = 1;
			current_rank = 1;
			for (int j = 1; j < k; j++)
			{
				if(info[cnt-k+j].score != info[cnt-k+j-1].score)
				{
					info[cnt-k+j].local_rank = j+1;
					current_rank = j+1;
				}
				else
					info[cnt-k+j].local_rank = current_rank;
			}
		}
		sort(info, info+cnt, cmp);
		info[0].final_rank = 1;
		current_rank = 1;
		for (int j = 1; j < cnt; j++)
		{
			if(info[j].score != info[j-1].score)
			{
				info[j].final_rank = j+1;
				current_rank = j+1;
			}
			else
				info[j].final_rank = current_rank;
		}

		printf("%d\n", cnt);
		for (int j = 0; j < cnt; j++)
		{
			printf("%s %d %d %d\n", info[j].reg_num, info[j].final_rank, info[j].location_number, info[j].local_rank);
		}
	}
	return 0;
}