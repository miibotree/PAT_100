//PAT_1037. Magic Coupon (22/25)
//Miibotree
//2015.1.19
//贪心?

#include <stdio.h>
#include <algorithm>

using namespace std;

int Find(int a[], int n);
void FillC(int a[], int n);
void FillP(int a[], int n);

bool cmp(int a, int b)
{	
	if (a != b)
		return a > b;
}

int c_posi[100005], c_negi[100005];
int p_posi[100005], p_negi[100005];
int c_posi_cnt, c_negi_cnt, p_posi_cnt, p_negi_cnt;

int main()
{
	int nc, np;
	int c[100005], p[100005];
	int sum;

	while (scanf("%d", &nc) != EOF)
	{
		sum = 0;
		for (int i = 0; i < 100005; i++)
		{
			c_posi[i] = 0;c_negi[i] = 0;p_posi[i] = 0; p_negi[i] = 0;
		}

		for (int i = 0; i < nc; i++)
			scanf("%d", &c[i]);
		scanf("%d", &np);
		for (int i = 0; i < np; i++)
			scanf("%d", &p[i]);
		c_posi_cnt = 0; c_negi_cnt = 0;  p_posi_cnt = 0; p_negi_cnt = 0;
		FillC(c, nc);
		FillP(p, np);
		sort(c_posi, c_posi+c_posi_cnt,cmp);
		sort(p_posi, p_posi+p_posi_cnt,cmp);
		sort(c_negi, c_negi+c_negi_cnt);
		sort(p_negi, p_negi+p_negi_cnt);

		int i = 0, j = 0;
		while (i <= c_posi_cnt && j <= p_posi_cnt)
			sum += c_posi[i++] * p_posi[j++];

		i = 0, j = 0;
		while (i <= c_negi_cnt && j <= p_negi_cnt)
			sum += c_negi[i++] * p_negi[j++];

		printf("%d\n", sum);
	}
	return 0;
}

void FillC(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			c_posi[c_posi_cnt++] = a[i];
		else
			c_negi[c_negi_cnt++] = a[i];
	}
}

void FillP(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			p_posi[p_posi_cnt++] = a[i];
		else
			p_negi[p_negi_cnt++] = a[i];
	}
}