//PAT_1072. Gas Station (30)
//Dijkstra Algorithm
//规则：1.使用Dijks
//2.找到距离最大的那个加油站
//3.找到的那个加油站离所有村庄的距离都不能大于Ds
//4.如果有相同，找到离所有村庄avg最小的
//5.如果还是有相同，输出序号最小的

#include <stdio.h>
#include <vector>
using namespace std;
struct Edge{
	int next;
	double c;
};
vector<Edge> edge[1020];
int Dis[1020];
int mark[1020];
int n, m, k, Ds;

void Dijkstra(int s)
{	
	int newP;
	//step1.init
	for(int i = 1; i < 1020; i++)
	{
		Dis[i] = -1;
		mark[i] = false;
	}
	Dis[s] = 0;
	mark[s] = true;
	newP = s;
	for(int i = 1; i < n + m; i++)//外层的循环
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[t] > Dis[newP] + c)
				Dis[t] = Dis[newP] + c;
		}
		int min = 999999999;
		for(int j = 1; j <= m + n; j++)
		{
			if(mark[j] == true || Dis[j] == -1)
				continue;
			if(Dis[j] < min)
			{
				min = Dis[j];
				newP = j;
			}
		}
		mark[newP] = true;
	}
}

int tonum(char s[])
{
	int num;
	if(s[0] != 'G')
	{
		sscanf(s, "%d", &num);
		return num;
	}
	else
	{
		sscanf(&s[1], "%d", &num);
		return num + n;
	}
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &k, &Ds);
	for(int i = 1; i <= k; i++)
	{
		char str1[10], str2[10];
		double d;
		scanf("%s %s %lf", str1, str2, &d);
		int c1 = tonum(str1);
		int c2 = tonum(str2);
		Edge tmp;
		tmp.c = d;
		tmp.next = c1;
		edge[c2].push_back(tmp);
		tmp.next = c2;
		edge[c1].push_back(tmp);
	}
	int ans = -1;
	double ansAvg = 999999999, ansMin = -1;
	for(int i = n + 1; i <= n + m; i++)//对每一个加油站使用Dijks
	{
		Dijkstra(i);
		int flag = true;//判断加油站距离所有村庄都小于等于Ds
		double Avg = 0;
		int Min = 999999999;
		for(int j = 1; j <= n; j++)
		{
			if(Dis[j] > Ds)
			{
				flag = false;
				break;
			}
			Avg += Dis[j];
			if(Dis[j] < Min)
				Min = Dis[j];
		}
		if(flag == false)
			continue;
		else
		{
			Avg /= n;
			if(Min > ansMin)
			{
				ansMin = Min;
				ans = i;
				ansAvg = Avg;
			}
			else if(Min == ansMin && ansAvg > Avg)
			{
				ans = i;
				ansAvg = Avg;
			}
		}
	}

	if(ans == -1)
		printf("No Solution\n");
	else
		printf("G%d\n%.1f %.1f\n", ans - n, ansMin, ansAvg);
	return 0;
}