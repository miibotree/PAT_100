//PAT_1010. Radix (22/25)
//Miibotree
//2015.2.4
//思路：进制转换（都转到10进制来比较）
#include <string.h>
#include <stdio.h>

long long Trans(char *str, int m)//任意m进制数转换成十进制数的函数
{
	long long tmp = 0, c = 1;
	int lenth = strlen(str);//c表示权重
	for(int i = lenth - 1; i >= 0; i--)
	{
		int x;
		if(str[i] >= '0' && str[i] <= '9')
			x = str[i] - '0';
		else
			x = str[i] - 'a' + 10;
		tmp += x * c;
		c *= m;
	}
	return tmp;
}

int main()
{	
	char n1[11], n2[11];
	long long radix;
	int tag;
	while(scanf("%s %s %d %lld", n1, n2, &tag, &radix) != EOF)
	{
		if(n1 == "1" && n2 == "1")  
		{  
			printf("2\n");  
			continue;  
		}  
		if(!strcmp(n1,n2))  
		{  
			printf("%d\n", radix);  
			continue;  
		}  

		if(tag == 1)//说明第一个数确定了进制
		{
			bool flag = false;
			long long x1, x2;
			long long i;
			x1 = Trans(n1, radix);
			for(i = 2; ; i++)//另外一个数从2进制到36进制依次尝试
			{
				x2 = Trans(n2, i);
				if (x1 == x2)
				{
					flag = true;
					break;
				}
				else if(x2 > x1)
					break;
			}
			if(flag)
				printf("%d\n", i);
			else
				printf("Impossible\n");
		}
		else if(tag == 2)
		{
			bool flag = false;
			long long x1, x2;
			long long i;
			x1 = Trans(n2, radix);
			for(i = 2; ; i++)//另外一个数从2进制到36进制依次尝试
			{
				x2 = Trans(n1, i);
				if (x1 == x2)
				{
					flag = true;
					break;
				}
				else if(x2 > x1)
					break;
			}
			if(flag)
				printf("%d\n", i);
			else
				printf("Impossible\n");
		}
	}

	return 0;
}