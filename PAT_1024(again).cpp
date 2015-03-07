#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
using namespace std;
struct bign{
	int d[100];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
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

bign trans(bign a)
{
	bign b;
	b.len = a.len;
	for(int i = 0; i < a.len; i++)
		b.d[i] = a.d[a.len - 1 - i];
	return b;
}
bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0)
		c.d[c.len++] = carry;
	return c;
}

bool isP(bign a)
{
	for(int i = 0; i < a.len / 2; i++)
	{
		if(a.d[i] != a.d[a.len - 1 - i])
			return false;
	}
	return true;
}


void Print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
		printf("%d", a.d[i]);
	printf("\n");
}

int main()
{
	char n[100];
	int k;
	scanf("%s %d", n, &k);
	bign a, b, c;
	a = change(n);
	int cnt = 0;
	while(cnt < k && isP(a) == false)//代码精简
	{
		b = trans(a);
		a = add(a, b);
		cnt++;
	}
	Print(a);
	printf("%d\n", cnt);
	return 0;
}