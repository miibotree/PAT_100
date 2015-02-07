//PAT_1014.cpp(Again)
//Miibotree
//2015.2.7
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 0x6fffffff

struct customer
{
	int wasteTime;
	int sTime;
	int eTime;
}cust[1005];

struct window
{
	int eTime;//窗口处理完时间
	queue<int> q;
}win[25];

int main()
{
	int n, m, k, q, i = 1;
	int minTime, idx, pos;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(i = 1; i <= k; i++)
		scanf("%d", &cust[i].wasteTime);
	i = 1;
	//首先把n个窗口每个窗口m个人先排满，并且计算每个窗口结束服务的时间
	for(int j = 0; i <= n * m && i <= k; ++i, j = (j+1) % n)
	{
		cust[i].sTime = win[j].eTime;
		cust[i].eTime = win[j].eTime + cust[i].wasteTime;
		win[j].eTime += cust[i].wasteTime;
		win[j].q.push(i);
	}
	//注意这里的i已经不是从头开始了
	for(; i <= k; ++i)
	{
		minTime = INF;
		for(int j = 0; j < n; ++j)
		{
			idx = win[j].q.front();//取每个队的队首
			if(minTime > cust[idx].eTime)
			{
				minTime = cust[idx].eTime;
				pos = j;//找到结束时间最早的那个窗口
			}
		}
		cust[i].sTime = win[pos].eTime;
		cust[i].eTime = win[pos].eTime + cust[i].wasteTime;
		win[pos].eTime += cust[i].wasteTime;
		win[pos].q.pop();
		win[pos].q.push(i);
	}
	int hour, minutes;
	while(q--)
	{
		scanf("%d", &k);
		if(cust[k].sTime+8*60 >= 17*60)
			printf("Sorry\n");
		else
		{
			hour = (cust[k].eTime+8*60)/60;
			minutes = (cust[k].eTime+8*60)%60;
			printf("%02d:%02d\n", hour, minutes);
		}
		
	}

	return 0;
}