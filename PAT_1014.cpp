//PAT_1014.Waiting in Line
//Miibotree
//2015.2.5
// 模拟题
#include <stdio.h>
#include <queue>

using namespace std;

struct info{
	int serve_time;//总共需要服务时间
	int hour;//记录完成的小时
	int minute;//记录完成的分钟
	int flag;//是否在排队
	int spend;//已经服务了多少时间
	int q;//排在哪个队伍
	int finish;
}Customer[1001];

int T[1001];
queue<int> window[21];
int w_num[21];

void Init()
{
	for(int i = 1; i <= 1000; i++)
	{
		Customer[i].finish = false;
		Customer[i].serve_time = 0;
		Customer[i].hour = 0;
		Customer[i].minute = 0;
		Customer[i].flag = false;
		Customer[i].spend = 0;
		Customer[i].q = 0;
	}
	for(int i = 1; i <= 20; i++)
	{
		w_num[i] = 0;
		while(window[i].empty() == false)
			window[i].pop();
	}

}

int main()
{
	int n, m, k, q;
	while(scanf("%d%d%d%d", &n, &m, &k, &q) != EOF)
	{
		Init();
		for(int i = 1; i <= k; i++)
			scanf("%d", &Customer[i].serve_time);

		for(int h = 8; h <= 17; h++)//小时
		{
			for(int mm = 0; mm <= 59; mm++)//分钟
			{
				if(h == 17 && mm != 0)
					continue;
				for(int i = 1; i <= k; i++)//轮询每个人
				{
					if(Customer[i].flag == true && Customer[i].finish == false)//已经入队列并且还没有完成服务
					{
					
						if(Customer[i].spend == Customer[i].serve_time)//服务完毕
						{
							Customer[i].hour = h;
							Customer[i].minute = mm;
							Customer[i].finish = true;
							window[Customer[i].q].pop();//把最先进入队列的人弹出来
							w_num[Customer[i].q]--;
						}
					}
					else//还没入队列
					{
						//找到排队人数最少的队列
						int cur = 1, min = m;
						int flag = false;
						for(int j = 1; j <= n; j++)//查询是否有窗口可以排队
						{
							if(w_num[j] < m)
							{
								if(w_num[j] < min)
								{
									flag = true;
									cur = j;
									min = w_num[j];
								}
							}
						}
						if(flag)//该窗口还可以排队
						{
							window[cur].push(i);
							w_num[cur]++;
							Customer[i].flag = true;
							Customer[i].q = cur;
						}
					}
				}
				for(int j = 1; j <= n; j++)//队首的处理时间加1
				{
					if(window[j].empty() == false)
					{
						int f = window[j].front();
						Customer[f].spend++;
					}	
				}
			}
		}

		//如果队列还有非空，则可以继续处理
		for(int j = 1; j <= n; j++)//队首的处理时间加1
		{
			if(window[j].empty() == false)
			{
				int f = window[j].front();
				Customer[f].spend++;
			}	
		}

		for(int i = 1; i <= q; i++)
		{
			int x;
			scanf("%d", &x);		
			if(Customer[x].finish == true)
				printf("%02d:%02d\n", Customer[x].hour, Customer[x].minute);
			else
				printf("Sorry\n");
		}
	}
}
