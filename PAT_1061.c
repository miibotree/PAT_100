//PAT_1061 Dating (20)
//Miibotree
//2015.1.11
//思路： 从str1 和str2中寻找星期1-7(A-G)和 小时0-23(0-9 A-N)
//		  从str3和str4中寻找分钟(在第几个位置就是第几分钟)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void FindWeekMinute(char *str1, char *str2);
void FindSecond(char *str3, char *str4);

int main()
{
	char str1[61], str2[61], str3[61], str4[61];

	while (gets(str1))
	{
		gets(str2);gets(str3);gets(str4);

		FindWeekMinute(str1, str2);
		FindSecond(str3, str4);
	}
	return 0;
}
void FindWeekMinute(char *str1, char *str2)
{
		int len1 = 0, len2 = 0;
		int cnt = 1;
		len1 = strlen(str1);
		len2 = strlen(str2);
		int min = len1<len2?len1:len2;
		for (int i = 0; i < min; i++) 
		{
			if (cnt == 1 && str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')//第一次共同字母
			{
				switch(str1[i])
				{
					case 'A':
						printf("MON ");
						break;
					case 'B':
						printf("TUE ");
						break;
					case 'C':
						printf("WED ");
						break;
					case 'D':
						printf("THU ");
						break;				
					case 'E':
						printf("FRI ");
						break;
					case 'F':
						printf("SAT ");
						break;
					case 'G':
						printf("SUN ");
						break;						
				}
				cnt++;
				continue;
			}											
			if (cnt == 2 && str1[i] == str2[i])//第二次共同字母
			{
				if (str1[i] >= '0' && str1[i] <= '9')
				{
					printf("0%c:", str1[i]);
					break;
				}
				else if (str1[i] >= 'A' && str1[i] <= 'N')
				{
					printf("%d:", str1[i]-'A'+10);
					break;
				}
			}
		}
}

void FindSecond(char *str3, char *str4)
{
	int  len3 = 0, len4 = 0;
	len3 = strlen(str3);
	len4 = strlen(str4);
	int min = len3<len4?len3:len4;
	for (int i = 0; i < min; i++)
	{
		if (str3[i] == str4[i])
		{
			if (isalpha(str3[i]))
			{
				printf("%02d\n", i);
				break;
			}
		}
	}
}