//PAT_1088. Rational Arithmetic (17 / 20)
//Miibotree
//2015.2.23
#include <stdio.h>
#include <algorithm>

using namespace std;

struct num{
	long long u;
	long long d;
	long long l;
	bool flag;
}a, b;

void Print(num x);
void Regular(num x);
long long gcd(long long a, long long b);
num Add(num a, num b);
num Minus(num a, num b);
num Multi(num a, num b);
num Quoti(num a, num b);


int main()
{
	while(scanf("%lld/%lld %lld/%lld", &a.u, &a.d, &b.u, &b.d) != EOF)
	{
		//Add
		Regular(a);
		printf(" + ");
		Regular(b);
		printf(" = ");
		Regular(Add(a, b));
		printf("\n");

		//Minus
		Regular(a);
		printf(" - ");
		Regular(b);
		printf(" = ");
		Regular(Minus(a, b));
		printf("\n");

		//Multi
		Regular(a);
		printf(" * ");
		Regular(b);
		printf(" = ");
		Regular(Multi(a, b));
		printf("\n");

		//Quoti
		Regular(a);
		printf(" / ");
		Regular(b);
		printf(" = ");
		if(b.u == 0)
			printf("Inf");
		else
			Regular(Quoti(a, b));
		printf("\n");
		
	}
	return 0;
}

void Print(num x)
{
	if(x.l == 0 && x.u == 0)
	{
		printf("0");
		return;
	}
	if(x.flag == 1)
		printf("(-");

	if(x.l != 0)
		printf("%lld", x.l);
	if(x.l == 0 && x.u != 0)
		printf("%lld/%lld", abs(x.u), x.d);
	else if(x.l != 0 && x.u != 0)
		printf(" %lld/%lld", abs(x.u), x.d);

	if(x.flag == 1)
		printf(")");
}

void Regular(num x)//化简
{
	if(x.d < 0)
	{
		x.u = -x.u;
		x.d = -x.d;
	}
	if(x.u < 0)
		x.flag = 1;//负数
	else
		x.flag = 0;//正数
	if(abs(x.u) >= x.d)
	{
		x.l = abs(x.u) / x.d;
		x.u = abs(x.u) % x.d;
	}
	else
		x.l = 0;
	Print(x);
}

long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

num Add(num a, num b)
{
	num tmp;
	tmp.d = a.d * b.d;
	tmp.u = a.u * b.d + b.u * a.d;
	int res = gcd(tmp.d, tmp.u);
	tmp.d /= res;
	tmp.u /= res;
	return tmp;
}

num Minus(num a, num b)
{
	num tmp;
	tmp.d = a.d * b.d;
	tmp.u = a.u * b.d - b.u * a.d;
	int res = gcd(tmp.d, tmp.u);
	tmp.d /= res;
	tmp.u /= res;
	return tmp;
}

num Multi(num a, num b)
{
	num tmp;
	tmp.d = a.d * b.d;
	tmp.u = a.u * b.u;
	int res = gcd(tmp.d, tmp.u);
	tmp.d /= res;
	tmp.u /= res;
	return tmp;
}

num Quoti(num a, num b)
{
	num tmp;
	tmp.d = a.d * b.u;
	tmp.u = a.u * b.d;
	long long res = gcd(tmp.d, tmp.u);
	tmp.d /= res;
	tmp.u /= res;
	return tmp;
}
