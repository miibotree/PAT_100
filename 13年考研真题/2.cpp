//PAT_1055. The World's Richest (25)
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	char name[9];
	int age;
	int worth;
}node[100001];

bool cmp(Node a, Node b)
{
	if(a.worth != b.worth)
		return a.worth > b.worth;
	else if(a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name, b.name) < 0;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%s %d %d", node[i].name, &node[i].age, &node[i].worth);
	sort(node, node + n, cmp);
	for(int i = 1; i <= k; i++)
	{
		printf("Case #%d:\n", i);
		int num, L, R, cnt;
		cnt = 0;
		scanf("%d %d %d", &num, &L, &R);
		for(int j = 0; j < n; j++)
		{
			if(node[j].age >= L && node[j].age <= R)
			{
				printf("%s %d %d\n", node[j].name, node[j].age, node[j].worth);
				cnt++;
			}
			if(cnt == num)
				break;
		}
		if(cnt == 0)
			printf("None\n");
	}
	return 0;
}