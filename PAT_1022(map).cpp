//PAT_1022. Digital Library (30)
//Miibotree
//2015.3.4
//map<string, set<int> >的使用方法
/*关键词分离的代码
	while(cin>>key){
		map[key].insert(id);
		char c = getchar();
		if(c == '\n')
		break;
	}
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
map<string, set<int> >mptitle, mpauthor, mpkeywords, mppublisher, mpyear;

void query(map<string, set<int> > &mp, string &str)
{
	if(mp.find(str) == mp.end())
		printf("Not Found\n");
	else
	{
		set<int>::iterator it;
		for(it = mp[str].begin(); it != mp[str].end(); it++)
		{
			printf("%07d\n", *it);
		}
	}
}

int main()
{
	int n;
	int id;
	string title, author, key, publisher, year;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{

		scanf("%d", &id);
		getchar();
		getline(cin, title);
		mptitle[title].insert(id);
		getline(cin, author);
		mpauthor[author].insert(id);
		while(cin>>key)
		{
			mpkeywords[key].insert(id);
			char c = getchar();
			if(c == '\n')	break;
		}
		getline(cin, publisher);
		mppublisher[publisher].insert(id);
		getline(cin, year);
		mpyear[year].insert(id);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int idx;
		string str;
		scanf("%d: ", &idx);
		getline(cin, str);
		printf("%d: %s\n", idx, str.c_str());
		if(idx == 1)	query(mptitle, str);
		else if(idx == 2)	query(mpauthor, str);
		else if(idx == 3)	query(mpkeywords, str);
		else if(idx == 4)	query(mppublisher, str);
		else if(idx == 5)	query(mpyear, str);
	}
	return 0;
}
