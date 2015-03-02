//PAT_1082. Read Number in Chinese (25)
//Miibotree
//2015.2.28
#include <cstdio>
#include <cstring>
char num[10][5] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main()
{
	char str[15];
	gets(str);
	int len = strlen(str);
	int left = 0, right = len - 1;//当前处理的字符串的左边界和右边界
	if(str[0] == '-')
	{
		printf("Fu");
		left++; 
	}
	while(left + 4 <= right)//每四位四位处理
		right -= 4;

	while(left < len)
	{
		bool flag = false;
		bool isPrint = false;
		while(left <= right)//当前四位的处理
		{
			if(left > 0 && str[left] == '0')
				flag = true;//前导0处理
			else
			{
				if(flag == true)
				{
					printf(" ling");
					flag = false;
				}
				if(left > 0)
					printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if(left != right)
					printf(" %s", wei[right - left - 1]);
			}
			left++;
		}
		if(isPrint == true && right != len - 1)
			printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		right += 4;
	}
	return 0;
}