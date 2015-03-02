//PAT_1026. Table Tennis (30)
//Miibotree
//2015.3.2
//这道题目的逻辑很复杂，细节地方必须注意好
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
const int K = 111;//窗口数
const int INF = 1000000000;//无穷大

struct Player{
	int arriveTime;//到达时间
	int startTime;//开始训练时间
	int trainTime;//训练时长
	int isVIP;
}newPlayer;

struct Table
{
	int endTime;//当前占用该球桌的球员的结束时间
	int numServe;
	bool isVIP;
}table[K];

vector<Player> player;

int convertTime(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}

bool cmpArriveTime(Player a, Player b)
{
	return a.arriveTime < b.arriveTime;
}

bool cmpStartTime(Player a, Player b)
{
	return a.startTime < b.startTime;	
}

int nextVIPPlayer(int VIPi)//编号VIPi从当前VIP球员移到下一个VIP球员
{
	VIPi++;
	while(VIPi < player.size() && player[VIPi].isVIP == 0)
	{
		VIPi++;//只要当前球员不是VIP，就让VIP后移一位
	}
	return VIPi;
}

//将编号为tID的球桌分配给编号为pID的球员
void allotTable(int pID, int tID)
{
	if(player[pID].arriveTime <= table[tID].endTime)
		player[pID].startTime = table[tID].endTime;
	else
		player[pID].startTime = player[pID].arriveTime;
	//该球桌的训练结束时间更新为新球员的结束时间，并让服务人数+1
	table[tID].endTime = player[pID].startTime + player[pID].trainTime;
	table[tID].numServe++;
}

int main()
{
	int n, k, m, VIPtable;
	scanf("%d", &n);
	int stTime = convertTime(8, 0, 0);//开门时间
	int edTime = convertTime(21, 0, 0);//关门时间

	for(int i = 0; i < n; i++)
	{
		int h, m, s, trainTime, isVIP;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVIP);
		newPlayer.arriveTime = convertTime(h, m, s);
		newPlayer.startTime = edTime;//开始时间初始化为21点
		if(newPlayer.arriveTime >= edTime)
			continue;
		newPlayer.trainTime = trainTime <= 120 ? trainTime * 60 : 7200;
		newPlayer.isVIP = isVIP;
		player.push_back(newPlayer);
	}

	scanf("%d%d", &k, &m);
	for(int i = 1; i <= k; i++)//球桌的初始化
	{
		table[i].endTime = stTime;
		table[i].numServe = table[i].isVIP = 0;
	}
	for(int i = 0; i < m; i++)//VIP桌子标记
	{
		scanf("%d", &VIPtable);
		table[VIPtable].isVIP = 1;
	}


	sort(player.begin(), player.end(), cmpArriveTime);
	int i = 0, VIPi = -1;//i用来扫描所有球员，VIPi总是指向当前最前的VIP球员
	VIPi = nextVIPPlayer(VIPi);//找到第一个VIP球员的编号
	while(i < player.size())//当前队列最前面的球员为 i
	{
		int idx = -1, minEndTime = INF;//寻找最早能空闲的球桌
		for(int j = 1; j <= k; j++)
		{
			if(table[j].endTime < minEndTime)
			{
				minEndTime = table[j].endTime;
				idx = j;
			}
		}
		//idx为最早空闲的球桌编号
		if(table[idx].endTime >= edTime)//已经关门，直接break
			break;
		if(player[i].isVIP == 1 && i < VIPi)
		{
			i++;
			continue;
		}
		//一下按球桌是否是VIP，球员是否是VIP，进行四种情况的讨论
		if(table[idx].isVIP == 1)
		{
			if(player[i].isVIP == 1)//球桌是VIP，球员是VIP
			{
				allotTable(i, idx);
				if(VIPi == i)
					VIPi = nextVIPPlayer(VIPi);
				i++;
			}
			else//球桌是VIP，球员不是VIP
			{
				if(VIPi < player.size() && player[VIPi].arriveTime <= table[idx].endTime)
				{
					allotTable(VIPi, idx);
					VIPi = nextVIPPlayer(VIPi);
				}
				else
				{
					allotTable(i, idx);
					i++;
				}

			}
		}
		else
		{
			if(player[i].isVIP == 0)//球桌不是VIP，球员不是VIP
			{
				allotTable(i, idx);
				i++;
			}
			else//球桌不是VIP，球员是VIP
			{
				int VIPidx = -1, minVIPEndTime = INF;
				//找到最早空闲的VIP球桌
				for(int j = 1; j <= k; j++)
				{
					if(table[j].isVIP == 1 && table[j].endTime < minVIPEndTime)
					{
						minVIPEndTime = table[j].endTime;
						VIPidx = j;
					}
				}
				//最早空闲的VIP球桌编号为VIPidx
				if(VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime)
				{
					allotTable(i, VIPidx);
					if(VIPi == i)
						VIPi = nextVIPPlayer(VIPi);
					i++;
				}
				else
				{
					allotTable(i, idx);
					if(VIPi == i)
						VIPi = nextVIPPlayer(VIPi);
					i++;
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmpStartTime);
	for(i = 0; i < player.size() && player[i].startTime < edTime; i++)
	{
		int t1 = player[i].arriveTime;
		int t2 = player[i].startTime;
		printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round(t2 - t1) / 60.0);
	}

	for(i = 1; i <= k; i++)
	{
		printf("%d", table[i].numServe);
		if(i < k )	printf(" ");
	}
	return 0;
}

