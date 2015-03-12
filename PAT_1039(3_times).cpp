#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;
map<string, int> name2idx;
map<int, string> idx2name;
set<int> s[40020];
int n, k;
int cnt = 0;

int change(string s)
{
	if(name2idx.find(s) != name2idx.end())//找到了
		return name2idx[s];
	else
	{
		name2idx[s] = cnt;
		idx2name[cnt] = s;
		return cnt++;
	}
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int idx, num, order;
	string name;
	scanf("%d%d", &n, &k);
	while(k--)
	{

		scanf("%d%d", &idx, &num);
		for(int i = 0; i < num; i++)
		{
			cin>>name;
			order = change(name);
			s[order].insert(idx);
		}
	}
	for(int i = 0; i < n; i++)
	{
		cin>>name;
		order = change(name);
		printf("%s %d", name.c_str(), s[order].size());
		for(set<int>::iterator it = s[order].begin(); it != s[order].end(); it++)
		{
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}