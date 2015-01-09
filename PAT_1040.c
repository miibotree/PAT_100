//PAT_1040
//Miibotree
//2015.1.9
//回文数可能同时既是无对称点又是有对称点，故应该取两者大的值

#include <stdio.h>
#include <string.h>

int main(){
	char str[10001];
	int len = 0;
	int tmp = 0;
	int max = 0;
	int offset = 0;
	while (gets(str))
	{
		max = 1;
		len = strlen(str);
		for (int i = 1; i < len; i++)
		{
			if(str[i] == str[i+1])//无对称点的情况
			{
				tmp = 2;
				offset = 1;
				while( (i-offset>=0) && (i+offset+1<len) )
				{
					if (str[i-offset] == str[i+offset+1])
						tmp +=2;
					else
						break;
					offset++;
				}
			}
			if (tmp > max)
			max = tmp;

			//有对称点的情况
			tmp = 1;
			offset = 1;
			while(i - offset >= 0 && i + offset < len)
			{
				if (str[i-offset] == str[i+offset])
					tmp +=2;
				else
					break;
				offset++;
			}
			if (tmp > max)
				max = tmp;

		}
		printf("%d\n", max);
	}
	return 0;
}