//PAT_1049. Counting Ones (30)
//Miibotree
//2015.2.18
#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int sum = 0;
		int factor = 1;
		int left, cur, right;
		while (n / factor != 0)
		{	
			left = n / (factor * 10);
			right = n %  factor;
			cur = n / factor % 10;
			switch(cur)
			{
				case 0:
					sum += left * factor;
					break;
				case 1:
					sum += left * factor + right + 1;
					break;
				default:
					sum += (left + 1) * factor;
					break;
			}
			factor *= 10;
		}
		printf("%d\n", sum);
	}
	return 0;
}