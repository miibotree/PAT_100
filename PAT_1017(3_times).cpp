//PAT_1014. Waiting in Line (30)
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Window{
	int endTime;
	int popTime;
	queue<int>q;
}w[21];
int ans[1001], serveTime[1001];

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n, m, k, q, i;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(i = 0; i < k; i++)
		scanf("%d", &serveTime[i]);
	//初始化每个窗口
	for(i = 0; i < n; i++)
	{
		w[i].endTime = w[i].popTime = 8 * 60;
	}
	//先将前n * m 个人入队列
	int cnt = 0;//
	for(i = 0; i < min(n*m, k); i++)//因为涉及到余数，所以还是从0开始
	{
		w[cnt % n].endTime += serveTime[cnt];//结束时间增加
		w[cnt % n].q.push(cnt);//入队列
		ans[cnt] = w[cnt % n].endTime;//计算答案
		//如果是窗口第一个服务的成员，还需要计算pop time
		if(cnt < n)
			w[cnt].popTime += serveTime[cnt]; 
		cnt++;
	}
	//再继续排余下的人
	for(; cnt < k; cnt++)
	{
		//首先找到pop时间最短的窗口
		int idx = -1, min = 0x3fffffff;
		for(int j = 0; j < n; j++)
		{
			if(w[j].popTime < min)
			{
				min = w[j].popTime;
				idx = j;
			}
		}
		//更新该窗口队列
		w[idx].q.pop();//队首出队列
		w[idx].q.push(cnt);//入队列
		w[idx].popTime += serveTime[w[idx].q.front()];
		w[idx].endTime += serveTime[cnt];
		ans[cnt] = w[idx].endTime;
	}
	while(q--)
	{
		int x;
		scanf("%d", &x);
		if(ans[x-1] - serveTime[x - 1] >= 17 * 60)//开始服务时间 = 结束服务时间 - 服务时长
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", ans[x-1]/60, ans[x-1]%60);
	}
	return 0;
}


