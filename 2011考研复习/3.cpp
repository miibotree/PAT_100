//并查集+DFS
#include <stdio.h>
#include <set>
#include <vector>
#define N 10001
using namespace std;

int tree[N];
int n;
int cnt;
set<int> v[N];
set<int> ans, tmp;

int find(int x)
{
	if(tree[x] == -1)
		return x;
	else
	{
		int tmp = x;
		x = find(tree[x]);
		tree[tmp] = x;
		return x;
	}
}
int maxH = 0;
void DFS(int x, int Height, int pre)
{
	if(Height > maxH)
	{
		tmp.clear();
		tmp.insert(x);
		maxH = Height;
	}
	else if(Height == maxH)
		tmp.insert(x);
	set<int>::iterator it;
	for(it = v[x].begin(); it != v[x].end(); it++)
	{
		if(*it == pre)
			continue;
		DFS(*it, Height + 1, x); 
	}
}

int main()
{
	cnt = 0;
	for(int i = 1; i < N; i++)
		tree[i] = -1;

	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].insert(b);
		v[b].insert(a);

		a = find(a);
		b = find(b);
		if(a != b)
		{
			tree[a] = b;
			cnt++;
		}
	}
	if(cnt != n-1)//说明图没有联通
		printf("Error: %d components\n", n - cnt);
	else//联通了
	{
		DFS(1, 1, -1);//结果存在tmp中
		ans = tmp;
		set<int>::iterator it = ans.begin();
		DFS(*it, 1, -1);
		for(it = tmp.begin(); it != tmp.end(); it++)
			ans.insert(*it);
		for(it = ans.begin(); it != ans.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}