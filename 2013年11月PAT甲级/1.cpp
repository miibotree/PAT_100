#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;
bool cmp(int a, int b)
{
	if(a != b)
		return a > b;
}

int n;
int s[5];
int MAX, MIN;
int cnt = 0;

void GetPart(int n, int a[])
{
	cnt = 0;
	do{
		a[cnt++] = n % 10;
		n /= 10;
	}while(n != 0);
}	

int GetNumber()
{
	int sum = 0;
	for(int i = 0; i < 4; i++)
		sum = sum * 10 + s[i];
	return sum;
}

int main()
{	

	scanf("%d", &n);
	while(1)
	{
		memset(s, 0, 5);
		GetPart(n, s);
		sort(s, s + 4);
		MIN = GetNumber();
		sort(s, s + 4, cmp);
		MAX = GetNumber();
		printf("%04d - %04d = %04d\n", MAX, MIN, MAX - MIN);
		n = MAX - MIN;
		if(n == 6174 || n == 0)
			break;
	}
	return 0;
}
