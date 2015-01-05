#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0, b = 0, sum = 0;
	
	while(scanf("%d %d", &a, &b) != EOF)
	{
		sum = a+b;
		if (abs(sum)< 1000)
			printf("%d\n", sum);
		else if (abs(sum) <= 999999)
			printf("%d,%03d\n", sum /1000, abs(sum) % 1000);
		else
			printf("%d,%03d,%03d\n", sum / 1000000, (abs(sum) %1000000) /1000, abs(sum) % 1000);
	}
	return 0;
}