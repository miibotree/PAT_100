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
	if (a < b)
		return true;
	else if(a > b)
		return false;
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
		for(int i = 0; i < n; i++)
			printf("%s", a[i].c_str());
		printf("\n");
	}
	return 0;
}