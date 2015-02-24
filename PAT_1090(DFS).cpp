//PAT_1090. Highest Price in Supply Chain (25)
//Miibotree
//2015.2.23
//DFS

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

vector <int> a[100001];
int cnt, max_level;

void DFS(int x, int depth)
{
	if(a[x].size() == 0)//说明深搜到了叶子节点
	{
		if(depth > max_level)
		{
			max_level = depth;
			cnt = 1;
		}
		else if(depth == max_level)
			cnt++;
	}
	for(int i = 0; i < a[x].size(); i++)
		DFS(a[x][i], depth + 1);
}

int main()
{
	int n;
	double p, r;
	int root;
	while(scanf("%d%lf%lf", &n, &p, &r) != EOF)
	{
		r = 1 + r / 100;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if(x != -1)
			{
				a[x].push_back(i);
			}
			else
				root = i;
		}
		cnt = 0; max_level = 0;
		DFS(root, 0);
		printf("%.2lf %d\n", p * pow(r, max_level), cnt);
	}
	return 0;
}