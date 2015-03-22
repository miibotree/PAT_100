#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<string, string>m1, m2;
int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n;
	char str[120];
	while(gets(str))
	{
		if( !(strcmp(str, "@END@") ))
			break;
		int len = strlen(str);
		int i = 1;
		int cnt = 0;
		char name[30];
		char sen[100];

		while(str[i] != ']')
			name[cnt++] = str[i++];
		name[cnt] = 0;
		cnt = 0;
		i = i + 2;
		while(i < len)
			sen[cnt++] = str[i++];
		sen[cnt] = 0;
		string s1 = name;
		string s2 = sen;
		m1[s1] = s2;
		m2[s2] = s1;
	}
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		string cmd;
		getline(cin, cmd);
		if(cmd[0] == '[')
		{
			cmd.erase(cmd.begin());
			cmd.erase(cmd.end() - 1);
			if(m1.find(cmd) != m1.end())//找到了
				printf("%s\n", m1[cmd].c_str());
			else
				printf("what?\n");
		}
		else
		{
			if(m2.find(cmd) != m2.end())//找到了
				printf("%s\n", m2[cmd].c_str());
			else
				printf("what?\n");
		}
	}
	return 0;
}