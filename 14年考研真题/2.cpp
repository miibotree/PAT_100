//14年考研真题
//1078. Hashing (25)
//Miibotree
//2015.3.4
//Hash
#include <stdio.h>
#include <cmath>
using namespace std;

#define N 10000
bool hashTable[N+1] = {false};

bool Judge(int x)
{
	if (x <= 1)
		return false;
	int sqr = (int)sqrt(1.0 * x);
	for(int i = 2; i <= sqr; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
} 

int main()
{
	int n, msize;
	int key;
	int res;
	scanf("%d%d", &msize, &n);
	while(Judge(msize) == false)
		msize++;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &key);
		res = key % msize;
		if(hashTable[res] == false)
		{
			if(i == n)
				printf("%d", res);
			else
				printf("%d ", res);
			hashTable[res] = true;
		}
		else//Quadratic probing
		{
			int step;
			for(step = 1; step < msize; step++)
			{
				res = (key + step * step) % msize;
				if(hashTable[res] == false)
				{
					if(i == n)
						printf("%d", res);
					else
						printf("%d ", res);
					hashTable[res] = true;
					break;
				}
			}
			
			if(step >= msize)
			{
				if(i == n)
					printf("-");
				else
					printf("- ");
			}
		}
	}
	return 0;
}