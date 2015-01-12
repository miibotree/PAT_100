//PAT_1077 Kuchiguse (20)
//Miibotree
//2015.1.12

#include <stdio.h>
#include <string.h>

int main()
{
	char str[101][257];
	int len[100];
	int n = 0;
	int minlen = 257;
	while (scanf("%d", &n) != EOF)
	{	
		getchar();
		minlen = 256;
		for (int p = 0; p < n; p++)
		{
			gets(str[p]);
			len[p] = strlen(str[p]);
			if (len[p] < minlen)
				minlen = len[p];
		}
		int cnt = 0;
		int j = 0;
		int i = 0;
		for (i = 0; i < minlen; i++)
		{
			char K = str[0][len[0]-1-i];
			for (j = 1; j < n; j++)
			{
				if (str[j][len[j]-1-i] != K)
					break;
			}
			if (j == n)//说明共同字符
				cnt++;
			else
				break;
		}
		if (cnt == 0)
			printf("nai\n");
		else
			printf("%s\n", &str[0][len[0]-cnt]);
	}

	return 0;
}
