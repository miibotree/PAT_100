//PAT_1088. Rational Arithmetic (20)
//Miibotree
//2015.3.2
//学习分数的表示方法和四则运算法则
#include <stdio.h>
#include <algorithm>

struct Fraction{
	long long up;
	long long down;
}a, b;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

//1.如果分母为负，则分子和分母各取相反数
//2.如果分子为零，另分母为1，表示整数
//3.如果分子分母存在约数，约去最大公约数
Fraction Reduction(Fraction result)
{
	if(result.down < 0)
	{
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0)
		result.down = 1;
	else
	{
		int d= gcd(abs(result.up), result.down);
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction Add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up * f2.down + f1.down * f2.up;
	return Reduction(result);
}

Fraction Minus(Fraction f1, Fraction f2)
{
	Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up * f2.down - f1.down * f2.up;
	return Reduction(result);
}


Fraction Multi(Fraction f1, Fraction f2)
{
	Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up * f2.up;
	return Reduction(result);
}


Fraction Divide(Fraction f1, Fraction f2)
{
	Fraction result;
	result.down = f1.down * f2.up;
	result.up = f1.up * f2.down;
	return Reduction(result);
}


void Print(Fraction r)
{
	r = Reduction(r);
	if(r.up < 0)
		printf("(-");
	if(r.down == 1)//整数
		printf("%lld", abs(r.up));
	else if(abs(r.up) > r.down)//假分数
		printf("%lld %lld/%lld", abs(r.up) / r.down, abs(r.up) % r.down, r.down);
	else
		printf("%lld/%lld", abs(r.up), r.down);
	if(r.up < 0)
		printf(")");
}


int main()
{
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//Add
	Print(a);
	printf(" + ");
	Print(b);
	printf(" = ");
	Print(Add(a, b));
	printf("\n");

	//Minus
	Print(a);
	printf(" - ");
	Print(b);
	printf(" = ");
	Print(Minus(a, b));
	printf("\n");

	//Muitl
	Print(a);
	printf(" * ");
	Print(b);
	printf(" = ");
	Print(Multi(a, b));
	printf("\n");

	//Divide
	Print(a);
	printf(" / ");
	Print(b);
	printf(" = ");
	if(b.up == 0)
		printf("Inf");
	else
		Print(Divide(a, b));
	printf("\n");

	return 0;
}