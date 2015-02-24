//PAT_1091.Acute Stroke(30)
//Miibotree
//2015.2.23
//思路:三维的Flood Fill 先用递归做一下看有没有超时
#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
	int x;
	int y;
	int z;
}Node;

queue<node> q;

int maze[65][1290][130];
bool flag[65][1290][130];
int n, m, l, t, sum;
int go[][3] = {-1, 0, 0,
				1, 0, 0,
				0, -1, 0,
				0, 1, 0,
				0, 0, -1,
				0, 0, 1};
//DFS会显示段错误的
/*			
void DFS(int x, int y, int z)
{
	for(int i = 0; i < 6; i++)
	{
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		int nz = z + go[i][2];
		if(nx < 1 || ny < 1 || nz < 1 || nx > l || ny > m || nz > n)
			continue;
		if(maze[nx][ny][nz] == 0)
			continue;
		if(flag[nx][ny][nz] == true)
			continue;
		flag[nx][ny][nz] = true;
		sum++;
		DFS(nx, ny, nz); 
	}
	return;
}
*/
void BFS(int x, int y, int z)
{
	while(q.empty() == false)	q.pop();
	Node.x = x; Node.y = y; Node.z = z;
	q.push(Node);
	flag[x][y][z] = true;
	while(q.empty() == false)
	{
		node top = q.front();
		q.pop();
		sum++;
		for(int i = 0; i < 6; i++)
		{
			int nx = top.x + go[i][0];
			int ny = top.y + go[i][1];
			int nz = top.z + go[i][2];
			if(nx < 1 || ny < 1 || nz < 1 || nx > l || ny > m || nz > n)
				continue;
			if(maze[nx][ny][nz] == 0)
				continue;
			if(flag[nx][ny][nz] == true)
				continue;
			flag[nx][ny][nz] = true;
			Node.x = nx; Node.y = ny; Node.z = nz;
			q.push(Node);
		}
	}
}


int main()
{
	while(scanf("%d%d%d%d", &m, &n, &l, &t) != EOF)
	{
		for(int i = 1; i <= l; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int k = 1; k <= n; k++)
				{
					scanf("%d", &maze[i][j][k]);
					flag[i][j][k] = false;
				}
			}
		}

		int ans = 0;
		for(int i = 1; i <= l; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int k = 1; k <= n; k++)
				{
					if(flag[i][j][k] == true)
						continue;
					if(maze[i][j][k] == 0)//表示正常
						continue;
					sum = 0;
					BFS(i, j, k);
					if(sum >= t)
						ans += sum;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}