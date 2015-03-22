#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
map<string, set<string> >mpBook, mpName, mpKey, mpPublisher, mpYear;
int n, m;

void query(map<string, set<string> > &mp, string &s)
{
	if(mp[string].size() == 0)
		printf("Not Found\n");
	else
	{
		set<string>::iterator it;

		for(int it = mp[string].begin(); it != mp[string].end(); it++)
			puts(*it);
	}
}

int main()
{
	string id, book, name, key, publisher, year;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		gets(id);
		gets(book);
		mpBook[book].insert(id);
		gets(name);
		mpName[name].insert(id);
		while(cin>>key)
		{
			mpKey[key].insert(id);
			char c = getchar();
			if(c == '\n')
				break;
		}
		gets(publisher);
		mpPublisher[publisher].insert(id);
		gets(year);
		mpYear[year].insert(id);
	}
	scanf("%d", &m);
	getchar();
	while(m--)
	{
		string cmd;
		int idx = cmd[0];
		gets(cmd);
		puts(cmd);
		cmd.erase(cmd.begin(), cmd.begin() + 3);
		if(idx == '1')
			query(mpBook, cmd);
		else if(idx == '2')
			query(mpName, cmd);
		else if(idx == '3')
			query(mpKey, cmd);
		else if(idx == '4')
			query(mpPublisher, cmd);
		else
			query(mpYear, cmd);
	}
	return 0;
}