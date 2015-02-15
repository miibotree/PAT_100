//PAT_1022. Digital Library (30)
//Miibotree
//2015.2.15
//搜索，结构体，排序,字符串处理
//这道题目有个坑：ID是七位数字，可能前面有0，这里使用了输出时%07d，
//也可以用字符串保存不会出错，比较的时候方法一样，按照字典序小排列就好了
//此份代码可以改进之处：1.存储keywords不用二维数组而用vecter
//2.单词分离代码可以改进
/*单词分离技巧1
char *point=book[i].keyWord;//关键词分离
            while(*point){
    sscanf(point,"%s",str);
    point+=strlen(str)+1;
    string stemp(str);
    mm_keyWord[stemp].push_back(i);
}

单词分离技巧2
#include<iostream>  
#include<sstream>  
using namespace std;  
int main()  
{  
    string str, line;  
    while(getline(cin, line))  
    {  
        istringstream stream(line);  
        while(stream>>str)  
            cout<<str.c_str()<<endl;  
    }     
    return 0;  
}  
*/

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Info{
	int id;
	char title[81];
	char author[81];
	char keywords[5][11];
	char publisher[81];
	char year[5];
}info[10001];

bool cmp(Info a, Info b)
{
	if (a.id != b.id)
		return a.id < b.id;
}

void Search(char *str);
int n;

int main()
{
	int m;
	while(scanf("%d", &n) != EOF)
	{
		char tmp[100];
		char word[11];
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &info[i].id);
			getchar();
			gets(info[i].title);
			gets(info[i].author);
			gets(tmp);
			gets(info[i].publisher);
			gets(info[i].year);

			int cnt = 0;
			for(int j = 0; tmp[j] != 0; )
			{
				int k = 0;
				while(tmp[j] != ' ' && tmp[j] != 0)
				{
					word[k++] = tmp[j++];
				}
				word[k] = 0;
				strcpy(info[i].keywords[cnt++], word);
				if(tmp[j] == 0)
					break;
				j++;
			}
		}
		sort(info, info+n, cmp);
		scanf("%d", &m);
		getchar();
		for(int i = 0; i < m; i++)
		{
			char str[200];
			gets(str);
			printf("%s\n", str);
			Search(str);
		}
	}
}

void Search(char *str)
{
	int flag = false;
	int len = strlen(str);
	char c = str[0];
	char query[81];
	strcpy(query, &str[3]);
	switch(c)
	{
		case '1':
			for(int i = 0; i < n; i++)
			{
				if(!strcmp(info[i].title, query))
				{
					printf("%07d\n", info[i].id);
					flag = true;
				}
			}
			if (flag == false)
				printf("Not Found\n");
			break;

		case '2':
			for(int i = 0; i < n; i++)
			{
				if(!strcmp(info[i].author, query))
				{
					printf("%07d\n", info[i].id);
					flag = true;
				}
			}
			if (flag == false)
				printf("Not Found\n");
			break;

		case '3':
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < 5; j++)
				if(!strcmp(info[i].keywords[j], query))
				{
					printf("%07d\n", info[i].id);
					flag = true;
					break;
				}
			}
			if (flag == false)
				printf("Not Found\n");
			break;

		case '4':
			for(int i = 0; i < n; i++)
			{
				if(!strcmp(info[i].publisher, query))
				{
					printf("%07d\n", info[i].id);
					flag = true;
				}
			}
			if (flag == false)
				printf("Not Found\n");
			break;

		case '5':
			for(int i = 0; i < n; i++)
			{
				if(!strcmp(info[i].year, query))
				{
					printf("%07d\n", info[i].id);
					flag = true;
				}
			}
			if (flag == false)
				printf("Not Found\n");
			break;
	}
}