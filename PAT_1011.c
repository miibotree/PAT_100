//PAT_1011 
//Miibotree
//2015.1.7

#include <stdio.h>

double cmp(double W, double T, double L);

int main()
{
	int i = 0;
	double W = 0, T = 0, L = 0;
	double profit = 1;
	while (scanf("%lf%lf%lf", &W, &T, &L) != EOF)
	{
		profit = 1;
		profit *= cmp(W, T, L);

		scanf("%lf%lf%lf", &W, &T, &L);
		profit *= cmp(W, T, L);

		scanf("%lf%lf%lf", &W, &T, &L);
		profit *= cmp(W, T, L);

		profit = (profit * 0.65 - 1) * 2;
		printf("%.2f\n", profit);

	}

}

double cmp(double W, double T, double L)
{
	double tmp = W;
	if (T > tmp)
		tmp = T;
	if (L > tmp)
		tmp = L;
	if (tmp == W)
		printf("W ");
	else if (tmp == T)
		printf("T ");
	else if (tmp == L)
		printf("L ");
	return tmp;
}