//PAT_1089. Insert or Merge (25)
//Miibotree
//2015.2.23
//归并排序step的变化再好好看一下
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[101], b[101], c[101];
int n;

bool InsertSort();
void MergeSort();
void Print(int a[]);
bool cmp(int a[], int b[]);

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			c[i] = a[i];
		}
		for(int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		
		if(!InsertSort())
		{
			printf("Merge Sort\n");
			MergeSort();
		}
	}


	return 0;
}


bool InsertSort()//递增排序
{
	int i, j;
	bool flag = false;
	for(i = 2; i <= n; i++)//依次将a[2]-a[n]插入到前面已排序序列
	{
		if(a[i] < a[i-1])//需要把a[i]插入到前面的某个位置
		{
			a[0] = a[i];
			for(j = i - 1; a[0] < a[j]; j--)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}
		if(flag == true)
		{
			Print(a);
			return true;
		}

		if(cmp(a, b))
		{
			printf("Insertion Sort\n");
			flag = true;
		}
	}
	return false;
}

void Print(int a[])
{
	for(int i = 1; i < n; i++)
		printf("%d ", a[i]);
	printf("%d\n", a[n]);
}

bool cmp(int a[], int b[])
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void MergeSort()
{
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2)
	{
		for(int i = 1; i <= n; i += step)
			sort(c+i, c+min(i+step, n+1));

		if(flag == true)
		{
			Print(c);
			return;
		}
		if(cmp(c, b))
			flag = true;


	}
}