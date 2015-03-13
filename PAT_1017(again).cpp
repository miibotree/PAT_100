//PAT_1017. Queueing at Bank (25)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Customer{
	int aTime;//到达时间
	int sTime;//服务时长
};
vector<Customer> c;

int w[101];//记录窗口的结束服务时间
int n, k;

bool cmp(Customer a, Customer b)
{
	return a.aTime < b.aTime;
}

int main()
{
	int stTime = 8 * 3600;//开门时间
	int edTime = 17 * 3600;//关门时间
	int totTime = 0;//记录总等待时长

	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++)
		w[i] = stTime;//窗口的初始结束时间初始化为开门时间
	for(int i = 0; i < n; i++)
	{
		int hh, mm, ss, last;
		int arriveTime;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &last);
		arriveTime = ss + mm * 60 + hh * 60 * 60;
		if(arriveTime > edTime)
			continue;
		if(last > 60)
			last = 60;
		Customer tmp;
		tmp.aTime = arriveTime;
		tmp.sTime = last * 60;
		c.push_back(tmp);
	}
	sort(c.begin(), c.end(), cmp);
	for(int i = 0; i < c.size(); i++)//对于每一个顾客
	{
		//选择当前最早结束服务的窗口
		int idx = -1, minEndTime = 0x3fffffff;
		for(int j = 0; j < k; j++)
		{
			if(w[j] < minEndTime)
			{
				minEndTime = w[j];
				idx = j;
			}
		}
		//idx就是最早服务结束的窗口编号，将客户customer[i]分配到该窗口
		if(c[i].aTime < w[idx])//客户来的比窗口结束服务时间要早
		{						//客户需要等待
			totTime += w[idx] - c[i].aTime;
			w[idx] += c[i].sTime;
		}
		else//客户来的比窗口结束服务时间要晚，可以直接服务，不用等待
		{
			w[idx] = c[i].sTime + c[i].aTime;
		}
	}
	if(c.size() == 0)
		printf("0.0\n");
	else
		printf("%.1f\n", totTime / 60.0 / c.size());
	return 0;
}