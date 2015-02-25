//PAT_1010. Radix (25)
//使用二分，考虑很多细节，晴神的代码
//Miibotree
//2015.2.25
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256];
LL inf = (1LL << 63) - 1;

void init()//映射
{
	for(char c = '0'; c <= '9'; c++)
		Map[c] = c - '0';
	for(char c = 'a'; c <= 'z'; c++)
		Map[c] = c - 'a' + 10;
}

LL convertNum10(char a[], LL radix, LL t)
{
	LL ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++)
	{
		ans = ans * radix + Map[a[i]];
		if(ans < 0 || ans > t)//溢出或者超过N1的十进制
			return -1;
	}
	return ans;
}

int cmp(char N2[], LL radix, LL t)//N2的十进制与t比较
{
	int len = strlen(N2);
	LL num = convertNum10(N2, radix, t);
	if(num < 0)	return 1;//溢出的情况N2 > t
	if(t > num)	return -1;
	else if(t == num) return 0;
	else return 1;
}

LL BinarySearch(char N2[], LL left, LL right, LL t)
{
	LL mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if(flag == 0)
			return mid;
		else if (flag == -1) 
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int findLargestDigit(char N2[])//二分下限
{
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i++)
	{
		if(Map[N2[i]] > ans)
			ans = Map[N2[i]];
	}
	return ans + 1;
}

char N1[20], N2[20], temp[20];
int tag, radix;
int main()
{
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if(tag == 2)//交换，统一操作
	{
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	LL t = convertNum10(N1, radix, inf);
	LL low = findLargestDigit(N2);
	LL high = max(low, t) + 1;
	LL ans = BinarySearch(N2, low, high, t);
	if (ans == -1)
		printf("Impossible\n");
	else
		printf("%lld\n", ans);
	return 0;
}