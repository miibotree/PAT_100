#include <stdio.h>
int n, b, a[1000];
int cnt;

bool judge()
{
	for(int i = 0; i < cnt / 2; i++)
	{
		if(a[i] != a[cnt - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &b);
	cnt = 0;
	do{
		a[cnt++] = n % b;
		n /= b;
	}while(n != 0)
	if(judge())
		printf("Yes\n");
	else
		printf("No\n");
	for(int i = cnt - 1; i >= 0; i--)
	{
		if(i != cnt - 1)
			printf(" ");
		printf("%d", a[i]);
	}

	return 0;
}