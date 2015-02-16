//PAT_1034. Head of a Gang (30)
//Miibotree
//2015.2.16
//参考博客：http://blog.csdn.net/acm_ted/article/details/20789637
//分析：1.可以使用并查集，也可以使用DFS，DFS更加简单，并查集需要更多保存更多数据
//		2.名字的存储,可以hash映射，或者用stl可以直接排序
//这道题目用stl代码非常短

#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 0x6fffffff;
map<string, int> weight;
map<string, bool> flag;
map<string, int> out;
map<string, vector<string> >link;//邻接链表
int idx, allWeight;
string st;//存储头

void dfs(string x)
{
	flag[x] = true;//该人已经被遍历过
	allWeight += weight[x];
	if(weight[x] > weight[st])//当前的权值大于头的权值
		st = x;
	for(vector<string>::iterator it = link[x].begin();
		it != link[x].end(); ++it)
	{
		if(flag[*it] == false)
			dfs(*it);//为什么要加*
	}
	++idx;
}

int main()
{
	int n, k;
	int w;
	char a[5], b[5];
	string aName, bName;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%s%s%d", a, b, &w);
		aName = string(a);
		bName = string(b);
		if(weight.find(aName) == weight.end())
			weight.insert(make_pair(aName, w));
		else
			weight.find(aName)->second += w;
		if(weight.find(bName) == weight.end())
			weight.insert(make_pair(bName, w));
		else
			weight.find(bName)->second += w; 
		link[aName].push_back(bName);
		link[bName].push_back(aName);
		flag[aName] = false;//flag是访问标记
		flag[bName] = false;
	}
	for(map<string, bool>::iterator it = flag.begin();
		it != flag.end(); ++it)
	{
		if(it->second == false)//该人没有被访问过，深度优先遍历
		{
			idx = 0;
			allWeight = 0;
			st = it->first;
			dfs(st);
			if(idx > 2 && allWeight / 2 > k)
				out[st]= idx;
		}
	}
	printf("%d\n", out.size());//map自动排序
	for(map<string, int>::iterator it = out.begin(); 
		it != out.end(); it++)
	{
		printf("%s %d\n", it->first.c_str(), it->second);
	}
	return 0;
}
