//PAT_1091. Acute Stroke (30)
//BFS
#include <stdio.h>
#include <queue>
using namespace std;

int maze[70][1300][130];
int inq[70][1300][130];
int m, n, l, t;
int gx[] = {-1, 1, 0, 0, 0, 0};
int gy[] = {0,  0, 1,-1, 0, 0};
int gz[] = {0,  0, 0, 0, 1,-1};

struct Node{
	int x, y, z;
};

bool judge(Node a)
{
	if(a.x <= 0 || a.y <= 0 || a.z <= 0 || a.x > m || a.y > n || a.z > l)
		return false;
	if(inq[a.x][a.y][a.z] == true || maze[a.x][a.y][a.z] == 0)
		return false;
	return true;
}

int BFS(int z, int x, int y)
{
	int sum = 0;
	queue<Node> q;
	Node tmp;
	tmp.x = x; tmp.y = y; tmp.z = z; 
	q.push(tmp);
	inq[x][y][z] = true;
	sum++;
	while(q.empty() == false)
	{
		Node top = q.front();
		q.pop();
		for(int i = 0; i < 6; i++)
		{
			Node newPos;
			newPos.x = top.x + gx[i];
			newPos.y = top.y + gy[i];
			newPos.z = top.z + gz[i];
			if(judge(newPos))
			{
				q.push(newPos);
				inq[newPos.x][newPos.y][newPos.z] = true;
				sum++;
			}
		}	
	}
	return sum;
}

int main()
{
	freopen("C:\\Users\\miibotree\\Desktop\\in.txt", "r", stdin);
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int i = 1; i <= l; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				scanf("%d", &maze[i][j][k]);
				inq[i][j][k] = false;
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
				if(maze[i][j][k] == 0 || inq[i][j][k] == true)
					continue;
				else
				{
					int res = BFS(i, j, k);
					if(res >= t)
						ans +=res;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}