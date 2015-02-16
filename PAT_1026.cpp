//PAT_1026. Table Tennis (30)
//Miibotree
//2015.2.15
//银行排队模拟题的进阶
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct player{
	int aTime;
	int sTime;
	int wTime;
	bool vip;
}p[10001];

struct table{
	int eTime;
	bool vip;
	int cnt;
}t[101];

bool cmp(player a, player b){
	if(a.aTime != b.aTime)
		return a.aTime < b.aTime;
}

int main()
{
	int n, m, v;
	while(scanf("%d", &n) != EOF)
	{
		int hh,mm,ss, playtime, tag;
		for(int i = 0; i < n; i++)
		{
			scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playtime, &tag);
			p[i].aTime = hh*60*60+mm*60+ss;
			p[i].wTime = playtime*60;
			p[i].vip = tag;
		}
		scanf("%d%d", &m, &v);
		for(int i = 0; i < v; i++)
		{
			int viptable;
			scanf("%d", &viptable);
			t[viptable].vip = 1;
		}
		sort(p, p+n, cmp);
		int pos = -1;
		for(int i = 0; i < n; i++)
		{
			//判断i是不是vip会员。若是，判断是否有vip桌子
			pos = -1;
			if(p[i].vip == 1)
			{
				for(int j = 0; j < m; j++)
				{
					if(t[j].eTime == p[i].aTime)//说明有空位子
					{
						pos = j;
						break;
					}
				}
				if(pos != -1)//有vip空位
				{
					p[i].sTime = p[i].aTime;
					
				}
			}
		}


	}
	return 0;
}