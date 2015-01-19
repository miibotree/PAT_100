//PAT_1016. Phone Bills (25)
//Miibotree
//2015.1.18
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int rates[24];

typedef struct _time{
	int month;
	int day;
	int hour;
	int minute;
}time;

typedef struct _call{
	time t;
	char state[10];
	int st;
}call;

struct _list{
	char name[21];
	int order;
	call c[100];
}list[1000];

bool cmp(call x, call y)
{
	if (x.st != y.st)
		return x.st < y.st;
}

int main()
{
	int n;
	time t;
	int cnt = 0;
	for (int i = 0; i < 24; i++)
		scanf("%d", &rates[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char name[21];
		char state[10];
		int j;
		scanf("%s %d:%d:%d:%d %s", name, &t.month, &t.day, &t.hour, &t.minute, state);
		//查找名字是否已经出现过
		if (cnt > 0)
		{
			for (j = 0; j < cnt; j++)
			{
				if (!strcmp(name, list[j].name))//相同
				{
					list[j].c[order].t = t;
					list[j].c[order].state = state;
					list[j].order++;
				}
			}
			if (j == cnt)//没有找到新添加
			{
				list[cnt].c[order].t = t;
				list[cnt].c[order].t = state;
				list[cnt].order++;	
				cnt++;
			}
		}
		else
		{
				list[cnt].c[order].t = t;
				list[cnt].c[order].t = state;
				list[cnt].order++;	
				cnt++;	
		}
	}
	for (int i = 0; i < cnt; i++)
		PrintBill(list[i]);
	return 0;
}

void PrintBill(_list x)
{
	//电话记录按时间排序
	for (int i = 0; i < x.order; i++)
	{
		x.c[i].st = x.c[i].day * 24 * 60 + x.c[i].hour * 60 + x.c[i].minute;
	}
	sort(x.c, x.c+x.order, cmp);
	printf("%s %02d\n", x.name, x.month);
	
}