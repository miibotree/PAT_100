//PAT_1042 Shuffling Machine (20)
//Miibotree
//2015.1.10

#include <stdio.h>

int Permutation(int *card, int *order);
int Echo(int *card);

int main()
{
	int n = 0;
	int card[55];
	int order[55];

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= 54; i++)
		{
			scanf("%d", &order[i]);
			card[i] = i;
		}

		for (int i = 0; i < n; i++)//n is the times of the permutation
			Permutation(card, order);
		Echo(card);
	}
	return 0;
}

int Permutation(int *card, int *order)
{
	int b[55];
	for (int i = 1; i <= 54; i++)
		b[order[i]] = card[i];
	for (int i = 1; i <= 54; i++)
		card[i] = b[i];
	return 0;
}

int Echo(int *card)
{
	for (int i = 1; i <= 54; i++)
	{
		if(card[i] == 53)
			printf("J1");
		else if (card[i] == 54)
			printf("J2");
		else
		{
			int s = (card[i]-1) / 13;
			int y = (card[i]-1) % 13;
			switch(s)
			{
				case 0:
					printf("S%d", y+1);
					break;
				case 1:
					printf("H%d", y+1);
					break;
				case 2:
					printf("C%d", y+1);
					break;
				case 3:
					printf("D%d", y+1);
					break;
			} 
		}
		if (i == 54)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}