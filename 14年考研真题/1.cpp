//14年考研真题
//1077. Kuchiguse (20)
//Miibotree
//2015.3.4
//思路，从后向前遍历字符串
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char str[101][257];

int main()
{
	int n, min_len = 1000, min_string = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		gets(str[i]);
		int len = strlen(str[i]);
		if(len < min_len)
		{
			min_len = len;
			min_string = i;
		}
	}
	int flag = 1;
	int cnt = 0;
	while(cnt < len)//从后开始比较每一位字符
	{
		int len_first = strlen(str[0]);
		char c = str[0][len_first - 1 - cnt];//每一位都与c比较
		for(int i = 1; i < n; i++)
		{
			int len = strlen(str[i]);
			char c_cmp = str[i][len - 1 - cnt];
			if(c_cmp != c)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 0)
			break;
		else
			cnt++;
	}
	if(cnt == 0)
		printf("nai\n");
	else
		printf("%s\n", &str[min_string][min_length - cnt]);
	return 0;
}