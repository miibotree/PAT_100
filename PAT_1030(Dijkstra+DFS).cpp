//PAT_1030. Travel Plan (30)
//Dijkstra + DFS
#include <stdio.h>
#include <vector>
#define N 501
using namespace std;
struct Edge{
	int next;
	int cost;
	int c;
};
int n, m, s, e;
vector<Edge> edge[N];
int Mcost[N][N];//DFS计算第二条件的时候直接调用这里好了
int Dis[N], Cost[N], mark[N]; 
vector<int> pre[N];
vector<int> path, tempPath;

void Dijkstra(int s)//如果采用Dij+DFS，那么这里的Dijkstra算法就不用变了
{
	for(int i = 0; i < n; i++)
	{
		Dis[i] = -1;
		Cost[i] = 0;
		mark[i] = false;
		pre[i].push_back(i);
	} 
	Dis[s] = 0;
	mark[s] = true;
	int newP = s;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			int cost = edge[newP][j].cost;
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[newP] + c < Dis[t])
			{
				Dis[t] = Dis[newP] + c;
				pre[t].clear();
				pre[t].push_back(newP);
			}
			else if(Dis[newP] + c == Dis[t])
				pre[t].push_back(newP);
		}
		int min = 0x3fffffff;
		for(int j = 0; j < n; j++)
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

int optvalue = 0x3fffffff;
void DFS(int v)
{
	if(v == s)//递归到了起点
	{
		tempPath.push_back(s);
		int value = 0;
		for(int i = tempPath.size() - 1; i > 0; i--)
		{
			int id = tempPath[i], nextid = tempPath[i-1];
			value += Mcost[id][nextid];
		}
		if(value < optvalue)
		{
			optvalue = value;
			path = tempPath;
		}
		tempPath.pop_back();
		return ;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	tempPath.pop_back();
}

void PrintPath()
{
	for(int i = path.size() - 1; i >=0; i--)
		printf("%d ", path[i]);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &e);
	while(m--)
	{
		int c1, c2, d, c;
		scanf("%d%d%d%d", &c1, &c2, &d, &c);
		Edge tmp;
		tmp.c = d;
		tmp.cost = c;
		tmp.next = c1;
		edge[c2].push_back(tmp);
		tmp.next = c2;
		edge[c1].push_back(tmp);
		Mcost[c1][c2] = Mcost[c2][c1] = c;
	}
	Dijkstra(s);
	DFS(e);//从后向前递归
	PrintPath();//递归输出的
	printf("%d %d\n", Dis[e], optvalue);
	return 0;
}
