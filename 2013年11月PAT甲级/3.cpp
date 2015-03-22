//PAT_1071. Speech Patterns (25)
#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
map<string, int> m;

bool judge(char c)
{
	if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}

bool cmp(int a, int b)
{
	if(a != b)
		return a > b;
}

char str[1048577];
char words[104857];
int main()
{

	gets(str);
	int len = strlen(str);
	int i = 0;
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}

	while(i < len)
	{
		//分离单词
		int cnt = 0;
		//memset(words, 0, sizeof(words));
		while(!judge(str[i]))
			i++;
		while(judge(str[i]) && i < len)
		{
			words[cnt++] = str[i];
			i++;
		}
		words[cnt] = 0;
		string s = words;
		if(m.find(s) == m.end())//没有找到
			m[s] = 1;
		else//找到了
			m[s]++;
	}
	//sort(m.begin()->second, m.end()->second, cmp);
	map<string, int>::iterator it, res;
	res = m.begin();
	for(it = m.begin(); it != m.end(); it++)
	{
		if(it->second > res->second)
			res = it;
	}
	printf("%s %d\n", res->first.c_str(), res->second);

	return 0;
}