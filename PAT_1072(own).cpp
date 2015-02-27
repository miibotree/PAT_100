//PAT_1072. Gas Station (30)
//Miibotree
//2015.2.19
//Dijkstra算法
//这道题目的意思不好理解
//1.使用Dijkstra算法计算每个加油站到所有村庄的距离
//2.选出每个加油站到所有村庄距离中最短的那个距离minDis
//3.选取的加油站必须是minDis最大的那个加油站
//4.minDis相同的情况下，选取到所有村庄平均距离最小的加油站
//5.上述若都相同，选择序号最小的加油站
#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 1000000000
using namespace std;

struct Edge{
	int next;
	int c;
};
vector<Edge> edge[10001];
bool mark[10020];
int Dis[10020];
int n, m, k, DS;

void Dijkstra(int s)
{
	for(int i = 1; i <= n + m; i++)
	{
		mark[i] = false;
		Dis[i] = -1;//表示不可达
	}
	mark[s] = true;
	Dis[s] = 0;
	int newP = s;
	for(int i = 1; i < n + m; i++)//执行n+m-1次
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int n = edge[newP][j].next;
			int c = edge[newP][j].c;
			if(mark[n] == true)
				continue;
			if(Dis[n] == -1 || Dis[newP] + c < Dis[n])
				Dis[n] = Dis[newP] + c;
		}
		int min = INF;
		for(int i = 1; i <= n+m; i++)
		{
			if(mark[i] == true || Dis[i] == -1)
				continue;
			else if(Dis[i] < min)
			{
				min = Dis[i];
				newP = i;
			}
		}
		mark[newP] = true;
	}
}

int getID(char str[])
{
	int len = strlen(str);
	int i = 0;
	int ID = 0;
	while(i < len)
	{
		if(str[i] != 'G')
			ID = ID * 10 + str[i] - '0';
		i++;
	}
	if(str[0] == 'G')
		return ID + n;
	else
		return ID;
}

int main()
{
	scanf("%d%d%d%d", &n,&m, &k, &DS);
	for(int i = 1; i <= n + m; i++)
	{
		edge[i].clear();
	}

	for(int i = 0; i < k; i++)
	{
		char city1[5], city2[5];
		int dist;
		scanf("%s %s %d", city1, city2, &dist);
		int id1 = getID(city1);
		int id2 = getID(city2);
		Edge tmp;
		tmp.c = dist;
		tmp.next = id2;
		edge[id1].push_back(tmp);
		tmp.next = id1;
		edge[id2].push_back(tmp);
	}
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;
	for(int i = n + 1; i <= n + m; i++)//对每一个加油站使用Dijstra算法
	{
		Dijkstra(i);
		double minDis = INF;
		double avg = 0;
		for(int j = 1; j <= n; j++)
		{
			if(Dis[j] > DS)//加油站到村庄的距离超过了DS
			{
				minDis = -1;
				break;
			}
			if(Dis[j] != -1 && Dis[j] < minDis)//题目中似乎都存在通路
				minDis = Dis[j];
			avg += 1.0 * Dis[j] / n;
		}
		if(minDis == -1)
			continue;
		else if(minDis > ansDis || minDis == ansDis && avg < ansAvg)
		{
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}
	}
	if(ansID == -1)
		printf("No Solution\n");
	else
		printf("G%d\n%.1lf %.1lf\n", ansID - n, ansDis, ansAvg);
	return 0;
}