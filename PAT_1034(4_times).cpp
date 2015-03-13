//PAT_1034 Head of a Gang
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Edge
{
	int next;
	int w;
};
vector<Edge> edge[3000];
int w[3000];
map<string, int> Name2Id;
map<int, string> Id2Name;
map<string, int> Gang;//头目,数目
int n, k;
int number = 0;
bool visit[3000];

int change(string s)
{
	if( Name2Id.find(s) == Name2Id.end() )//没有找到
	{
		number++;
		Name2Id[s] = number;
		Id2Name[number] = s;
		return number;
	}
	else
		return Name2Id[s];
}
void DFS(int x, int &head, int &totalWeight, int &gangNum)
{
	gangNum++;
	visit[x] = true;
	if(w[x] > w[head])//更换头目
		head = x;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int idx = edge[x][i].next;
		totalWeight += edge[x][i].w;//这里先累加边权
		if(visit[idx] == false)//然后再考虑递归的问题
			DFS(idx, head, totalWeight, gangNum);
	}
}


void DFSTrave()
{
	for(int i = 1; i <= number; i++)//遍历所有人
	{
		if(visit[i] == false)//还没有被遍历过
		{
			int totalWeight = 0, gangNum = 0, head = i;
			DFS(i, head, totalWeight, gangNum);
			if(totalWeight > k * 2 && gangNum > 2)
				Gang[Id2Name[head]] = gangNum;
		}
	}
}


int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	while(n--)
	{
		string s1, s2;
		int weight;
		cin>>s1>>s2>>weight;
		int name1 = change(s1);
		int name2 = change(s2);
		w[name1] += weight;
		w[name2] += weight;
		Edge tmp;
		tmp.w = weight;
		tmp.next = name1;
		edge[name2].push_back(tmp);
		tmp.next = name2;
		edge[name1].push_back(tmp);
	}
	DFSTrave();
	printf("%d\n", Gang.size());
	map<string, int>::iterator it;//map也是直接按照字典序排好了
	for(it = Gang.begin(); it != Gang.end(); it++)
	{
		printf("%s %d\n", it->first.c_str(), it->second);
	}
	return 0;
}