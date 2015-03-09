#include <stdio.h>
#include <algorithm>
using namespace std;

int a[101], b[101], tmp[101];
int n;

bool compare(int a[], int b[])
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void Print(int a[])
{
	for(int i = 0; i < n; i++)
	{
		if(i != 0)
			printf(" ");
		printf("%d", a[i]);
	}
}

bool InsertSort()
{
	bool flag = false;
	for(int i = 1; i < n; i++)
	{
		int temp = a[i], j = i;
		while(j >= 1 &&	 temp < a[j-1])
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
		if(flag == true)
		{
			printf("Insertion Sort\n");
			Print(a);
			return true;
		}
		if(compare(a, b))
			flag = true;
	}
	return false;
}

void MergeSort()
{
	printf("Merge Sort\n");
	bool flag = false;
	for(int step = 2; step <= n; step*=2)//注意这里
	{
		for(int i = 0; i < n; i += step)
			sort(tmp+i, tmp+min(i+step, n));
		if(flag == true)
		{
			Print(tmp);
			return ;
		}
		if(compare(b, tmp))
			flag = true;
	}
}

int main()
{

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		tmp[i] = a[i];
	}
	for(int i  = 0; i < n; i++)
		scanf("%d", &b[i]);
	if(!InsertSort())
		MergeSort();
	return 0;
}