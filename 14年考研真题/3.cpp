//14年考研真题
//1079. Total Sales of Supply Chain (24 / 25)
//Miibotree
//2015.3.4
//树的遍历(BFS / DFS都可以)
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
struct Node 
{
	int level;
	int id;
};
vector<Node> tree[100001];
queue<Node> q;
double sum = 0;
double p, r;
map<int, int> amount;

void BFS()
{
	while(q.empty() == false)
	{
		Node top = q.front();
		int Idx = top.id;
		int nowLevel = top.level;
		q.pop();
		for(int i = 0; i < tree[Idx].size(); i++)
		{
			Node childNode = tree[Idx][i];
			childNode.level = nowLevel + 1;
			if(tree[childNode.id].size() == 0)//说明是叶子节点
			{
				sum += p * pow(1 + r, childNode.level) * amount[childNode.id];
			}
			else
				q.push(childNode);
		}
	}
}

int main()
{
	//freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	int n;
	scanf("%d %lf %lf", &n, &p, &r);
	r = r / 100;
	for(int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		if(num == 0)//说明是叶子节点
		{
			int sell_num;
			scanf("%d", &sell_num);
			amount[i] = sell_num;
			continue;
		}

		for(int j = 0; j < num; j++)
		{
			int x;
			scanf("%d", &x);
			Node tmp;
			tmp.id = x;
			tmp.level = 0;
			tree[i].push_back(tmp);
		}
	}
	Node root;
	root.id = 0;
	root.level = 0; 
	q.push(root);
	BFS();
	printf("%.1f\n", sum);
	return 0;
}
