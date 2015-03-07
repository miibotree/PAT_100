//PAT_1031. Hello World for U (20)
#include <stdio.h>
#include <string.h>

char a[84][84];
int n1, n2, n3;
int main()
{
	char str[84];
	scanf("%s", str);
	int n = strlen(str);
	n1 = -1;
	int k;
	for(n2 = 3; n2 <= n; n2++)
	{
		if((n + 2 - n2) % 2 == 0)
		{
			n1 = n3 = (n + 2 - n2) / 2;
			if(n2 >= n1)
				break;
		}
	}

	int cnt = 0;
	for(int i = 0; i < n1; i++)
		for(int j = 0; j < n2; j++)
			a[i][j] = ' ';
	for(int i = 0; i < n1; i++)
		a[i][0] = str[cnt++];
	for(int i = 1; i < n2; i++)
		a[n1 - 1][i] = str[cnt++];
	for(int i = n1 - 2; i >= 0; i--)
		a[i][n2-1] = str[cnt++];
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < n2; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	return 0;
}