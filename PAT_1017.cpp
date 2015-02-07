//PAT_1017. Queueing at Bank (25)
//Miibotree
//2015.2.7
//注意细节：sort是从下标0开始的，而我这里处理的时候是从1开始的
#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 0x6fffffff
using namespace std;

struct customer{
	int aTime;//到达时间
	int sTime;//开始处理时间
	int wasteTime;//处理时间
}cus[10000+5];

bool cmp(customer a, customer b){
	if(a.aTime != b.aTime)
		return a.aTime < b.aTime;
}

int win[100+5];

int main()
{
	int i, j;
	int n, k;
	int minTime;
	int idx, pos;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			int hh, mm, ss, process;
			scanf("%d:%d:%d %d", &hh, &mm, &ss, &process);
			cus[i].aTime = hh * 60 * 60 + mm * 60 + ss;//统一变成秒处理
			cus[i].wasteTime = process * 60;
		}
		for(i = 1; i <= k; i++)
			win[i] = 8*60*60;
		sort(cus+1, cus+n+1, cmp);//按照到达时间排序

		for(i = 1; i <= n; i++)
		{
			minTime = INF;
			for(j = 1; j <= k; ++j)
			{
				if(minTime > win[j])
				{
					minTime = win[j];
					pos = j;//找到结束时间最早的那个窗口
				}
			}
			cus[i].sTime = max(cus[i].aTime, win[pos]);
			win[pos] = cus[i].sTime + cus[i].wasteTime;
		}
		
		double sum = 0;
		int cnt = 0;
		for(i = 1; i <= n; i++)
		{
			if(cus[i].aTime > 17*60*60)
				continue;
			else
			{
				sum += cus[i].sTime - cus[i].aTime;
				cnt++;
			}
		}
		sum  = sum / 60 / cnt;
		printf("%.1f\n", sum);
	}
	return 0;
}