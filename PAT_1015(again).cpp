//PAT_1015. Reversible Primes (20)
#include <stdio.h>
#include <math.h>

int z[111];
int cnt = 0;
bool judge(int x)
{
	if(x <= 1)
		return false;
	int sqr = sqrt(1.0 * x); 
	for(int i = 2; i <= sqr; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int GetNum(int d)
{
	int res = 0;
	for(int i = 0; i < cnt; i++)
		res = res * d + z[i];
	return res;
}

void Trans(int x, int d)
{
	do{
		z[cnt++] = x % d;
		x = x / d;
	}while(x != 0);
}

int main()
{
	int n, d;
	while(scanf("%d", &n) != EOF)
	{
		if (n < 0)
			break;

		scanf("%d", &d);
		if(n == 1)
		{
			printf("No\n");
			continue;
		}
		bool flag = judge(n);
		if(flag == false)
		{
			printf("No\n");
			continue;
		}
		cnt = 0;
		Trans(n, d);
		int r_n = GetNum(d);
		flag = judge(r_n);
		if(flag == true)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}