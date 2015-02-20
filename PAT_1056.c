//PAT_1056 Mice and Rice(25)
//Miibotree
//2015.2.20
//模拟题(想清楚思路之后，被英文坑到了)
//The third line gives the initial playing order which is a permutation of 0,...NP-1 
//	 (assume that the programmers are numbered from 0 to NP-1). 
// All the numbers in a line are separated by a space.
//这里的initial playing order说的是执行队列的顺序（被小括号里面的置换给搞混了）

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int a[1001], p[1001], r[1001], b[1001];

vector<int> v, tmp_v, next_v;

int Max_order()
{
	int max = a[tmp_v[0]], cur = tmp_v[0];
	for(int i = 1; i < tmp_v.size(); i++)
	{
		if(a[tmp_v[i]] > a[cur])
		{
			max = a[tmp_v[i]];
			cur = tmp_v[i];
		}
	}
	return cur;
}

int main()
{
	int np, ng;
	while(scanf("%d%d", &np, &ng) !=EOF)
	{
		v.clear();	tmp_v.clear();	next_v.clear();
		
		for(int i = 0; i < np; i++)
		{
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < np; i++)
		{
			scanf("%d", &p[i]);
			v.push_back(p[i]);
		}

		int rank;
		int cnt;
		while(v.size() > 0)
		{
			if(v.size() == 1)
			{
				r[v[0]] = 1;
				break;
			}

			next_v.clear();
			tmp_v.clear();

			if(v.size() % ng == 0)
				rank = v.size() / ng + 1;
			else
				rank = v.size() / ng + 2;
			cnt = 0;
			while(cnt < ng && v.size() > 0)
			{
				//把每组成员放到tmp_q中
				int cur = v[0];
				v.erase(v.begin(), v.begin()+1);
				tmp_v.push_back(cur);
				cnt++;

				//tmp_q满了
				if(cnt == ng)
				{
					int max = Max_order();
					next_v.push_back(max);
					for(int i = 0; i < tmp_v.size(); i++)
					{
						if(tmp_v[i] != max)//标记rank
							r[tmp_v[i]] = rank;
					}
					cnt = 0;
					tmp_v.clear();
				}
			}
			if(tmp_v.size() > 0)
			{
				int max = Max_order();
				next_v.push_back(max);
				for(int i = 0; i < tmp_v.size(); i++)
				{
					if(tmp_v[i] != max)//标记rank
						r[tmp_v[i]] = rank;
				}
			}
			v = next_v;
		}
		for(int i = 0; i < np; i++)
		{
			if(i == 0)
				printf("%d", r[i]);
			else
				printf(" %d", r[i]);
		}
		printf("\n");
	}

	return 0;
}