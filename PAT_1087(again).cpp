//PAT_1087. All Roads Lead to Rome (30)
//1.花费最小（这里的花费可以看成是路径长度）
//2.花费相同，happiness最大
//3.maximum average happiness
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Edge{
	int next;
	int c;
};
vector<Edge> edge[210];

int n, k;
int Dis[210];//花费数组
int w[210];
int happy[210];//快乐值
int number[210];//最短路径条数
int pt[210];//路径上的节点个数
int pre[210];//前驱节点
bool mark[210];

map<string, int> City2Int;
map<int, string> Int2City;

void Dijkstra()
{
	//step1:init
	for(int i = 0; i < n; i++)
	{
		mark[i] =false;
		Dis[i] = -1;
		number[i] = 0;
		pt[i] = 0;
		w[i] = 0;
	}
	mark[0] = true;
	Dis[0] = 0;
	pt[0] = 0;
	number[0] = 1;
	w[0] = 0;
	int newP = 0;
	//step2:main algorithm
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			int h = happy[t];
			if(mark[t] == true)
				continue;
			if(Dis[t] == -1 || Dis[newP] + c < Dis[t])
			{
				Dis[t] = Dis[newP] + c;
				w[t] = w[newP] + h;
				number[t] = number[newP];
				pt[t] = pt[newP] + 1;
				pre[t] = newP;
			}
			else if(Dis[t] == Dis[newP] + c)
			{
				number[t] += number[newP];
				if(w[t] < w[newP] + h)
				{
					w[t] = w[newP] + h;
					pt[t] = pt[newP] + 1;
					pre[t] = newP;
				}
				else if(w[t] == w[newP] + h)
				{
					double newPAvg = 1.0 * w[t] / (pt[newP] + 1);
					double tAvg = 1.0 * w[t] / pt[t];
					if(newPAvg > tAvg)
					{
						pt[t] = pt[newP] + 1;
						pre[t] = newP;
					} 
				}
			}
		}
		int min = 0x3fffffff;
		for(int j = 1; j < n; j++)
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

void PrintPath(int v)
{
	if(v == 0)//回溯到了原点
	{
		cout<<Int2City[v];
		return;
	}
	PrintPath(pre[v]);
	cout<<"->"<<Int2City[v];
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	string city, start;
	cin>>n>>k>>start;
	City2Int[start] = 0;
	Int2City[0] = start;

	for(int i = 1; i < n; i++)
	{
		int h;
		cin>>city>>h;
		City2Int[city] = i;
		Int2City[i] = city;
		happy[i] = h;
	}

	for(int i = 0; i < k; i++)
	{
		string c1, c2;
		int d;
		cin>>c1>>c2>>d;
		int a, b;
		a = City2Int[c1];
		b = City2Int[c2];
		Edge tmp;
		tmp.c = d;
		tmp.next = a;
		edge[b].push_back(tmp);
		tmp.next = b;
		edge[a].push_back(tmp);
	}
	Dijkstra();
	int e = City2Int["ROM"];
	printf("%d %d %d %d\n", number[e], Dis[e], w[e], w[e] / pt[e]);
	PrintPath(e);
	return 0;
}

