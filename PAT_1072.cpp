//PAT_1072. Gas Station (30)
//Miibotree
//2015.2.27
//Dijkstra算法
//这道题目的意思不好理解
//1.使用Dijkstra算法计算每个加油站到所有村庄的距离
//2.选出每个加油站到所有村庄距离中最短的那个距离minDis
//3.选取的加油站必须是minDis最大的那个加油站
//4.minDis相同的情况下，选取到所有村庄平均距离最小的加油站
//5.上述若都相同，选择序号最小的加油站


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 1020;
const int INF = 1000000000;

int n, m, k, DS, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s)
{
	memset(vis, false, sizeof(vis));//注意这里每次使用Dij算法都要初始化一下
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for(int i = 0; i < n + m; i++)//遍历的次数
	{
		int u = -1, MIN = INF;
		for(int j = 1; j <= n + m; j++)//找到距离最小的顶点
		{
			if(vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1)	return;
		vis[u] = true;//放入已访问集合
		for(int v = -1; v <= n + m; v++)//为什么从-1开始？
		{
			if(vis[v] == false && G[u][v] != INF)
			{
				if(d[u] + G[u][v] < d[v])
					d[v] = d[u] + G[u][v];
			}
		}
	}
}

int getID(char str[])//house的编号为1-n 而gas station的编号为n+1开始
{
	int i = 0, len = strlen(str), ID = 0;
	while(i < len)
	{
		if(str[i] != 'G')
			ID = ID * 10 + (str[i] - '0');
		i++;
	}
	if(str[0] == 'G')	
		return n + ID;
	else
		return ID;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &DS);
	int u, v, w;
	char city1[5], city2[5];	//由于输入的顶点序号中含字母G，故用字符串的方式读取
	fill(G[0], G[0] + MAXV * MAXV, INF);//临接矩阵的初始化
	for(int i = 0; i < k; i++)
	{
		scanf("%s %s %d", city1, city2, &w);
		u = getID(city1);
		v = getID(city2);
		G[v][u] = G[u][v] = w;//给边赋权值
	}
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;
	for(int i = n + 1; i <= n + m; i++)//遍历每一个gas station
	{
		double minDis = INF, avg = 0;//minDis存放的是加油站到所有村庄里面最小的那个距离
		Dijkstra(i);
		for(int j = 1; j <= n; j++)
		{
			if(d[j] > DS)//i加油站到每一个村庄的距离都必须在DS范围之内
			{
				minDis = -1;
				break;
			}
			if(d[j] < minDis)	minDis = d[j];
			avg += 1.0 * d[j] / n;
		}
		if(minDis == -1)	continue;
		if(minDis > ansDis)//最小的那个距离要最大
		{
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}
		else if(minDis == ansDis && avg < ansAvg)//最小距离相同情况下，平均距离最小
		{
			ansID = i;
			ansAvg = avg;
		}
	}
	if(ansID == -1)
		printf("No Solution\n");
	else
	{
		printf("G%d\n", ansID - n);
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}
	return 0;
}