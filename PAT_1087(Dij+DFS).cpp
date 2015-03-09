//PAT_1087. All Roads Lead to Rome (30)
//Dijkstra + DFS
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#define N 300
using namespace std;
int Dis[N], mark[N], num[N], weight[N];
vector<int> pre[N];
vector<int>tempPath, path;
struct Edge
{
	int next;
	int c;
};
vector<Edge> edge[N];
int n, m;
map<string, int>City2Int;
map<int, string>Int2City;

void Dijkstra(int s)
{
	for(int i = 0; i < n; i++)
	{
		mark[i] = false;
		Dis[i] = -1;
		num[i] = 0;
		pre[i].push_back(i);
	}
	mark[s] = true;
	Dis[s] = 0;
	num[s] = 1;
	int newP = s;
	for(int i = 0; i < n; i++)
	{
		for(int j  = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[t] > Dis[newP] + c)
			{
				Dis[t] = Dis[newP] + c;
				num[t] = num[newP];
				pre[t].clear();
				pre[t].push_back(newP);
			}
			else if(Dis[t] == Dis[newP] + c)
			{				
				num[t] += num[newP];
				pre[t].push_back(newP);

			}
		}
		int min = 0x3fffffff;
		for(int j = 1; j < n; j++)
		{
			if(Dis[j] == -1 || mark[j] == true)
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

int optValue = -1, optAvg = -1;
void DFS(int v)
{
	if(v == 0)//到了起点
	{
		int value = 0, avg = 0;
		tempPath.push_back(v);
		for(int i = 0; i < tempPath.size() - 1; i++)//注意起点的点值不要算进去
		{
			int idx = tempPath[i];
			value += weight[idx];
		}
		avg = value / (tempPath.size() - 1);//起点不算
		if(value > optValue || value == optValue && avg > optAvg)
		{
			path = tempPath;
			optValue = value;
			optAvg = avg;
		}

		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	tempPath.pop_back();
}

void PrintInfo(int rome)
{
	printf("%d %d %d %d\n", num[rome], Dis[rome], optValue, optAvg);
	for(int i = path.size() - 1; i >= 0; i--)
	{
		int idx = path[i];
		cout<<Int2City[idx];
		if(i != 0)
			cout<<"->";
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	string start;
	cin>>start;
	City2Int[start] = 0;
	Int2City[0] = start;
	for(int i = 1; i < n; i++)
	{
		string city;
		int happy;
		cin>>city>>happy;
		City2Int[city] = i;
		Int2City[i] = city;
		weight[i] = happy;
	}
	while(m--)
	{
		int c;
		string c1, c2;
		cin>>c1>>c2>>c;
		int a, b;
		a = City2Int[c1];
		b = City2Int[c2];
		Edge tmp;
		tmp.c = c;
		tmp.next = a;
		edge[b].push_back(tmp);
		tmp.next = b;
		edge[a].push_back(tmp);
	}
	Dijkstra(0);
	int rome = City2Int["ROM"];
	DFS(rome);
	PrintInfo(rome);
	return 0;
}