//1084 Broken Keyboard (20)
//Miibotree
//2015.1.12

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[81], s2[81];
	char b[81];
	int  a[256];
	while (gets(s1))
	{
		for (int i = 0; i < 256; i++)
			a[i] = 0;
		gets(s2);

		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for (int i = 0; i < len1; i++)			//小写转化为大写
		{
			if (s1[i] >= 'a' && s1[i] <= 'z')
				s1[i] = s1[i] - 'a' + 'A';
		}
		for (int i = 0; i < len2; i++)
		{
			if (s2[i] >= 'a' && s2[i] <= 'z')
				s2[i] = s2[i] - 'a' + 'A';
		}

		int x = 0, y = 0, z = 0;
		while (x < len1)
		{
			if (s1[x] == s2[y])
			{
				x++;y++;
			}
			else//不相等
			{
				b[z] = s1[x];
				z++;
				x++;
			}
		}

		for (int i = 0; i < z; i++)
		{
			if (a[b[i]] == 0)//第一次出现
			{
				printf("%c", b[i]);
				a[b[i]] = 1;
			}
		}
		printf("\n");
	}

	return 0;
}