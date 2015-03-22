//PAT_1056. Mice and Rice (25)
#include <stdio.h>
#include <queue>
using namespace std;

struct Node{
	int w;
	int r;
}node[1001];
queue<int>q, tmp_q, next_q;//q是该轮队列，tmp_q是每组的队列，next_q存放获胜的下一组队列

int FindMax(queue<int> fq)//找到每组中最大的老鼠的序号
{
	int max_num = fq.front();
	int max = node[max_num].w;
	fq.pop();
	while(fq.empty() == false)
	{
		int cmp = fq.front();
		fq.pop();
		if(node[cmp].w > max)
		{
			max = node[cmp].w;
			max_num = cmp;
		}
	}
	return max_num;
}

int main()
{
	int np, ng, u;
	scanf("%d%d", &np, &ng);
	u = np;
	for(int i = 0; i < np; i++)
		scanf("%d", &node[i].w);
	for(int i = 0; i < np; i++)
	{
		int order;
		scanf("%d", &order);
		q.push(order);//只是把序号压进去
	}
	while(1)//每一轮
	{
		if(q.size() == 1)//只剩下一只老鼠跳出循环
		{
			node[q.front()].r = 1;
			break;
		}
		int rank;//排名的计算
		if(np % ng == 0)
			rank = np / ng + 1;
		else
			rank = np / ng + 2;
		int group_cnt = 0;//每一轮每一个组的老鼠数目的计数器
		while(q.empty() == false)
		{
			//取一组的老鼠
			int x = q.front();
			q.pop();
			tmp_q.push(x);
			group_cnt++;
			if(group_cnt == ng)//一组到了
			{
				int max = FindMax(tmp_q);//找到该组的最大编号
				while(tmp_q.empty() == false)//处理排名
				{
					int t = tmp_q.front();//取出该组的一只老鼠序号
					tmp_q.pop();
					if(t != max)//淘汰的老鼠直接计算排名
						node[t].r = rank;
					else
						next_q.push(t);//晋级的老鼠
				}

				while(tmp_q.empty() == false)	tmp_q.pop();//tmp_q清空
				group_cnt = 0;//计数器置0
			}
		}
		//不满一组的也要计算
		int max;
		if(tmp_q.empty() == false)
			max = FindMax(tmp_q);//找到该组的最大编号 注意这里如果队列为空调用函数会导致段错误
		while(tmp_q.empty() == false)
		{
			int t = tmp_q.front();
			tmp_q.pop();
			if(t != max)//淘汰的老鼠直接计算排名
				node[t].r = rank;
			else
				next_q.push(t);//晋级的老鼠
		} 
		np = rank - 1; //下一组的总人数
		q = next_q;
		while(next_q.empty() == false)	next_q.pop();//清空next_q数组
	}
	
	for(int i = 0; i < u - 1; i++)
		printf("%d ", node[i].r);
	printf("%d\n", node[u - 1].r);
	
	return 0;
}