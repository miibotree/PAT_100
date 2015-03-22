//PAT_1092. To Buy or Not to Buy (20)
//Miibotree
//2015.3.22
#include <stdio.h>
#include <string.h>
#define MAX 1000
using namespace std;

char s1[MAX+1], s2[MAX+1];
int hash[256];
int main()
{
	gets(s1);
	gets(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for(int i = 0; i < len1; i++)
		hash[s1[i]]++;
	int flag = true;
	for(int i = 0; i < len2; i++)
	{
		hash[s2[i]]--;
		if(hash[s2[i]] < 0)
			flag = false;
	}
	int cnt = 0;
	if(flag == true)
	{
		for(int i = 0; i < 256; i++)
		{
			if(hash[i] > 0)
				cnt += hash[i];
		}
		printf("Yes %d\n", cnt);
	}
	else
	{
		for(int i = 0; i < 256; i++)
		{
			if(hash[i] < 0)
				cnt -= hash[i];
		}
		printf("No %d\n", cnt);
	}
	return 0;
}