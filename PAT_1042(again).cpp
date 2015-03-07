//PAT_1042. Shuffling Machine (20)
#include <stdio.h>
int main()
{
	int t, p[55], a[55], b[55];
	scanf("%d", &t);
	for(int i = 1; i <= 54; i++)
	{
		scanf("%d", &p[i]);
		a[i] = i - 1;
	}
	while(t--)
	{
		for(int i = 1; i <= 54; i++)
		{
			b[p[i]] = a[i];
		}	
		for(int i = 1; i <= 54; i++)
			a[i] = b[i];
	}
	for(int i = 1; i <= 54; i++)
	{
		if(i != 1)
			printf(" ");
		int color = a[i] / 13;
		if(color == 0)
			printf("S%d ", a[i] % 13 + 1);
		else if(color == 1)
			printf("H%d ", a[i] % 13 + 1);
		else if(color == 2)
			printf("C%d ", a[i] % 13 + 1);
		else if(color == 3)
			printf("D%d ", a[i] % 13 + 1);
		else
			printf("J%d\n", a[i] % 13 + 1);
	}
	return 0;
}