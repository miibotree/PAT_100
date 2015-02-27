//PAT_1034.Head of a Gang(22 / 30)
//Miibotree
//2015.2.26
//用并查集重写该题
//思路：1.关于姓名和数字的转换，使用map映射,而且map是自动排序的
//		2.需要记录每个集合的老大和元素，故再开两个数组记录
#include <stdio.h>
#include <map>
#include <string>
#define max 2010
using namespace std;

map<int, string> Int2String;
map<string, int> String2Int;

int Tree[max];
int weight[max];
int Gang[max];//存放每个集和 最大权值的序号
int Gangweight[max];//存放每个集的权值之和
int Gangnum[max];//集和的数目
int sum = 0;
int flag[max] = {false};//遍历标志

int change(string s)
{
	if(String2Int.find(s) != String2Int.end())//说明存在
		return String2Int[s];
	else//不存在
	{
		String2Int[s] = sum;
		Int2String[sum] = s;
		return sum++;
	}
}

int findRoot(int x)
{
	int ret;
	int tmp = x;
	while(Tree[x] != -1)
		x = Tree[x];
	ret = x;
	x = tmp;
	while(Tree[x] != -1)
	{
		int t = Tree[x];
		Tree[x] = ret;
		x = t;
	}
	return ret;
}

int main()
{
	int n, k, i;
	int root;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		for(i = 0; i < max; i++)
		{
			Tree[i] = -1;
			Gangnum[i] = 1;
		}
		for(i = 0; i < n; i++)//Set Union
		{
			char str1[4], str2[4];
			int w, name1, name2;
			scanf("%s %s %d", str1, str2, &w);
			string s1 = str1;	string s2 = str2;
			name1 = change(s1);	name2 = change(s2);
			weight[name1] += w;
			weight[name2] += w;
			name1 = findRoot(name1);
			name2 = findRoot(name2);
			if(name1 != name2)
			{
				Tree[name1] = name2;//合并
				Gangnum[name2] += Gangnum[name1];//Gangnum数组存放集合的数量
			}
		}

		//找出每个集和的gang，判断是否满足gang的条件
		for(i = 0; i < sum; i++)
		{
			if(Tree[i] == -1)
				Gang[i] = i;//首先把每个集合的gang设置为根节点
		}
		for(i = 0; i < sum; i++)//找出每个集合的gang
		{
			root = findRoot(i);
			Gangweight[root] += weight[i];
			if(weight[i] >= weight[Gang[root]])
				Gang[root] = i;
		}
		int flag = false;
		int cnt = 0;
		for(i = 0; i < sum; i++)
		{
			if(Tree[i] == -1)//说明是根节点
			{
				if(Gangnum[i] > 2 && Gangweight[i] > k * 2)
				{
					cnt++;
					flag = true;
				}
			}
		}

		if(flag == false)
			printf("0\n");
		else
		{
			printf("%d\n", cnt);
			for(i = 0; i < sum; i++)
			{
				if(Tree[i] == -1)//说明是根节点
				{
					if(Gangnum[i] > 2 && Gangweight[i] > k * 2)
					{
						printf("%s %d\n", Int2String[Gang[i]].c_str(), Gangnum[i]);
					}
				}
			}
		}
	}
	return 0;
}