//PAT_1008 Elevator
//Miibotree
//2015.1.5

#include <stdio.h>
int main()
{
	int n = 0, i = 0, m = 0;
	int current = 0;//表示上一次停留的层数
	int sum = 0;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		sum = 0;
		current = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%d", &m);
			if (m > current)//向上走
				sum += 5 + (m-current) * 6;
			else if (m < current)//向下走
				sum += 5 + (current - m) * 4; 
			else
				sum += 5;
			current = m;
		}
		printf("%d\n", sum);

	}
	return 0;
}