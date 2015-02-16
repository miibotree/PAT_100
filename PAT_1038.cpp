//PAT_1038. Recover the Smallest Number (30)
//Miibotree
//2015.2.16

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
	return a+b < b+a;//这里利用了string的重载符+，判断ab和ba的大小
}

int n;
string a[10001];
char str[9];

int main()
{

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s", str);
			a[i] = str;
		}
		sort(a, a+n, cmp);
		int flag = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < a[i].size(); j++)
			{
				if(a[i][j] == '0' && flag == 0)
					;
				else
				{
					printf("%c", a[i][j]);
					flag = 1;
				}
			}
		}
		if (flag == 0)
			printf("0");
		printf("\n");
	}
	return 0;
}