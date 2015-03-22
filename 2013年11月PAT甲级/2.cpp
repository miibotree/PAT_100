//PAT_1070. Mooncake (25)
//Greedy
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Cake
{
	double price;
	double amount;
	double avg;
}cake[1001];


bool cmp(Cake a, Cake b){
	if(a.avg != b.avg)
		return a.avg > b.avg;
}


int main()
{
	int n;
	double D;
	scanf("%d %lf", &n, &D);
	for(int i = 0; i < n; i++)
		scanf("%lf", &cake[i].amount);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &cake[i].price);
		cake[i].avg = cake[i].price / cake[i].amount;
	}
	sort(cake, cake + n, cmp);
	double res = 0;
	double remain = D;//还需要多少月饼
	for(int i = 0; i < n; i++)
	{
		if(cake[i].amount <= remain)//可以全部给
		{
			remain -= cake[i].amount;
			res += cake[i].price;
		}
		else//只能给部分了
		{
			res += remain  * cake[i].avg;
			remain = 0;
			break;
		}
	}
	printf("%.2f\n", res);
	return 0;
}