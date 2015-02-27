//PAT_1079. Total Sales of Supply Chain (25)
//Miibotree
//2015.2.27
//DFS 时间复杂度为o(n)
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct  node
{
	double data;
	vector<int> child;
}Node[maxn];
int n;
double p, r, ans = 0;

void DFS(int index, int depth)
{
	if(Node[index].child.size() == 0)//说明是零售商
	{
		ans += Node[index].data * pow(1 + r, depth);
		return;
	}
	for(int i = 0; i < Node[index].child.size(); i++)
		DFS(Node[index].child[i], depth + 1);
}

int main()
{
	int k, child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if(k == 0)
			scanf("%lf", &Node[i].data);
		else
		{
			for(int j = 0; j < k; j++)
			{
				scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f\n", p * ans);
	return 0;
}