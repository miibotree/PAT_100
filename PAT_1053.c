//PAT_1053. Path of Equal Weight (30)
//Miibotree
//2015.2.18
//树的DFS 碰到的问题：如何排序？
//1.把结果保存在字符串中，输出字符串
//2.先把孩子节点按照权值排序，然后再用dfs
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T[101];
int w[101];
int j;
int flag[101];//flag = 0 表示非叶节点; flag = 1 表示叶节点
char ans[101][101];

int DFS(int i)
{
	if(T[i] != -1)
		return w[i] + DFS(T[i]);
	else
		return w[i];
}


void GetQueue(int i, int cnt)
{
	if(T[i] != -1)
		GetQueue(T[i], cnt);
	ans[cnt][j++] = w[i];
}

int cmp(const void* tmpa,const void* tmpb){  
    char* a=(char*)tmpa;  
    char* b=(char*)tmpb;  
    return strcmp(b,a);  
}  

int main()
{
	int n, m, weight, cnt;
	
	while(scanf("%d%d%d", &n, &m, &weight) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &w[i]);
			flag[i] = 1;
		}
		T[0] = -1;
		for(int i = 0; i < m; i++)
		{
			int root, num, child;
			scanf("%d%d", &root, &num);
			flag[root] = 0;
			for(int j = 0; j < num; j++)
			{
				scanf("%d", &child);
				T[child] = root;
			}
		}
		cnt = 0;
		for(int i = 0; i < n; i++)
		{
			int sum = 0;
			if(flag[i] == 1)
			{
				sum = DFS(i);//自底向上的遍历
				if(sum == weight)
				{
					j = 0;
					GetQueue(i, cnt);
					ans[cnt][j] = 0;
					cnt++;
				}
			}
		}
		qsort(ans, cnt, sizeof(ans[0]), cmp);  

		for(int i = 0; i < cnt; i++)
		{
			for(int k = 0; k < strlen(ans[i]) - 1; k++)
				printf("%d ", ans[i][k]);
			printf("%d\n", ans[i][strlen(ans[i]) - 1]);
		}
	}
	return 0;
}