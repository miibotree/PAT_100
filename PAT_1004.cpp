//PAT_1004. Counting Leaves (30)
//Miibotree
//2015.2.4
#include <stdio.h>
#include <queue>

using namespace std;

queue<int> q, tmp_q;//tmp_q里存放下一层的结点
int main()
{	
	int n, k;
	int id[101];
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i = 1; i <= k; i++)
		{
			int a, m, b;
			scanf("%d%d", &a, &m);
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &b);
				id[b] = a;//b结点的父结点是a
			}
		}
		id[1] = -1;
		while(q.empty() == false) q.pop();//初始化操作
		while(tmp_q.empty() == false) tmp_q.pop();

		q.push(01);//把父结点入队列
		int isFirst = true;
		while(q.empty() == false)
		{
			int count = 0;
			while(q.empty() == false)//遍历当前层
			{
				int curId = q.front();
				q.pop();
				bool hasChild = false;
				for(int i = 2; i <= n; i++)
				{
					if(id[i] == curId)//说明该结点的父节点是curId
					{
						tmp_q.push(i);
						hasChild = true;
					}
				}
				if(!hasChild)
					count++;
			}
			if (isFirst)
			{
				printf("%d", count);
				isFirst = false;
			}
			else
				printf(" %d", count);
			while(tmp_q.empty() == false)
			{
				int t = tmp_q.front();
				tmp_q.pop();
				q.push(t);
			}
		}
	}

	return 0;
}