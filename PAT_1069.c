//PAT_1069 The Black Hole of Numbers (20)
//Miibotree 
//2015.1.11

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

void Sort(int *n, int *rn);
int  Judge(int n, int rn, int diff);
int AllSame(int n);

int main()
{
	int n = 0, rn = 0, diff = 0;
	while (scanf("%d", &n) != EOF)
	{
		//判断是否各位相等
		if (AllSame(n))
		{
			printf("%d - %d = 0000\n", n, n);
			continue;
		}		
		diff = 0;
		while(1)
		{
			Sort(&n, &rn);
			if (Judge(n, rn, diff) == true)
				break; 
			else
			{
				if (n > rn)
					printf("%04d - %04d = %04d\n", n, rn, abs(n - rn));
				else
					printf("%04d - %04d = %04d\n", rn, n, abs(n - rn));
				n = abs(n - rn);
				diff = n;
			}
		}
	}
	return 0;
}
void Sort(int *n, int *rn)
{
	int a[4];
	int tmp1 = 0, tmp2 = 0;
	a[0] = *n / 1000;
	a[1] = (*n % 1000) / 100;
	a[2] =  (*n % 100) / 10;
	a[3] = *n % 10;
	sort(a, a+4);
	tmp1 = a[0] * 1 + a[1] * 10 + a[2] * 100 + a[3] * 1000;
	tmp2 = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] * 1;
	if (tmp1 > tmp2)
	{
		*n = tmp1;
		*rn = tmp2;
	}
	else
	{
		*n = tmp2;
		*rn = tmp1;
	}
}

int  Judge(int n, int rn, int diff)
{
	if (abs(n - rn) == diff)
		return true;
	else
		return false;
}

int AllSame(int n)
{
	int a = n / 1000;
	int b = (n % 1000) / 100;
	int c =  (n % 100) / 10;
	int d = n % 10;
	if ( a == b && b == c && c == d)
		return true;
	else
		return false;
}