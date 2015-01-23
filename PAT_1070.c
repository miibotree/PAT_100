//PAT 1070.Mooncakes
//Miibotree
//2015.1.23
//贪心
//坑爹啊！ amount也必须是实数不能用int！！！

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct _cake{
	float amount;
	float price;
	float ave; 
}cake;

bool cmp(cake a, cake b)
{
	if (a.ave != b.ave)
		return a.ave > b.ave;
}

cake c[1005];

int main()
{
	int n, d;
	while (scanf("%d%d", &n, &d) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%f", &c[i].amount);
		for (int i = 0; i < n; i++)
		{
			scanf("%f", &c[i].price);
			c[i].ave = c[i].price / c[i].amount;
		}
		sort(c, c+n, cmp);

		int cnt = 0;
		float sum = 0;
		while (d)
		{
			if (cnt >= n)
				break;
			if(d >= c[cnt].amount)
			{
				sum += c[cnt].price;
				d -= c[cnt].amount;
				cnt++;
			}
			else
			{
				sum += c[cnt].ave * d;
				d = 0;
			}
		}
		printf("%.2f\n", sum);
	}
	return 0;
}