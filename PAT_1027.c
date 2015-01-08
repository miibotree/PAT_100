//PAT_1027
//Miibotree
//2015.1.8
#include <stdio.h>

int Trans(int x);

int main()
{
	int R = 0, G = 0, B = 0;
	while(scanf("%d %d %d", &R, &G, &B) != EOF)
	{
		printf("#");
		Trans(R);
		Trans(G);
		Trans(B);
		printf("\n");
	}

	return 0;
}

int Trans(int x)
{
	int m0 = x % 13;
	int m1 = x / 13;
	switch(m1)
	{
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;
		case 12:
			printf("C");
			break;
		default:
			printf("%d", m1);
			break;
	}

	switch(m0)
	{
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;
		case 12:
			printf("C");
			break;
		default:
			printf("%d", m0);
			break;
	}
}