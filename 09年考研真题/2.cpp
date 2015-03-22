#include <stdio.h>
#include <string.h>
int hash[4];
char str[101];
int main()
{
	while(gets(str))
	{
		for(int i = 1; i <= 3; i++)
			hash[i] = 0;
		if(str[0] == 'E')
			break;
		int len = strlen(str);
		for(int i = 0; i < len; i++)
		{
			if(str[i] == 'Z')
				hash[1]++;
			else if(str[i] == 'O')
				hash[2]++;
			else
				hash[3]++;
		}
		int cnt = 0;
		while(cnt < len)
		{
			if(hash[1] > 0)
			{
				printf("Z");
				hash[1]--;
				cnt++;
			}
			if(hash[2] > 0)
			{
				printf("O");
				hash[2]--;
				cnt++;
			}
			if(hash[3] > 0)
			{
				printf("J");
				hash[3]--;
				cnt++;
			}
		}
		printf("\n");
	}
	return 0;
}