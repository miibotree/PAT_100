//PAT_1033.To Fill or Not to Fill (23 / 25)
//贪心的策略选择
#include <stdio.h>
#include <algorithm>
using namespace std;

struct station{
	double price;
	double pos;
}s[501];//加油站结构体

bool cmp(station a, station b)
{
	if(a.pos != b.pos)
		return a.pos < b.pos;
}
double Cmax, D, Davg;
int n;
int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for(int i = 0; i < n; i++)
		scanf("%lf%lf", &s[i].price, &s[i].pos);
	sort(s, s + n, cmp);
	if(s[0].pos != 0)//起点没有加油站
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double pos = 0;//当前距离
	int cur = 0;//当前加油站
	double most_pos = 0;//加满油之后可以跑多远
	double sum = 0;//计算总价格
	double gas = 0;//当前油量

	while(pos < D)//当前距离小于终点距离
	{
		most_pos = pos + Cmax * Davg;//加满油之后可以跑到的距离

		int flag = false;//假设当前范围里面没有加油站
		for(int i = cur + 1; i < n; i++)//判断当前加满油的范围里面有没有加油站
		{
			if(s[i].pos <= most_pos)//找到了
			{
				flag = true;
				break;
			}
		}
		if(flag == false)//找不到加油站
		{

			//可以到达终点
			if(most_pos >= D)
			{
				//1.当前油量可以到达终点
				if( (gas * Davg + pos) >= D)//most_pos范围内可以到达终点
				{
					printf("%.2f\n", sum);
					
				}
				//2.当前油量不能到达终点
				else//加恰好到达终点的油
				{
					sum += ( (D - s[cur].pos) / Davg - gas ) * s[cur].price;//加刚好到终点的油
					printf("%.2f\n", sum);
				}
			}
			else//不能到达终点
				printf("The maximum travel distance = %.2f\n", most_pos);
			break;
		}
		else//目标范围里面有加油站
		{
			int cheaper_flag = false;//找比当前加油站价格更加便宜的加油站
			double priceMin = 10000000;
			int cheaper_cur = cur + 1;
			for(int i = cur + 1; i < n; i++)//枚举范围内的加油站
			{
				if(s[i].pos > most_pos)
					break;

				if(s[i].price < priceMin)
				{
					priceMin = s[i].price;
					cheaper_cur = i;
					if(s[i].price < s[cur].price)
					{
						cheaper_flag = true;
						break;
					}
				}
			}
			//1.没有找到更加便宜的,当前加油站 加满油，
			if(cheaper_flag == false)
			{
				//在当前加油站加满油
				sum += s[cur].price * (Cmax - gas);
				gas = Cmax;
				//开到下一个加油站
				gas -= (s[cheaper_cur].pos - s[cur].pos) / Davg;//油量减少
				pos = s[cheaper_cur].pos;
				cur = cheaper_cur;//选择当前范围内油价最低的加油站
			}
			//2.找到了更加便宜的,油量仅仅加到到达那个加油站的油量
			else
			{
				//看看当前油量够不够刚好跑到目的地
				if(gas >= (s[cheaper_cur].pos - s[cur].pos) / Davg)//当前油量够到加油站
				{
					gas -= (s[cheaper_cur].pos - s[cur].pos) / Davg;
				}
				else//当前油量不够到加油站
				{
					sum += s[cur].price * ( (s[cheaper_cur].pos - s[cur].pos) / Davg - gas);
					gas = 0;
				}
				pos = s[cheaper_cur].pos;
				cur = cheaper_cur;
			}
		}
	}
	return 0;
}