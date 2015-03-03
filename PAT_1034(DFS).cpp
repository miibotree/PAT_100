//PAT_1034.Head of a Gang
//Miibotree
//2015.3.3
//使用DFS遍历，把题目抽象出来的话，得到点权的概念和边权之和的概念。
//这里还是使用的是邻接表的方法，感觉自己使用邻接表更熟一点
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Edge{
	int next;
	int weight;
};

map<string, int>Gang;//Gang头目和对应的成员数
map<string, int>String2Int;
map<int, string>Int2String;
vector<Edge>edge[2020];	
int w[2020];//每个顶点的权值
int visit[2020];
int cnt = 0;//存放不同的人数
int n, k;

int change(string s)
{
	if(String2Int.find(s) == String2Int.end())//不存在
	{
		String2Int[s] = cnt;
		Int2String[cnt] = s;
		return cnt++;
	}
	else
		return String2Int[s];
}


void DFS(int i, int &head, int &numMember, int &totalValue)//关键就是这里的DFS代码
{
	visit[i] = true;
	numMember++;
	if(w[i] > w[head])
		head = i;
	for(int j = 0; j < edge[i].size(); j++)
	{
		Edge tmp = edge[i][j];
		int Idx = tmp.next;
		totalValue += edge[i][j].weight;
		if(visit[Idx] == false)
			DFS(Idx, head, numMember, totalValue);
	}
}

void DFSTrave()
{
	for(int i = 0; i < cnt; i++)//对每一个人进行遍历
	{
		if(visit[i] == false)//这个人还没有被遍历过
		{
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if(numMember > 2 && totalValue > 2 * k)//由于是无向边，所以这里 2 * k
				Gang[Int2String[head]] = numMember;
		}
	}
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)//输入
	{
		char str1[4], str2[4];
		int weight;
		scanf("%s %s %d", str1, str2, &weight);
		string s1 = str1;
		string s2 = str2;
		int name1 = change(s1);
		int name2 = change(s2);
		w[name1] += weight;
		w[name2] += weight;//点权增加
		Edge tmp;
		tmp.weight = weight;
		tmp.next = name1;
		edge[name2].push_back(tmp);//注意这里应该看成是无向边，如果看成有向边的话可能会造成访问不到的情况
		tmp.next = name2;
		edge[name1].push_back(tmp);
	} 
	DFSTrave();
	printf("%d\n", Gang.size());
	map<string, int>::iterator it;
	for(it = Gang.begin(); it != Gang.end(); it++)
		printf("%s %d\n", it->first.c_str(), it->second);
	return 0;
}