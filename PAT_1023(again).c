//PAT_1023. Have Fun with Numbers (20)
#include <stdio.h>
#include <memory.h>
#include <string.h>
struct bign{
	int d[30];
	int len;
	bign()
	{
		memset(d, 0,sizeof(d));
		len = 0;
	}
};

bign change(char s[])
{
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; i++)
		a.d[i] = s[a.len - 1 - i] - '0';
	return a;
}

bign multi(bign a, int b)
{
	bign c;
	int carry  = 0;
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bool compare(bign a, bign b)
{
	int cnta[10] = {0}, cntb[10] = {0};//千万注意这里的初始化
	if(a.len != b.len)
		return false;
	else
	{
		for(int i = 0; i < a.len; i++)
		{
			cnta[a.d[i]]++;
			cntb[b.d[i]]++;
		}
		for(int i = 0; i <= 9; i++)
		{
			if(cnta[i] != cntb[i])
				return false;
		}
		return true;
	}
}

void Print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
		printf("%d", a.d[i]);
}

int main()
{	
	char s[30];
	gets(s);
	bign a, b;
	a = change(s);
	b = multi(a, 2);
	if(compare(a, b))
		printf("Yes\n");
	else
		printf("No\n");
	Print(b);
}