//PAT_1079. Total Sales of Supply Chain (24/25)
//Miibotree
//2015.2.18
//BFS 时间复杂度为o(n)
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

struct Node{
	int flag;
	int amount;
	int level;
	vector<int> c;
}t[100010];

queue<Node> q;

int main()
{
	int n;
	double p, r, sum;
	while(scanf("%d%lf%lf", &n, &p, &r) != EOF)
	{
		r /= 100;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if(x == 0)//零售商
			{
				t[i].flag = 1;
				scanf("%d", &t[i].amount);
			}
			else//非零售商
			{
				for(int j = 0; j < x; j++)
				{
					int y;
					scanf("%d", &y);
					t[i].c.push_back(y);
				}
			}
		}
		while(q.empty() == false)	q.pop();

		q.push(t[0]);//根节点入队列
		t[0].level = 0;
		sum = 0.00;
		while(q.empty() == false)
		{

			Node tmp = q.front();
			q.pop();
			for(int i = 0; i < tmp.c.size(); i++)
			{
				t[tmp.c[i]].level = tmp.level + 1;
				if(t[tmp.c[i]].flag == 1)
					sum += t[tmp.c[i]].amount * p * pow(1 + r, t[tmp.c[i]].level);
				q.push(t[tmp.c[i]]);
			}
			/*
			for(vector<int>::iterator it = t[tmp].c.begin(); it != t[tmp].c.end(); it++)
			{
				t[*it].level = t[tmp].level + 1;
				if(t[*it].flag == 1)//零售商
					sum += t[*it].amount * p * pow(1 + r, t[*it].level);
				q.push(*it);
			}
			*/
		}
		printf("%.1f\n", sum);
	}
	return 0;
}