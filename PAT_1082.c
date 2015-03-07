//PAT_1082 Read Number in Chinese (25)
//Miibotree
//2015.3.6
#include <stdio.h>
#include <string.h>

char num[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main()
{
	char str[11];
	gets(str);
	int len = strlen(str);
	int left = 0;
	int right = len - 1;
	if(str[left] == '-')
	{
		printf("Fu");
		left++;
	}
	while(left + 4 <= right)
		right -= 4;
	while(left < len)
	{
		bool flag = false;//处理前导的零
		bool isPrint = false;//如果该节都没有输出 则最后的位也不用输出
		while(left <= right)
		{
			if(left > 0 && str[left] == '0')//当前位为0
			{
				flag = true;
			}
			else//当前位为数字
			{
				if(flag == true)//需要输出0
				{
					printf(" ling");
					flag = false;
				}
				if(left > 0)
					printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if(left != right)//除了个位外，都要输出十百千
					printf("%s", wei[right - left - 1]);
			}
			left++;
		}
		if(isPrint == true && right != len - 1)
			printf("%s", wei[(len - 1 - right) / 4 + 2] );
		right += 4;
	}
	return 0;
}